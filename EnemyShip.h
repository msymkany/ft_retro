//
// Created by Illia Lukianov on 11/5/17.
//

#ifndef RUSH00_ENEMYSHIP_H
#define RUSH00_ENEMYSHIP_H


#include "FlyingEssence.hpp"

class EnemyShip : public FlyingEssence {
public:
    EnemyShip();
    EnemyShip(const EnemyShip &);
    EnemyShip& operator=(const EnemyShip &);
    virtual ~EnemyShip();

    int get_stoper() const;

    void set_stoper(int _stoper);
    void fly(EnemyShip *enemyy);
    void cleanFly(EnemyShip *enemyy, int *random);

private:
    int _stoper;
};


#endif //RUSH00_ENEMYSHIP_H
