#pragma once
#ifndef MONSTER_H
#define MONSTER_H

#include <graphics.h>
#include "Constant.h"
static int MonsterId;

class Monster
{
public:

	int id;// 怪物的唯一标识符
	float x, y; // 怪物的位置
	float vx = 0, vy = 0; // 怪物的速度
	float width, height; // 怪物的宽度和高度
	int aniId = 0; // 怪物的动画ID
	int aniCount = 0; // 怪物动画的计数

	bool isArrived = false; // 是否到达目标位置

	int heart;// 生命值
	float speed;// 速度,单位是block_width/秒
	float dropCoins;// 掉落金币

	Coordinate currentCoordinate; // 当前坐标
	Coordinate lastCoordinate; // 上一个坐标

	std::vector<IMAGE> ims_monster;

	MonsterType type; // 怪物类型

	Monster(MonsterType type, Coordinate coordinate);
	void drawHeart(); // 绘制怪物血条
	void draw(); // 绘制怪物
	void move(); // 移动怪物, 每0.1s调用一次
	void update(); // 更新怪物状态, 每0.1s调用一次
	Coordinate findNext(); // 寻找下一个坐标

	void subHeart(int value);
};




#endif // !MONSTER_H





