#pragma once
#ifndef TOWER_H
#define TOWER_H

#include "Constant.h"



static int TowerId = 0;
class Tower
{
public:
	int id; // 塔的id,唯一标识符
	TowerType type; // 塔的类型
	//- 位置相关
	float x, y; // 塔的中心坐标
	int row, col; // 塔所在的行和列
	float width = 62, height = 62; // 塔的宽高
	//- 动画相关
	int aniCount = 0;
	int aniId = 0;
	//- 共有属性
	int heart; // 剩余血量
	int currentGrade;// 当前等级
	float speed; // 塔的攻击速度/加金币的速度，单位：次/秒
	int upgradeCost; // 升级花费
	std::vector<IMAGE> ims_tower; // 塔的图片
	//- 攻击属性
	int shootCount = 0;
	float attckRange; // 攻击范围
	//- 金币属性
	int coinPerSecond; // 每秒产出金币数量
	// 构造函数
	Tower(TowerType type, Coordinate coordinate);
	// 绘制
	void draw();
	// 更新
	void update();
	// 射击
	void Shoot();
	// 加钱
	void addCoin();
	// 升级
	void upgrade();
	// 加载塔的信息
	void loadTowerInfo();
	// 扣血
	void subHeart(int value);
};
#endif // !TOWER_H


