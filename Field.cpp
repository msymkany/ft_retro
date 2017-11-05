// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Field.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/11/04 14:18:54 by msymkany          #+#    #+#             //
//   Updated: 2017/11/04 14:18:57 by msymkany         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "game.hpp"
#include "Field.hpp"

//initialization

Field::Field() : _script(5), _scriptMark(0), _score(0), _lives(3), _maxlives(3), _cycles(0)
{
	User = new UserShip;
//    this->_script = 5;
	init_graph();
	apd_screen();
	return;
}

Field::~Field()
{
	delwin(_field);
	delwin(_info);
	endwin();
    delete User;
	return;
}

Field::Field(const Field & some)
{
	*this = some;
}

Field &	Field::operator=(const Field & some)
{
    _cycles = some._cycles;
	return *this;
}

//Getters

int Field::get_score() const
{
	return _score;
}

int Field::get_lives() const
{
	return _lives;
}

int Field::get_maxlives() const
{
	return _maxlives;
}

int Field::get_cycles() const
{
	return _cycles;
}

void Field::take_live()
{
	_lives -= 1;
}

void Field::operator+=(int pt)
{
	_score += pt;
}

//start game


//graphics


void Field::init_graph()
{
	_stdwin = initscr();
	cbreak();
	start_color();
	keypad(stdscr, TRUE);
	noecho();
	curs_set(0);
	scrollok(stdscr, TRUE);

    init_pair(1, COLOR_BLUE, COLOR_BLACK);
    init_pair(2, COLOR_CYAN, COLOR_BLACK);
    init_pair(3, COLOR_WHITE, COLOR_BLACK);
    init_pair(4, COLOR_RED, COLOR_BLACK);

//    while ()
    getmaxyx(stdscr, _playScreen.y, _playScreen.x);
//	_playScreen.y -= 5;
    _infoScreen.y = 5;
    _infoScreen.x = _playScreen.x;
    _field = newwin(_playScreen.y, _playScreen.x, 0, 0);
    _info = newwin(_infoScreen.y, _infoScreen.x, 0, 0);
   init_win();
}

void Field::init_win() {
    box(_field, 0, 0);
    box(_info, 0, 0);
    wbkgd(_field, COLOR_PAIR(1));
    wbkgd(_info, COLOR_PAIR(2));
    keypad(_field, TRUE);
    nodelay(stdscr, TRUE);
    halfdelay(1);
    refresh();
    wrefresh(_field);
    wrefresh(_info);
}

void Field::apd_screen()
{
	mvwprintw(_info, 2, 20, "Score: %d", _score);
    mvwprintw(_info, 2, 45, "Lives: ");
    mvwprintw(_info, 2, 52, "                                ");
    for (int i = 0; i < _lives; i++)
        mvwprintw(_info, 2, 52 + i * 3, " @ ");
	wrefresh(_info);
	wrefresh(_field);
	refresh();
}

void Field::play_game() {

	int in_char;
	bool exit_requested = false;
	while (1) {
        t = std::clock() / 3000;
        mvprintw(0, 0, "%d", t);
        if ((t % 5) == 0 && _scriptMark == 1) {
            _scriptMark = 0;
        }
        if ((t % 40) == 0 && get_script() > 0 && _scriptMark == 0) {
            set_script(1);
            _scriptMark = 1;
        } else if ((t % 30) == 0 && get_script() > 0 && _scriptMark == 0) {
            set_script(2);
            _scriptMark = 1;
        } else if ((t % 20) == 0 && get_script() > 0 && _scriptMark == 0) {
            set_script(3);
            _scriptMark = 1;
        } else if ((t % 10) == 0 && get_script() > 0 && _scriptMark == 0) {
            set_script(4);
            _scriptMark = 1;
        }

		apd_screen();
		in_char = wgetch(_field);
//        mvprintw(0, 0, "%d", get_script());
		User->putSpace(_field, User->getModulSize());
		if (!User->hook(in_char))
			exit_requested = true;
		*User==_playScreen;
		User->getMissile()->cleanFly(User->getMissile());
		User->getMissile()->fly(User->getMissile(), this->_playScreen);
        this->putRandomStar();
        this->star->cleanFly(this->star, this->random_star);
        this->star->fly(this->star, this->_playScreen);
        if (t > 8) {
            this->putRandomEnemy();
            this->enemy->cleanFly(this->enemy, this->random);
            this->enemy->fly(this->enemy, _playScreen);
        }
        wattron(_field, COLOR_PAIR(3));
		User->putModul(_field, User->getModulSize());
		wattroff(_field, COLOR_PAIR(3));
        this->destroyObj(User->getMissile());
		checkLives();
		if (exit_requested) break;
		if (!_lives) break;
		usleep(10000); // 10 ms
		refresh();
	}
//	delete User;
	if (!_lives)
		game_over();
}

