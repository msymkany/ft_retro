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

Field::Field() : _score(0), _lives(3), _maxlives(3), _cycles(0)
{
	User = new UserShip;
	init_graph();
	apd_screen();
	return;
}

Field::~Field()
{
	delwin(_field);
	delwin(_info);
	endwin();
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
	mvprintw(3, 15, "Lives %d", _lives); //test
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
	nodelay(stdscr, TRUE);
	halfdelay(1);
	scrollok(stdscr, TRUE);

	init_pair(1, COLOR_BLUE, COLOR_BLACK);
	init_pair(2, COLOR_CYAN, COLOR_BLACK);
	init_pair(3, COLOR_WHITE, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);

	getmaxyx(stdscr, _playScreen.y, _playScreen.x);
	_playScreen.y -= 5;
	_infoScreen.y = 5;
	_infoScreen.x = _playScreen.x;
	_field = newwin(_playScreen.y, _playScreen.x, 5, 0);
	_info = newwin(_infoScreen.y, _infoScreen.x, 0, 0);
	box(_field, 0, 0);
	box(_info, 0, 0);
	wbkgd(_field, COLOR_PAIR(1));
	wbkgd(_info, COLOR_PAIR(2));
	keypad(_field, TRUE);
	refresh();
	wrefresh(_field);
	wrefresh(_info);
}

void Field::apd_screen()
{
	mvwprintw(_info, 2, 20, "Score: %d", _score);
	mvwprintw(_info, 2, 45, "Lives: ");
	for (int i = 0; i < _lives; i++)
		waddstr(_info, " @ ");
	wrefresh(_info);
	wrefresh(_field);
	refresh();
}

void Field::play_game() {

	int in_char;
	bool exit_requested = false;
	while (1) {
		apd_screen();
		in_char = wgetch(_field);
//		mvprintw(0, 0, "%d", in_char); //test
		User->putSpace(_field, User->getModulSize());
		if (!User->hook(in_char))
			exit_requested = true;
		*User==_playScreen;
		User->getMissile()->cleanFly(User->getMissile());
        wattron(_field, COLOR_PAIR(4));
		User->getMissile()->fly(User->getMissile(), this->_playScreen);
        wattroff(_field, COLOR_PAIR(4));
        this->putRandomEnemy();
        this->enemy->cleanFly(this->enemy, this->random);
        this->enemy->fly(this->enemy);
		wattron(_field, COLOR_PAIR(3));
		User->putModul(_field, User->getModulSize());
		wattroff(_field, COLOR_PAIR(3));
		checkLives();
		if (exit_requested) break;
		if (!_lives) break;
		usleep(10000); // 10 ms
		refresh();
	}
	delete User;
	if (!_lives)
		game_over();
}

void Field::putRandomEnemy() {
    int i;
    int r;

    i = 0;
    while (i < 2) {
        r = rand() % 99;
        this->enemy[r].set_stoper(1);
        if (this->random[r] != 1)
		{
			this->enemy[r].getModulPosition()->pos.y = rand() % 25 + 8;
			this->random[r] = 1;
		}
        i++;
    }
}

void Field::checkLives() {

	for (int i = 0; i < 100; i++)
	{
		if (random[i])
		{
			if (*User == enemy[i])
			{
				take_live();
				if (!_lives)
					return ;
			}
		}
	}
}

void Field::game_over() {

	int in_char;
	wclear(_field);
	wclear(_info);
	clear();
	wrefresh(_info);
	wrefresh(_field);
	box(stdscr, 0, 0);
//	bkgd(COLOR_PAIR(1));
	mvwprintw(_stdwin, 14, 20, "Game over");
	refresh();
	usleep(1000000); // 10 ms
	in_char = wgetch(_stdwin);
	halfdelay(30);
	if (in_char == 'q')
		return;
//	delwin(_field);
//	delwin(_info);
}


