#pragma once
#ifndef CLICKBUTTON_H
#define CLICKBUTTON_H

#include <vector>
#include <graphics.h>
#include "Constant.h"

class ClickButton
{
public:

	ClickButtonType type; // 按钮类型
	Coordinate lastClickCoordinate; // 上一次点击的坐标
	float x = 0, y = 0;
	float width = 0, height = 0;
	int aniId = 0;
	int aniCount = 0;

	// 构造函数
	ClickButton();
	// 绘制
	void draw();
	// 更新
	void update();
	// 点击某一个方块
	void clickCoordinate(Coordinate coordinate);
	// 显示
	void show(ClickButtonType type, Coordinate coordinate);
	// 隐藏
	void hide();
};

#endif // !CLICKBUTTON_H
