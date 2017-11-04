// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/11/04 14:13:20 by msymkany          #+#    #+#             //
//   Updated: 2017/11/04 14:14:55 by msymkany         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <ncurses.h>
#include <vector>
#include <string>
#include "Field.hpp"

int		main()
{
	Field game;
	int ch = 0;

	while (game.get_lives())
	{
		ch = getch();
		if (ch == 'q')
			exit (0);
	}
	return 0;
}
