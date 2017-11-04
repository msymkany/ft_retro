//
// Created by Illia Lukianov on 11/4/17.
//
#ifndef FLYINGESSENCE_HPP_
#define FLYINGESSENCE_HPP_
#include "game.hpp"

class FlyingEssence {
public:
	FlyingEssence();
	FlyingEssence(int part);
	FlyingEssence(const FlyingEssence &);
	FlyingEssence& operator=(const FlyingEssence &);
	virtual ~FlyingEssence();
	virtual player *getModulPosition() const;
protected:
	player *modulPosition;
};
#endif //RUSH00_FLYINGESSENCE_H
