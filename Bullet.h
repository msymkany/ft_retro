//
// Created by Illia Lukianov on 11/4/17.
//

#ifndef RUSH00_BULLET_H
#define RUSH00_BULLET_H

#include "FlyingEssence.hpp"
//#include "Field.hpp"

class Bullet : public FlyingEssence {
public:
    Bullet();
    Bullet(const Bullet &);
    Bullet& operator=(const Bullet &);

    virtual ~Bullet();
    void fly(Bullet *missile, cordScreen _playScreen);
    void cleanFly(Bullet *missile, cordScreen _playScreen);
private:
    int		_stoper;
public:
    void set_stoper(int _stoper);

public:
    int get_stoper() const;
};


#endif //RUSH00_BULLET_H
