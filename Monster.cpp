#include "Monster.h"
#include "EasyXPng.h"
#include "Global.h"
#include "EnemyBullet.h"
#include "Toolkit.h"
#include <thread>
#include "Constant.h"
Monster::Monster(MonsterType type, Coordinate coordinate) {
    // 初始化id
    this->id = ++MonsterId;
    // 初始化长宽
    MonsterInfo info = monsterInfo[type];
    this->width = info.im_width;
    this->height = info.im_height;
    // 初始化坐标
    this->currentCoordinate = coordinate;
    this->x = coordinate.col * BLOCK_WIDTH + BLOCK_WIDTH / 2;
    this->y = coordinate.row * BLOCK_HEIGHT + BLOCK_HEIGHT / 2;
    // 初始化信息
    this->heart = info.heart;
    this->speed = info.speed;
    this->dropCoins = info.coin;
    // 初始化图片
    this->ims_monster = getImagesByTypeAndDirection(type, 'w');
	// 初始化类型
	this->type = type;
}

Monster::~Monster()
{
	
}

void Monster::drawHeart()
{
	if (type == MonsterType::Boss) {
		rectangle(BLOCK_WIDTH * 3, 100, WIDHT - BLOCK_WIDTH * 3, 120);
		float totalWidth = WIDHT - BLOCK_WIDTH * 6;
		float currentWidth = totalWidth * this->heart / monsterInfo[type].heart;
		setfillcolor(RED);
		fillrectangle(BLOCK_WIDTH * 3, 100, BLOCK_WIDTH * 3 + currentWidth, 120);
		settextcolor(BLACK);
		drawText("哥布林头目", BLOCK_WIDTH * 6 + 24 * 2.5, 120, 24);
		return;
	}

	// 血条宽度
	float heartWidth = 50;
	// 血条高度
	float heartHeight = 10;
	// 一排血条的血量
	int heartValuePerRow = 10;
	// 绘制血条外框
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID, 1);
	for (int i = 0; i < this->heart; i += heartValuePerRow) {
		rectangle(this->x - heartWidth / 2, this->y - this->height / 2 - heartHeight - i*1.2, this->x + heartWidth / 2, this->y - this->height / 2 - i * 1.2);
	}
	int leftValue = this->heart;
	// 绘制内部
	setfillcolor(RED);
	for (int i = 0; i < this->heart; i += heartValuePerRow) {
		if (leftValue >= heartValuePerRow) {
			fillrectangle(this->x - heartWidth / 2, this->y - this->height / 2 - heartHeight - i * 1.2, this->x + heartWidth / 2, this->y - this->height / 2 - i * 1.2);
			leftValue -= heartValuePerRow;
		}
		else {
			fillrectangle(this->x - heartWidth / 2, this->y - this->height / 2 - heartHeight - i * 1.2, this->x - heartWidth / 2 + heartWidth * (leftValue*1.0/ heartValuePerRow), this->y - this->height / 2 - i * 1.2);
		}
	}

}

void Monster::draw()
{
	this->aniCount++;
	if (aniCount > ANI_MAX_COUNT * 1.0 / this->speed) {
		aniCount = 0;
		aniId++;
		aniId %= ims_monster.size();
	}
	aniId %= ims_monster.size();
    putimagePng(this->x - this->width/2, this->y - this->height/2, &ims_monster[aniId]);
    
	drawHeart();
	if (type == MonsterType::Bee) {
		setlinecolor(RED);
		setlinestyle(PS_DASHDOT);
		circle(this->x, this->y, 150);
	}
	if (this->isIced) {
		putimagePng(x - ims_vfx_beIced[15].getwidth()/2, y- ims_vfx_beIced[15].getheight()/2, &ims_vfx_beIced[15]);
	}
}

void Monster::move()
{
	this->x += this->vx;
	this->y += this->vy;
    // 检查是否到达目标中心
	// 目标坐标
	float targetX = currentCoordinate.col * BLOCK_WIDTH + BLOCK_WIDTH / 2;
    float targetY = currentCoordinate.row * BLOCK_HEIGHT + BLOCK_HEIGHT / 2;
	/*if ((this->x > targetX - BLOCK_WIDTH*this->speed/200 && this->x < targetX + BLOCK_WIDTH*this->speed/200)
		&& (this->y > targetY - BLOCK_HEIGHT*this->speed/200 && this->y < targetY + BLOCK_HEIGHT * this->speed/200)) */
	if ((this->x > targetX - 10 && this->x < targetX + 10)
		&& (this->y > targetY - 10 && this->y < targetY + 10))
	{
		// 到达方块中心
		Coordinate temp = currentCoordinate;
		currentCoordinate = findNext();
		lastCoordinate = temp;
		if (currentCoordinate.row == -1 && currentCoordinate.col == -1){
			// 到达终点
			isArrived = true;
			return;
		}
	}
	
}

