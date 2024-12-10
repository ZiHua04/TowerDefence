#pragma once
#ifndef CLICKBUTTON_H
#define CLICKBUTTON_H

#include <vector>
#include <graphics.h>
#include "Constant.h"

class ClickButton
{
public:

	ClickButtonType type; // ��ť����
	Coordinate lastClickCoordinate; // ��һ�ε��������
	float x = 0, y = 0;
	float width = 0, height = 0;
	int aniId = 0;
	int aniCount = 0;

	// ���캯��
	ClickButton();
	// ����
	void draw();
	// ����
	void update();
	// ���ĳһ������
	void clickCoordinate(Coordinate coordinate);
	// ��ʾ
	void show(ClickButtonType type, Coordinate coordinate);
	// ����
	void hide();
};

#endif // !CLICKBUTTON_H
