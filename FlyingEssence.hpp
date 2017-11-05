//
// Created by Illia Lukianov on 11/4/17.
//

#ifndef FLYINGESSENCE_HPP_
#define FLYINGESSENCE_HPP_
#include "game.hpp"

class FlyingEssence {

public:
    FlyingEssence(player *modulPosition, int modulSize);
    FlyingEssence();
    FlyingEssence(int part);
    FlyingEssence(const FlyingEssence &);
    FlyingEssence& operator=(const FlyingEssence &);
    virtual ~FlyingEssence();
    virtual player *getModulPosition() const;
    void putModul(WINDOW *field, int size);
    void putSpace(WINDOW *field, int size);
    int getModulSize() const;

    void setModulSize(int modulSize);

protected:
	player *modulPosition;
    int modulSize;

};
#endif
