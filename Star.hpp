//
// Created by Illia Lukianov on 11/5/17.
//

#ifndef STAR_HPP_
#define STAR_HPP_

#include "FlyingEssence.hpp"

class Star : public FlyingEssence {
public:
    Star();
    Star(const Star & n);
    Star& operator=(const Star & n);
    virtual ~Star();

    int get_stoper() const;

    void set_stoper(int _stoper);
    void fly(Star *enemyy, cordScreen _playScreen);
    void cleanFly(Star *enemyy, int *random);

private:
    int _stoper;
};


#endif
