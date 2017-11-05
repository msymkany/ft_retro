//
// Created by Illia Lukianov on 11/4/17.
//
#include "FlyingEssence.hpp"
#include "game.hpp"


FlyingEssence::FlyingEssence(int part) : modulPosition(new player[part]), modulSize(part) {

}

FlyingEssence::~FlyingEssence() {
}

player *FlyingEssence::getModulPosition() const {
	return modulPosition;
}

void    FlyingEssence::putModul(WINDOW *field, int size) {
    int i;
    i = 0;
    while (i < size) {
        mvwaddch(field, modulPosition[i].pos.y, modulPosition[i].pos.x, modulPosition[i].pos.disp_char);
        i++;
    }
}
void     FlyingEssence::putSpace(WINDOW *field, int size) {
    int i;
    i = 0;
    while (i < size) {
        mvwaddch(field, modulPosition[i].pos.y, modulPosition[i].pos.x, ' ');
        i++;
    }
}

int FlyingEssence::getModulSize() const {
    return modulSize;
}

void FlyingEssence::setModulSize(int modulSize) {
    FlyingEssence::modulSize = modulSize;
}
