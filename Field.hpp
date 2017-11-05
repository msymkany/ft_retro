// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Field.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/11/04 14:18:54 by msymkany          #+#    #+#             //
//   Updated: 2017/11/04 14:18:57 by msymkany         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef FIELD_HPP_
# define FIELD_HPP_

#include <iostream>
#include <ncurses.h>
#include <vector>
#include <string>
#include "game.hpp"
#include "UserShip.hpp"
#include "EnemyShip.h"


class Field
{
public:
	Field();

	~Field();

	Field(const Field & some);

	Field &	operator=(const Field & some);


	int get_score() const;
	int get_lives() const;
	int get_maxlives() const;
	int get_cycles() const;

	void 	play_game();
	void	apd_screen();
	void 	init_graph();
	void 	take_live();
	void	operator+=(int pt);
	void	putRandomEnemy();



private:
	UserShip	*User;
    EnemyShip enemy[100];
	int 	random[100];
	int		_score;
	int		_lives;
	int		_maxlives;
	int		_cycles;
	cordScreen	_infoScreen;
	cordScreen	_playScreen;
	WINDOW  *_field;
	WINDOW	*_info;
};

//Field game;


#endif

