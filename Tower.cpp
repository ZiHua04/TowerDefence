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

	this->currentGrade = 1;
	loadTowerInfo();
}



void Tower::draw() {
	if (this == nullptr) return;
	
	putimagePng(x-width/2, y-height/2, &ims_tower[aniId]);
	aniCount++;
	if (aniCount > ANI_MAX_COUNT) {
		aniCount = 0;
		aniId++;
		aniId %= ims_tower.size();
	}

	drawHeart();

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

	//draw();
	if (this == nullptr) return;
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
			// 播放音效
			audioSystem->playAudio(AudioType::Shoot);
			bullets.push_back(new Bullet(x, y, monsters[i]));
			return;
		}
	}
}

void Tower::addCoin()
{
	coinSystem->addCoin(this->coinPerSecond, this->x, this->y);
}

void Tower::upgrade()
{
	if (this == nullptr) return;
	// 检查是否满级
	if (currentGrade >= 3) return;
	// 检查是否有足够金币
	if (!coinSystem->subCoin(upgradeCost)) return;
	currentGrade++;
	loadTowerInfo();
	this->ims_tower = getTowerImages(type, currentGrade);
	
}

void Tower::loadTowerInfo()
{
	this->heart = towerInfo[currentGrade].heart;
	this->speed = towerInfo[currentGrade].speed;
	this->upgradeCost = towerInfo[currentGrade].upgradeCost;
	this->attckRange = towerInfo[currentGrade].attackRange;
	this->coinPerSecond = towerInfo[currentGrade].coinPerSecond;
}

void Tower::subHeart(int value) {
	if (this->heart - value > 0) {
		this->heart -= value;
		return;
	}
	destoryTowerById(this->id);


}

void Tower::drawHeart()
{
	float im_width = ims_heart[0].getwidth();
	float im_height = ims_heart[0].getheight();
	putimagePng(x-width/2 + 15, y+height/2-10, &ims_heart[aniId*2]);
	settextcolor(RED);
	drawText(std::to_string(heart), x + width / 2 - 20, y + height / 2 - 10, 15);
}
