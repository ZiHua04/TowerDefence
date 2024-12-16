#pragma once
#ifndef COINSYSTEM_H
#define COINSYSTEM_H

#include <map>
#include <string>
#include <vector>

struct TextWithPos
{
public:
	float x;
	float y;
	std::string text;
	int counter = 50;
	int aniId = 0;
	int aniCount = 0;
};

class CoinSystem
{
private:
	int currentCoin = 50; // 初始金币
	int aniId = 0;
	int aniCount = 0;
public:
	std::vector<TextWithPos> texts; // 界面上显示的加金币文字

	CoinSystem(); // 构造函数

	void addCoin(int value, float x, float y); // 加金币
	bool subCoin(int value); // 减金币，如果金币不够返回false
	int getCoin(); // 查询当前金币
	void draw(); // 绘制
	void update(); // 更新
	void reset();
};

#endif // !COINSYSTEM_H
