//
// Created by Illia Lukianov on 11/4/17.
//
#include "FlyingEssence.hpp"

FlyingEssence::FlyingEssence() {
    modulPosition = nullptr;
    modulSize = 0;
}

FlyingEssence::FlyingEssence(player *modulPosition, int modulSize) : modulPosition(modulPosition),
                                                                     modulSize(modulSize)
{

}

FlyingEssence::FlyingEssence(int part) : modulPosition(new player[part]), modulSize(part) {

}

FlyingEssence::~FlyingEssence() {
    modulPosition = nullptr;
    modulSize = 0;
}

FlyingEssence::FlyingEssence(const FlyingEssence & f) {
    *this = f;
}

FlyingEssence &FlyingEssence::operator=(const FlyingEssence & f) {
    modulSize = f.modulSize;
    modulPosition->pos.disp_char = f.modulPosition->pos.disp_char;
    modulPosition->pos.x = f.modulPosition->pos.x;
    modulPosition->pos.y = f.modulPosition->pos.y;
    return *this;
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






