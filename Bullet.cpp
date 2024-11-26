#include "Bullet.h"
#include "EasyXPng.h"
Bullet::Bullet(float x, float y, Monster* target)
{
	id = ++bulletId;

	targetMonster = target;
	this->x = x;
	this->y = y;
	this->width = 14;
	this->height = 3;
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
	}
	catch (const std::exception&)
	{

	}
}

void Bullet::update()
{
	draw();
	move();
}

void Bullet::draw()
{
	putimagePng(x, y, &im_arrow);
}
