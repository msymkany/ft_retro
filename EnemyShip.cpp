//
// Created by Illia Lukianov on 11/5/17.
//

#include "EnemyShip.h"
#include "game.hpp"

EnemyShip::EnemyShip() : FlyingEssence::FlyingEssence(1), _stoper(0) {
    modulPosition[0].pos.x = 150;
    modulPosition[0].pos.y = 15;
    modulPosition[0].pos.disp_char = '@';
}
EnemyShip::~EnemyShip() {

}

int EnemyShip::get_stoper() const {
    return _stoper;
}

void EnemyShip::set_stoper(int _stoper) {
    EnemyShip::_stoper = _stoper;
}

void EnemyShip::fly(EnemyShip *enemy) {
    int i;

    i = 0;
    while (i < 50) {
        if (enemy[i].getModulPosition()->pos.x < 3)
            enemy[i]._stoper = 0;
        if (enemy[i]._stoper != 0) {
            enemy[i].modulPosition[0].pos.x--;
            mvaddch(enemy[i].getModulPosition()->pos.y, enemy[i].getModulPosition()->pos.x, enemy[i].getModulPosition()->pos.disp_char);
        }
        i++;
    }
}

void EnemyShip::cleanFly(EnemyShip *enemy) {
    int i;

    i = 0;
    while (i < 50) {
        if (enemy[i]._stoper != 0) {
            mvaddch(enemy[i].getModulPosition()->pos.y - 1, enemy[i].getModulPosition()->pos.x - 1, ' ');
        }
        i++;
    }
}