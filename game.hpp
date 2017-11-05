//
// Created by Illia Lukianov on 04.11.2017.
//
#ifndef GAME_HPP_
#define GAME_HPP_
#include <unistd.h>
#include <ncurses.h>
#include <cstdint>
#include <string>
#include <iostream>
#define ENEMY 200
//#include "Field.hpp"
//#include "UserShip.hpp"
//#include "FlyingEssence.hpp"

typedef struct {
	int x;
	int y;
	char disp_char;
} vec2ui;

typedef struct {
    int x;
    int y;
//    WINDOW *wnd;
} cordScreen;

typedef struct {
	int x;
	int y;
	char disp_char;
} vec2i;

typedef struct {
	vec2i pos;
} player;

//typedef struct {
//    vec2i pos_1;
//
//} enemy;
//int init();
//void run();
//void close();
#endif
