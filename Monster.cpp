#include "Monster.h"
#include "EasyXPng.h"

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

void Monster::drawHeart()
{
	// 血条宽度
	float heartWidth = 50;
	// 血条高度
	float heartHeight = 10;
	// 一排血条的血量
	int heartValuePerRow = 10;
	// 绘制血条外框
	setlinecolor(BLACK);
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
    putimagePng(this->x - this->width/2, this->y - this->height/2, &ims_monster[aniId]);
    this->aniCount++;
    if (aniCount > ANI_MAX_COUNT) {
        aniCount = 0;
        aniId++;
        aniId %= ims_monster.size();
    }
	drawHeart();
}

void Monster::move()
{
	this->x += this->vx;
	this->y += this->vy;
    // 检查是否到达目标中心
	// 目标坐标
	float targetX = currentCoordinate.col * BLOCK_WIDTH + BLOCK_WIDTH / 2;
    float targetY = currentCoordinate.row * BLOCK_HEIGHT + BLOCK_HEIGHT / 2;
	if ((this->x > targetX - BLOCK_WIDTH*this->speed/200 && this->x < targetX + BLOCK_WIDTH*this->speed/200)
		&& (this->y > targetY - BLOCK_HEIGHT*this->speed/200 && this->y < targetY + BLOCK_HEIGHT * this->speed/200)) {
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
			this->ims_monster = getImagesByTypeAndDirection(type, 'w');
			return Coordinate(row - 1, col);
		}
	}
	// 下
	if (row + 1 < ROW) {
		if (roadMap[row + 1][col] == 1 && row + 1 != lastCoordinate.row) {
			this->vx = 0;
			this->vy = BLOCK_HEIGHT * this->speed / 200;
			this->ims_monster = getImagesByTypeAndDirection(type, 's');
			return Coordinate(row + 1, col);
		}
	}
	// 左
	if (col - 1 > 0) {
		if (roadMap[row][col - 1] == 1 && col - 1 != lastCoordinate.col) {
			this->vx = -BLOCK_WIDTH * this->speed / 200;
			this->vy = 0;
			this->ims_monster = getImagesByTypeAndDirection(type, 'a');
			return Coordinate(row, col - 1);
		}
	}
	// 右
	if (col + 1 < COL) {
		if (roadMap[row][col + 1] == 1 && col + 1 != lastCoordinate.col) {
			this->vx = BLOCK_WIDTH * this->speed / 200;
			this->vy = 0;
			this->ims_monster = getImagesByTypeAndDirection(type, 'd');
			return Coordinate(row, col + 1);
		}
	}
	return Coordinate(-1, -1);
}

void Monster::subHeart(int value)
{
	this->heart -= value;
}
