#include "Bullet.h"
#include "EasyXPng.h"
Bullet::Bullet(float x, float y, Monster* target)
{
	id = ++bulletId;

	targetMonster = target;
	this->x = x;
	this->y = y;
	this->width = im_arrow.getwidth();
	this->height = im_arrow.getheight();
}
void Bullet::move(){
	x += vx;
	y += vy;
	if (targetMonster == nullptr) return;
	try
	{
		float dis_x = targetMonster->x - x;
		float dis_y = targetMonster->y - y;
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

void Bullet::update()
{
	if (this == nullptr) return;
	//draw();
	move();
}

void Bullet::draw()
{
	if (this == nullptr) return;
	putimagePng(x, y, &im_bullet);
}
