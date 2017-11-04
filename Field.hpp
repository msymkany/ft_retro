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

typedef struct
{
	int x;
	int y;
} Cord;

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



private:
	int		_score;
	int		_lives;
	int		_maxlives;
	int		_cycles;
	Cord	_infoScreen;
	Cord	_playScreen;
	WINDOW  *_field;
	WINDOW	*_info;
};

void draw_borders(WINDOW *screen);

#endif

