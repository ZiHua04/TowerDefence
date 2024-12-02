#pragma once
#ifndef BULLET_H
#define BULLET_H

#include "Monster.h"
static int bulletId = 0;
class Bullet
{
private:
	IMAGE im_bullet;
public:
	int id;
	float x, y;
	float width, height;
	Monster* targetMonster;
	float vx = 0;
	float vy = 0;
	Bullet(float x, float y, Monster* target);
	void move();
	void update();
	void draw();
};



#endif // !BULLET_H






