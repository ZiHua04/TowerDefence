#pragma once
#ifndef MONSTER_H
#define MONSTER_H

#include <graphics.h>
#include "Constant.h"
static int MonsterId;

class Monster
{
public:

	int id;// �����Ψһ��ʶ��
	float x, y; // �����λ��
	float vx = 0, vy = 0; // ������ٶ�
	float width, height; // ����Ŀ�Ⱥ͸߶�
	int aniId = 0; // ����Ķ���ID
	int aniCount = 0; // ���ﶯ���ļ���

	bool isArrived = false; // �Ƿ񵽴�Ŀ��λ��

	int heart;// ����ֵ
	float speed;// �ٶ�,��λ��block_width/��
	float dropCoins;// ������

	int timeCount = 0;

	Coordinate currentCoordinate; // ��ǰ����
	Coordinate lastCoordinate; // ��һ������

	std::vector<IMAGE> ims_monster;

	MonsterType type; // ��������

	bool isIced = false;

	Monster(MonsterType type, Coordinate coordinate);
	~Monster();
	void drawHeart(); // ���ƹ���Ѫ��
	void draw(); // ���ƹ���
	void move(); // �ƶ�����, ÿ0.1s����һ��
	void update(); // ���¹���״̬, ÿ0.1s����һ��
	Coordinate findNext(); // Ѱ����һ������

	void subHeart(int value);

	// ���������ֻ���۷����
	void shoot();
	// ������
	void beIced();
	// �ָ�
	void recover();
};




#endif // !MONSTER_H





