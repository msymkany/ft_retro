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

#include "Field.hpp"

//initialization

Field::Field() : _score(0), _lives(3), _maxlives(3), _cycles(0)
{
	initscr();
	cbreak();
	start_color();
	keypad(stdscr, TRUE);
	noecho();
	curs_set(0);
	nodelay(stdscr, TRUE);
	scrollok(stdscr, TRUE);

	init_pair(1, COLOR_BLUE, COLOR_BLACK);
	init_pair(2, COLOR_CYAN, COLOR_BLACK);

	getmaxyx(stdscr, _playScreen.y, _playScreen.x);
	_playScreen.y -= 5;
	_infoScreen.y = 5;
	_infoScreen.x = _playScreen.x;
	_field = newwin(_playScreen.y, _playScreen.x, 5, 0);
	_info = newwin(_infoScreen.y, _infoScreen.x, 0, 0);
	refresh();
//	mvwprintw(_field, 34, 67, "+");
	box(_field, 0, 0);
	box(_info, 0, 0);
	wbkgd(_field, COLOR_PAIR(1));
	wbkgd(_info, COLOR_PAIR(2));
	wrefresh(_field);
	wrefresh(_info);
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
