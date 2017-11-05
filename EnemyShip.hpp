//
// Created by Illia Lukianov on 11/5/17.
//

#ifndef ENEMYSHIP_HPP
#define ENEMYSHIP_HPP

#include "FlyingEssence.hpp"

class EnemyShip : public FlyingEssence {
public:
    EnemyShip();
    EnemyShip(const EnemyShip & es);
    EnemyShip& operator=(const EnemyShip & es);
    virtual ~EnemyShip();

    int get_stoper() const;
    void set_stoper(int _stoper);
    void fly(EnemyShip *enemyy, cordScreen _playScreen);
    void cleanFly(EnemyShip *enemyy, int *random);

private:
    int _stoper;
};


#endif
