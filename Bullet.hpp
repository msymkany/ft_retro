//
// Created by Illia Lukianov on 11/4/17.
//

#ifndef BULLET_HPP
#define BULLET_HPP

#include "FlyingEssence.hpp"
#include "EnemyShip.hpp"

class Bullet : public FlyingEssence {

public:
    Bullet();
    Bullet(const Bullet & b);
    Bullet& operator=(const Bullet & b);
    virtual ~Bullet();

    void fly(Bullet *missile, cordScreen _playScreen);
    void cleanFly(Bullet *missile);
    void set_stoper(int _stoper);
    int get_stoper() const;

private:
    int		_stoper;

};

#endif
