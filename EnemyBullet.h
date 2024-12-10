#pragma once
#ifndef ENEMYBULLET_H
#define ENEMYBULLET_H

#include "Tower.h"
static int enemyBulletId = 0;
class EnemyBullet
{
private:
	IMAGE im_bullet;
public:
	int id;
	float x, y;
	float width, height;
	Tower* targetTower;
	float vx = 0;
	float vy = 0;
	EnemyBullet(float x, float y, Tower* tower);
	void move();
	void update();
	void draw();
};

#endif // !ENEMYBULLET_H
