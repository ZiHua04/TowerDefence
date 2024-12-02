#pragma once
#ifndef VFXSYSTEM_H
#define VFXSYSTEM_H

#include "Enum.h"
#include <vector>
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
	void draw();
	void drawOnce();
	void destoryVFX(int id);

public:
	VFXSystem() {

	}
	void update();
	
	// ≤•∑≈Ãÿ–ß
	void PlayVFX(float x, float y, VFXType type, VFXPlayClass playClass = VFXPlayClass::Once);
	
};



#endif // !VFXSYSTEM_H

