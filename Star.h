//
// Created by Illia Lukianov on 11/5/17.
//

#ifndef RUSH00_STAR_H
#define RUSH00_STAR_H


#include "FlyingEssence.hpp"

class Star : public FlyingEssence {
public:
    Star();
    Star(const Star &);
    Star& operator=(const Star &);
    virtual ~Star();

    int get_stoper() const;

    void set_stoper(int _stoper);
    void fly(Star *enemyy);
    void cleanFly(Star *enemyy, int *random);

private:
    int _stoper;
};


#endif //RUSH00_STAR_H
