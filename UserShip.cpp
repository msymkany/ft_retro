//
// Created by Illia Lukianov on 11/4/17.
//
#include "UserShip.hpp"
#include "game.hpp"

UserShip::UserShip() : FlyingEssence::FlyingEssence(4) {
	attron(COLOR_PAIR(3));
	modulPosition[0].pos.x = 10;
	modulPosition[0].pos.y = 15;
	modulPosition[0].pos.disp_char = '/';
	modulPosition[1].pos.x = 10;
	modulPosition[1].pos.y = 14;
	modulPosition[1].pos.disp_char = '=';
	modulPosition[2].pos.x = 10;
	modulPosition[2].pos.y = 13;
	modulPosition[2].pos.disp_char = '\\';
	modulPosition[3].pos.x = 11;
	modulPosition[3].pos.y = 14;
	modulPosition[3].pos.disp_char = '>';
	attroff(COLOR_PAIR(10));
	mvprintw(10, 10, "%s", "hhkjhjkhkjhjk");
}
UserShip::~UserShip() {
}
void    UserShip::setXModulPosition(int x) {
	int i;
	i = 0;
	while (i < 4) {
		modulPosition[i].pos.x += x;
		i++;
	}
}
void    UserShip::setYModulPosition(int y) {
	int i;
	i = 0;
	while (i < 4) {
		modulPosition[i].pos.y += y;
		i++;
	}
}
void    UserShip::putModul(WINDOW *field) {
	int i;
	i = 0;
	while (i < 4) {
		mvwaddch(field, modulPosition[i].pos.y, modulPosition[i].pos.x, modulPosition[i].pos.disp_char);
		i++;
	}
}
void     UserShip::putSpace(WINDOW *field) {
	int i;
	i = 0;
	while (i < 4) {
		mvwaddch(field, modulPosition[i].pos.y, modulPosition[i].pos.x, ' ');
		i++;
	}
}
bool    UserShip::hook(int in_char) {
	switch(in_char) {
		case 'q':
			return false;
		case KEY_UP:
		case 'w':
			setYModulPosition(-1);
			return true;
		case KEY_DOWN:
		case 's':
			setYModulPosition(1);
			return true;;
		case KEY_LEFT:
		case 'a':
			setXModulPosition(-1);
			return true;;
		case KEY_RIGHT:
		case 'd':
			setXModulPosition(1);
			return true;;
//		case 32:
//			shot();
		default:
			return true;;
	}
}
void UserShip::operator==(cordScreen cord) {
	int i;
	i = 0;
	while (i < 4) {
		if (modulPosition[i].pos.x <= 0) {
			setXModulPosition(1);
			return;
		} else if  (modulPosition[i].pos.x >= (cord.x - 1)) {
			setXModulPosition(-1);
			return;
		} else if (modulPosition[i].pos.y <= 0) {
			setYModulPosition(1);
			return;
		} else if (modulPosition[i].pos.y >= (cord.y - 1)) {
			setYModulPosition(-1);
			return;
		}
		i++;
	}
}
player *UserShip::getModulPosition() const {
	return modulPosition;
}
//void    UserShip::shot() {
//	missile = new Bullet;
//	missile->getModulPosition()->pos.x = getModulPosition()[3].pos.x + 1;
//	missile->getModulPosition()->pos.y = getModulPosition()[3].pos.y;
//}
//Bullet *UserShip::getMissile() const {
//	return missile;
//}
//    modulPosition[0].pos.x = getModulPosition()[3].pos.x + 1;
//    modulPosition[0].pos.y = getModulPosition()[3].pos.y;
//bool UserShip::operator!=(const UserShip &rhs) const {
//    return !(rhs == *this);
//}
