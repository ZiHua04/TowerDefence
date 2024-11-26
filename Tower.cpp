#include "Tower.h"
#include "EasyXPng.h"
#include "Global.h"
#include "Toolkit.h"



Tower::Tower(TowerType type, Coordinate coordinate)
{
	this->id = ++TowerId;
	this->type = type;
	this->row = coordinate.row;
	this->col = coordinate.col;
	this->x = col * BLOCK_WIDTH + BLOCK_WIDTH / 2;
	this->y = row * BLOCK_HEIGHT + BLOCK_HEIGHT / 2;
	this->ims_tower = getTowerImages(type, 1);
}

void Tower::draw() {
	putimagePng(x-width/2, y-height/2, &ims_tower[aniId]);
	aniCount++;
	if (aniCount > ANI_MAX_COUNT) {
		aniCount = 0;
		aniId++;
		aniId %= ims_tower.size();
	}

	switch (type)
	{
	case TowerType::Attack:
		setlinecolor(GREEN);
		setlinestyle(PS_DASH, 2);
		circle(x, y, attckRange);
		setlinestyle(PS_SOLID);
		break;
	case TowerType::Coin:
		break;
	default:
		break;
	}
	
}

void Tower::update()
{
	draw();

	this->shootCount += 5;
	if (shootCount >= this->speed * 1000) {
		this->shootCount = 0;
		switch (type) {
            case TowerType::Attack:
                Shoot();
				break;
			case TowerType::Coin:
				addCoin();
                break;
		}
	}
}

void Tower::Shoot()
{
	float cx = this->x + this->width / 2;
	float cy = this->y + this->height / 2;
	for (int i = 0; i < monsters.size(); i++) {

		float xmin = monsters[i]->x;
		float ymin = monsters[i]->y;
		float xmax = xmin + monsters[i]->width;
		float ymax = ymin + monsters[i]->height;
		if (isCircleRectangleIntersect(cx, cy, this->attckRange, xmin, ymin, xmax, ymax)) {
			bullets.push_back(new Bullet(x, y, monsters[i]));
			return;
		}
	}
}

void Tower::addCoin()
{
	coinSystem->addCoin(this->coinPerSecond, this->x, this->y);
}
