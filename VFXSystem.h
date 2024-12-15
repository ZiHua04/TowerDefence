#pragma once
#ifndef VFXSYSTEM_H
#define VFXSYSTEM_H

#include "Enum.h"
#include <vector>
#include <string>

static int textId;
struct Text
{
public:
	Text(std::string info, float x, float y, float existTime = 1, int color = 0x000000, int font = 24);
	int id;
	int font;
	int color;
	float x, y;
	float existTime;
	std::string info;
};

static int vfxId;
struct VFX
{
public:
	VFX(VFXType type, float x, float y);
	int id;
	VFXType type;
	float x;
	float y;
	int aniId;
	int aniCount;
	float width;
	float height;
};

class VFXSystem
{
private:
	std::vector<VFX*>  onceVFX;
	std::vector<Text*> texts;
	
	void drawAllText();
	void drawOnce();
	void destoryVFX(int id);
	void destoryText(int id);
	
public:
	VFXSystem() {

	}
	void update();
	void draw();
	// 播放特效
	void PlayVFX(float x, float y, VFXType type, VFXPlayClass playClass = VFXPlayClass::Once);
	// 播放文字
	void addText(std::string info, float x, float y, float existTime = 1, int color = 0x000000, int font = 24);
};



#endif // !VFXSYSTEM_H