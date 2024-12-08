#pragma once
#ifndef PROPSYSTEM_H
#define PROPSYSTEM_H

#include "Enum.h"

struct Prop
{
public:
	Prop(float x, float y, float width, float height, PropType type, float totalCoolTime, int cost, float range);
	PropType type;
	float x, y;
	float width, height;
	float totalCoolTime;
	float countTime;
	int cost;
	float range;
	void subCountTime();
};

class PropSystem
{
private:
	void draw();
	void drawIce();
	void drawBomb();
	void useProp();
	void useIce();
	void useBomb();
	void clickIce();
	void clickBomb();
	bool isUsingProp = false;
	PropType usingType = PropType::Boom;
public:
	Prop* iceProp;
	Prop* bombProp;
	Prop* cancelProp;
	PropSystem();
	void update();
	bool click(float x, float y);
	
};

#endif // !PROPSYSTEM_H





