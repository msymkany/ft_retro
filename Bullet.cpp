//
// Created by Illia Lukianov on 11/4/17.
//

#include "Bullet.hpp"

Bullet::Bullet() : FlyingEssence::FlyingEssence(1) {
    modulPosition[0].pos.disp_char = '*';
    modulPosition[0].pos.x = -10;
    modulPosition[0].pos.y = -10;
}

Bullet::Bullet(const Bullet & b) {
    *this = b;
}

Bullet &Bullet::operator=(const Bullet & b) {
    _stoper = b._stoper;
    return *this;
}

Bullet::~Bullet() {

}

void Bullet::fly(Bullet *missile, cordScreen _playScreen) {
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < 200) {
        if (missile[i].getModulPosition()->pos.x > _playScreen.x - 3)
            missile[i]._stoper = 0;
        if (missile[i]._stoper != 0) {
            missile[i].modulPosition[0].pos.x++;
            mvaddch(missile[i].getModulPosition()->pos.y, missile[i].getModulPosition()->pos.x, missile[i].getModulPosition()->pos.disp_char);
        }
        i++;
    }
}

void Bullet::cleanFly(Bullet *missile) {
    int i;

    i = 0;
    while (i < 200) {
        if (missile[i]._stoper != 0) {
            mvaddch(missile[i].getModulPosition()->pos.y, missile[i].getModulPosition()->pos.x, ' ');
        }
        i++;
    }
}

int Bullet::get_stoper() const {
    return _stoper;
}

void Bullet::set_stoper(int _stoper) {
    Bullet::_stoper = _stoper;
}