void Field::putRandomEnemy() {
    int i;
    int r;

    i = 0;
    if (get_script() != 0) {
        if ((this->t % get_script()) == 0) {
            while (i < 2) {
                r = rand() % 149;
                this->enemy[r].set_stoper(1);
                if (this->random[r] != 1) {
                    this->enemy[r].getModulPosition()->pos.x = this->_playScreen.x - 2;
                    this->enemy[r].getModulPosition()->pos.y = rand() % (_playScreen.y - 6) + 6;
                    this->random[r] = 1;
                }
                i++;
            }
        }
    }
}

void Field::checkLives() {

	for (int i = 0; i < 100; i++)
	{
		if (enemy[i].get_stoper())
		{
			if (*User == enemy[i])
			{
				take_live();
				enemy[i].set_stoper(0);
                random[i] = 0;
				if (!_lives)
					return ;
			}
		}
	}
}

void Field::game_over() {

	int in_char = 0;
    nocbreak();
    keypad(_stdwin, true);
	wclear(_field);
	wclear(_info);
	clear();
	wrefresh(_info);
	wrefresh(_field);
	box(stdscr, 0, 0);
//	bkgd(COLOR_PAIR(1));
    mvwprintw(_stdwin, 14, 20, "Game over");
    mvwprintw(_stdwin, 16, 20, "Your score is: %d", _score);
    mvwprintw(_stdwin, 18, 20, "Press 'q' to quit");
    mvwprintw(_stdwin, 20, 20, "Press 'r' to start a new game");
    refresh();
    usleep(1000000); // 10 ms
	while (1)
    {
        in_char = getch();
        if (in_char == 'q')
            return ;
        if (in_char == 'r')
            break ;
    }
    new_game();
}

void Field::putRandomStar() {
    int i;
    int r;

    i = 0;
    while (i < 1) {
        r = rand() % 99;
        this->star[r].set_stoper(1);
        if (this->random_star[r] != 1) {
            this->star[r].getModulPosition()->pos.x = this->_playScreen.x - 2;
            this->star[r].getModulPosition()->pos.y = rand() % (_playScreen.y - 6) + 6;
        }
        this->random_star[r] = 1;
        i++;
    }
}

clock_t Field::getT() const {
    return t;
}


void Field::setT(clock_t t) {
    Field::t = t;
}

int Field::get_script() const {
    return _script;
}

void Field::set_script(int _script) {
    Field::_script = _script;
}

void Field::destroyObj(Bullet *missile) {
    int i;
    int j;

    i = 0;
    while (i < 200) {
        j = 0;
        while (j < 150){
            if (enemy[j].getModulPosition()[0].pos.x == missile[i].getModulPosition()[0].pos.x &&
                    enemy[j].getModulPosition()[0].pos.y == missile[i].getModulPosition()[0].pos.y &&
                    enemy[j].get_stoper() != 0) {
                enemy[j].set_stoper(0);
                this->random[j] = 0;
                enemy[j].getModulPosition()->pos.x = _playScreen.x - 2;
                _score += 50;
            }
            j++;
        }
        i++;
    }
}

void Field::new_game() {
    _score = 0;
    _lives = _maxlives;
    for (int i = 0; i < 150; i++)
    {
        random[i] = 0;
        enemy[i].set_stoper(0);
    }
    mvwprintw(_stdwin, 14, 20, "         ");
    mvwprintw(_stdwin, 16, 20, "                 ");
    mvwprintw(_stdwin, 18, 20, "                 ");
    mvwprintw(_stdwin, 20, 20, "                               ");
    User->newGamePos();
    init_win();
    play_game();
}

