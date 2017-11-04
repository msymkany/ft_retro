//
// Created by Illia Lukianov on 11/4/17.
//
#ifndef USERSHIP_HPP
#define USERSHIP_HPP
#include "game.hpp"

#include "FlyingEssence.hpp"
//#include "Bullet.hpp"
class UserShip : public FlyingEssence {
public:
	UserShip();
	UserShip(const UserShip &);
	UserShip& operator=(const UserShip &);
	virtual ~UserShip();
	player *getModulPosition() const;
	void setXModulPosition(int x);
	void setYModulPosition(int y);
	void putModul(WINDOW *field);
	bool hook(int in_char);
	void putSpace(WINDOW *field);
//	void    shot();
//	Bullet *getMissile() const;
	void operator==(cordScreen cord);
private:
//	Bullet *missile;
	int     _cout_missile;
//    bool operator!=(const UserShip &rhs) const;
};
#endif //RUSH00_USERSHIP_H