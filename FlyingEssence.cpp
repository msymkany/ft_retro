//
// Created by Illia Lukianov on 11/4/17.
//
#include "FlyingEssence.hpp"
#include "game.hpp"


FlyingEssence::FlyingEssence(int part) : modulPosition(new player[part]) {

}

FlyingEssence::~FlyingEssence() {
}

player *FlyingEssence::getModulPosition() const {
	return modulPosition;
}
