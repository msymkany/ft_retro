//
// Created by Illia Lukianov on 11/5/17.
//

#include "EnemyShip.hpp"

EnemyShip::EnemyShip() : FlyingEssence::FlyingEssence(1), _stoper(0) {
    modulPosition[0].pos.x = -11;
    modulPosition[0].pos.y = -11;
    modulPosition[0].pos.disp_char = '@';
}

EnemyShip::EnemyShip(const EnemyShip & es) {
    *this = es;
}

EnemyShip &EnemyShip::operator=(const EnemyShip & es) {
    _stoper = es._stoper;
    return *this;
}

EnemyShip::~EnemyShip() {

}

int EnemyShip::get_stoper() const {
    return _stoper;
}

void EnemyShip::set_stoper(int _stoper) {
    EnemyShip::_stoper = _stoper;
}

void EnemyShip::fly(EnemyShip *enemy, cordScreen _playScreen) {
    int i;

    i = 0;
    while (i < 150) {
        if (enemy[i].getModulPosition()->pos.x < 2) {
            enemy[i]._stoper = 0;
            enemy[i].modulPosition[0].pos.x = _playScreen.x - 2;

        }
        if (enemy[i]._stoper != 0) {
            enemy[i].modulPosition[0].pos.x--;
            mvaddch(enemy[i].getModulPosition()->pos.y, enemy[i].getModulPosition()->pos.x,
                    enemy[i].getModulPosition()->pos.disp_char);
        }
        i++;
    }
}

void EnemyShip::cleanFly(EnemyShip *enemy, int *random) {
    int i;

    i = 0;
    while (i < 150) {
        if (enemy[i]._stoper != 0 && random[i] == 1) {
            mvaddch(enemy[i].getModulPosition()->pos.y, enemy[i].getModulPosition()->pos.x, ' ');
        }
        i++;
    }
}