void Monster::update()
{
    draw();// 绘制
    move();// 移动
	timeCount += 5;
	if (timeCount >= 1000) {
		timeCount = 0;
		if (type == MonsterType::Bee) {
			shoot();
		}
		
	}

	if (this->isArrived) {

		destoryMonsterById(this->id);
		return;
	}
	if (this->heart <= 0) {
		coinSystem->addCoin(this->dropCoins, this->x, this->y);
		if (type == MonsterType::Boss) {
			destoryMonsterById(this->id);
			currentGameState = GameState::WIN;
			return;
		}
		destoryMonsterById(this->id);
	}
	
}

Coordinate Monster::findNext()
{
	int row = currentCoordinate.row;
	int col = currentCoordinate.col;
	// 上
	if (row - 1 >= 0) {
		if (roadMap[row - 1][col] == 1 && row - 1 != lastCoordinate.row) {
			this->vx = 0;
			this->vy = -BLOCK_HEIGHT * this->speed / 200;
			if(type != MonsterType::Boss)
				this->ims_monster = getImagesByTypeAndDirection(type, 'w');
			return Coordinate(row - 1, col);
		}
	}
	// 下
	if (row + 1 < ROW) {
		if (roadMap[row + 1][col] == 1 && row + 1 != lastCoordinate.row) {
			this->vx = 0;
			this->vy = BLOCK_HEIGHT * this->speed / 200;
			if (type != MonsterType::Boss)
				this->ims_monster = getImagesByTypeAndDirection(type, 's');
			return Coordinate(row + 1, col);
		}
	}
	// 左
	if (col - 1 > 0) {
		if (roadMap[row][col - 1] == 1 && col - 1 != lastCoordinate.col) {
			this->vx = -BLOCK_WIDTH * this->speed / 200;
			this->vy = 0;
			if (type != MonsterType::Boss)
				this->ims_monster = getImagesByTypeAndDirection(type, 'a');
			else
				this->ims_monster = getImagesByTypeAndDirection(type, 'a', (heart < monsterInfo[type].heart/2));
				
			return Coordinate(row, col - 1);
		}
	}
	// 右
	if (col + 1 < COL) {
		if (roadMap[row][col + 1] == 1 && col + 1 != lastCoordinate.col) {
			this->vx = BLOCK_WIDTH * this->speed / 200;
			this->vy = 0;
			if (type != MonsterType::Boss)
				this->ims_monster = getImagesByTypeAndDirection(type, 'd');
			else
				this->ims_monster = getImagesByTypeAndDirection(type, 'd', (heart < monsterInfo[type].heart / 2));
			return Coordinate(row, col + 1);
		}
	}
	return Coordinate(-1, -1);
}

void Monster::subHeart(int value)
{
	vfxSystem->addText("-"+std::to_string(value), this->x, this->y, 0.2, RED, 20);
	vfxSystem->PlayVFX(x, y, VFXType::Hit);// 播放特效
	this->heart -= value;
}

void Monster::shoot()
{
	float cx = this->x + this->width / 2;
	float cy = this->y + this->height / 2;
	std::map<Coordinate, Tower*>::iterator iter;
	for (iter = towers.begin(); iter != towers.end(); iter++) {
		//cout << iter->first << " : " << iter->second << endl;
		float xmin = iter->second->x;
		float ymin = iter->second->y;
		float xmax = xmin + iter->second->width;
		float ymax = ymin + iter->second->height;
		if (isCircleRectangleIntersect(cx, cy, 150, xmin, ymin, xmax, ymax)) {
			enemyBullets.push_back(new EnemyBullet(x, y, iter->second));
			return;
		}
	}
	
}

void Monster::beIced()
{
	this->isIced = true;
	this->speed /= 2;
	this->vx /= 2;
	this->vy /= 2;
	// 显示特效
	vfxSystem->PlayVFX(x, y, VFXType::BeIced);
	std::thread([this]() {
		std::this_thread::sleep_for(std::chrono::seconds(10));
		if (this == nullptr) return;
		this->recover();
		}).detach();
}

void Monster::recover()
{	
	this->isIced = false;
	this->speed = monsterInfo[type].speed;
}
