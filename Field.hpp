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
#include "Star.h"


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
	void	init_win();
	void 	take_live();
	void	operator+=(int pt);
	void	putRandomEnemy();
	void 	checkLives();
	void	game_over();
    void	putRandomStar();
    void    destroyObj(Bullet *missile);
	void	new_game();


	int get_script() const;

    void set_script(int _script);

    clock_t getT() const;

	void setT(clock_t t);


private:
	UserShip	*User;
    EnemyShip enemy[150];
	int 	random[150];
    Star    star[100];
    int 	random_star[100];
    int     _script;
    int     _scriptMark;
	std::clock_t t;
	int		_score;
	int		_lives;
	int		_maxlives;
	int		_cycles;
	cordScreen	_infoScreen;
	cordScreen	_playScreen;
	WINDOW  *_field;
	WINDOW	*_info;
	WINDOW	*_stdwin;
};

//Field game;


#endif

