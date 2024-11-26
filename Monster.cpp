#include "Monster.h"
#include "EasyXPng.h"

Monster::Monster(MonsterType type, Coordinate coordinate) {
    // ��ʼ��id
    this->id = ++MonsterId;
    // ��ʼ������
    MonsterInfo info = monsterInfo[type];
    this->width = info.im_width;
    this->height = info.im_height;
    // ��ʼ������
    this->currentCoordinate = coordinate;
    this->x = coordinate.col * BLOCK_WIDTH + BLOCK_WIDTH / 2;
    this->y = coordinate.row * BLOCK_HEIGHT + BLOCK_HEIGHT / 2;
    // ��ʼ����Ϣ
    this->heart = info.heart;
    this->speed = info.speed;
    this->dropCoins = info.coin;
    // ��ʼ��ͼƬ
    this->ims_monster = getImagesByTypeAndDirection(type, 'w');
	// ��ʼ������
	this->type = type;
}

void Monster::drawHeart()
{
	// Ѫ�����
	float heartWidth = 50;
	// Ѫ���߶�
	float heartHeight = 10;
	// һ��Ѫ����Ѫ��
	int heartValuePerRow = 10;
	// ����Ѫ�����
	setlinecolor(BLACK);
	for (int i = 0; i < this->heart; i += heartValuePerRow) {
		rectangle(this->x - heartWidth / 2, this->y - this->height / 2 - heartHeight - i*1.2, this->x + heartWidth / 2, this->y - this->height / 2 - i * 1.2);
	}
	int leftValue = this->heart;
	// �����ڲ�
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
    // ����Ƿ񵽴�Ŀ������
	// Ŀ������
	float targetX = currentCoordinate.col * BLOCK_WIDTH + BLOCK_WIDTH / 2;
    float targetY = currentCoordinate.row * BLOCK_HEIGHT + BLOCK_HEIGHT / 2;
	if ((this->x > targetX - BLOCK_WIDTH*this->speed/200 && this->x < targetX + BLOCK_WIDTH*this->speed/200)
		&& (this->y > targetY - BLOCK_HEIGHT*this->speed/200 && this->y < targetY + BLOCK_HEIGHT * this->speed/200)) {
		// ���﷽������
		Coordinate temp = currentCoordinate;
		currentCoordinate = findNext();
		lastCoordinate = temp;
		if (currentCoordinate.row == -1 && currentCoordinate.col == -1){
			// �����յ�
			isArrived = true;
			return;
		}
	}
	
}

void Monster::update()
{
    draw();// ����
    move();// �ƶ�
}

Coordinate Monster::findNext()
{
	int row = currentCoordinate.row;
	int col = currentCoordinate.col;
	// ��
	if (row - 1 >= 0) {
		if (roadMap[row - 1][col] == 1 && row - 1 != lastCoordinate.row) {
			this->vx = 0;
			this->vy = -BLOCK_HEIGHT * this->speed / 200;
			this->ims_monster = getImagesByTypeAndDirection(type, 'w');
			return Coordinate(row - 1, col);
		}
	}
	// ��
	if (row + 1 < ROW) {
		if (roadMap[row + 1][col] == 1 && row + 1 != lastCoordinate.row) {
			this->vx = 0;
			this->vy = BLOCK_HEIGHT * this->speed / 200;
			this->ims_monster = getImagesByTypeAndDirection(type, 's');
			return Coordinate(row + 1, col);
		}
	}
	// ��
	if (col - 1 > 0) {
		if (roadMap[row][col - 1] == 1 && col - 1 != lastCoordinate.col) {
			this->vx = -BLOCK_WIDTH * this->speed / 200;
			this->vy = 0;
			this->ims_monster = getImagesByTypeAndDirection(type, 'a');
			return Coordinate(row, col - 1);
		}
	}
	// ��
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
