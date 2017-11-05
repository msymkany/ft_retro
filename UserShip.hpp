//
// Created by Illia Lukianov on 11/4/17.
//
#ifndef USERSHIP_HPP
#define USERSHIP_HPP
#include "game.hpp"
#include "Bullet.hpp"
#include "EnemyShip.hpp"

class UserShip : public FlyingEssence {
public:
	UserShip();
	UserShip(const UserShip & u);
	UserShip& operator=(const UserShip & u);
	virtual ~UserShip();
	player *getModulPosition() const;
	void setXModulPosition(int x);
	void setYModulPosition(int y);
	bool hook(int in_char);
	void    shot();

	Bullet *getMissile();
    void newGamePos();
	int get_cout_missile() const;

	void operator==(cordScreen cord);
	bool operator==(EnemyShip & e) const;

private:
	Bullet missile[200];
	int     _cout_missile;
};
#endif
