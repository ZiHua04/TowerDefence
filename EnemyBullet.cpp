#include "EnemyBullet.h"
#include "EasyXPng.h"
EnemyBullet::EnemyBullet(float x, float y, Tower* tower)
{
	id = ++enemyBulletId;

	targetTower = tower;
	this->x = x;
	this->y = y;
	this->width = im_arrow.getwidth();
	this->height = im_arrow.getheight();
}

void EnemyBullet::move()
{
	x += vx;
	y += vy;
	if (targetTower == nullptr) return;
	try
	{
		float dis_x = targetTower->x - x;
		float dis_y = targetTower->y - y;
		float lenght = sqrt(pow(dis_x, 2) + pow(dis_y, 2));
		vx = 5 * dis_x / lenght;
		vy = 5 * dis_y / lenght;
		float angle = atan(vy / vx);
		rotateimage(&im_bullet, &im_arrow, -angle, 0UL, true);
	}
	catch (const std::exception&)
	{

	}
}

void EnemyBullet::update()
{
	draw();
	move();
}

void EnemyBullet::draw()
{
	putimagePng(x, y, &im_bullet);
}
