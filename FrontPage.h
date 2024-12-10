#pragma once
#ifndef FRONT_PAGE_H
#define FRONT_PAGE_H

#include "Global.h"
struct LevelIcon
{
public:
	LevelIcon(float x, float y, float width, float height, int diff);
	float x, y;
	float width, height;
	int diff;
};
// ¹Ø¿¨Í¼±ê
extern std::vector<LevelIcon*> levelIcons;

void frontPageInput();

void frontPageClick(float x, float y);

void frontPageDraw();

#endif // !FRONT_PAGE_H
