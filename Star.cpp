//
// Created by Illia Lukianov on 11/5/17.
//

#include "Star.h"
#include "game.hpp"

Star::Star() : FlyingEssence::FlyingEssence(1), _stoper(0) {
    modulPosition[0].pos.x = -10;
    modulPosition[0].pos.y = -10;
    modulPosition[0].pos.disp_char = '-';
}
Star::~Star() {

}

int Star::get_stoper() const {
    return _stoper;
}

void Star::set_stoper(int _stoper) {
    Star::_stoper = _stoper;
}

void Star::fly(Star *star, cordScreen _playScreen) {
    int i;

    i = 0;
    while (i < 100) {
        if (star[i].getModulPosition()->pos.x < 2) {
            star[i]._stoper = 0;
            star[i].modulPosition[0].pos.x = _playScreen.x - 2;
        }
        if (star[i]._stoper != 0) {
            star[i].modulPosition[0].pos.x--;
            mvaddch(star[i].getModulPosition()->pos.y, star[i].getModulPosition()->pos.x, star[i].getModulPosition()->pos.disp_char);
        }
        i++;
    }
}

void Star::cleanFly(Star *star, int *random) {
    int i;

    i = 0;
    while (i < 100) {
        if (star[i]._stoper != 0 && random[i] == 1) {
            mvaddch(star[i].getModulPosition()->pos.y, star[i].getModulPosition()->pos.x, ' ');
        }
        i++;
    }
}