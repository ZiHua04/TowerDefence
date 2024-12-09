#include "PropSystem.h"

#include "Constant.h"
#include "EasyXPng.h"
#include "Toolkit.h"
#include "Global.h"

PropSystem::PropSystem()
{
	this->iceProp = new Prop(BLOCK_WIDTH * (COL - 2) + 16, BLOCK_HEIGHT * (ROW - 1) + 30, 64, 64
		,PropType::Ice, 10, 200, 200);
	this->bombProp = new Prop(BLOCK_WIDTH * (COL - 1) + 16, BLOCK_HEIGHT * (ROW - 1) + 30, 64, 64
		, PropType::Boom, 5, 100, 150);
	this->cancelProp = new Prop(BLOCK_WIDTH * (COL - 3) + 16, BLOCK_HEIGHT * (ROW - 1) + 30, 64, 64
		, PropType::Cancel, 5, 100, 150);
}

void PropSystem::draw()
{
	if (this->isUsingProp) {
		// ����ȡ����ť
		putimagePng(cancelProp->x, cancelProp->y, &im_wrong);


		if (this->usingType == PropType::Ice) {
			// ��������
			setlinestyle(PS_DASH | PS_ENDCAP_FLAT, 1);
			setfillcolor(RGB(0, 191, 255));
			setfillstyle(BS_HATCHED, HS_BDIAGONAL);
			fillcircle(m.x, m.y, iceProp->range);
			setfillstyle(BS_SOLID);
			// ������ë
			putimagePng(m.x - im_ice.getwidth() / 2, m.y - im_ice.getheight() / 2, &im_ice);
			// ������������
			drawBomb();
		}
		else if(this->usingType == PropType::Boom){
			// ��������
			setlinestyle(PS_DASH | PS_ENDCAP_FLAT, 1);
			setfillcolor(RGB(255, 140, 0));
			setfillstyle(BS_HATCHED, HS_DIAGCROSS);
			fillcircle(m.x, m.y, bombProp->range);
			setfillstyle(BS_SOLID);
			// ����ը��
			putimagePng(m.x - im_bomb.getwidth() / 2, m.y - im_bomb.getheight() / 2, &im_bomb);

			// ������������
			drawIce();
		}

		return;
	}

	drawIce();
	drawBomb();
	
	
}

void PropSystem::drawIce()
{
	settextcolor(YELLOW);
	drawText(std::to_string(iceProp->cost), iceProp->x + 18, iceProp->y - 20, 20);

	putimagePng(iceProp->x + 32 - im_ice.getwidth() / 2, iceProp->y, &im_ice);

	setlinecolor(BLACK);
	setlinestyle(PS_SOLID, 4);
	rectangle(iceProp->x, iceProp->y, iceProp->x + iceProp->width, iceProp->y + iceProp->height);

	setfillcolor(BLACK);
	setfillstyle(BS_HATCHED, HS_DIAGCROSS);
	float top = iceProp->y + iceProp->height * (iceProp->totalCoolTime - iceProp->countTime) / iceProp->totalCoolTime;
	fillrectangle(iceProp->x, top, iceProp->x + iceProp->width, iceProp->y + iceProp->height);
	setfillstyle(BS_SOLID);
}

void PropSystem::drawBomb()
{
	
	settextcolor(YELLOW);
	drawText(std::to_string(bombProp->cost), bombProp->x + 18, bombProp->y - 20, 20);

	putimagePng(bombProp->x + 32 - im_bomb.getwidth() / 2, bombProp->y, &im_bomb);

	setlinecolor(BLACK);
	setlinestyle(PS_SOLID, 4);
	rectangle(bombProp->x, bombProp->y, bombProp->x + bombProp->width, bombProp->y + bombProp->height);

	setfillcolor(BLACK);
	setfillstyle(BS_HATCHED, HS_DIAGCROSS);
	float top = bombProp->y + bombProp->height * (bombProp->totalCoolTime - bombProp->countTime) / bombProp->totalCoolTime;
	fillrectangle(bombProp->x, top, bombProp->x + bombProp->width, bombProp->y + bombProp->height);
	setfillstyle(BS_SOLID);
}

void PropSystem::update()
{
	draw();
	this->bombProp->subCountTime();
	this->iceProp->subCountTime();
	if (!isUsingProp) return;

}

bool PropSystem::click(float x, float y)
{
	// ����Ƿ�����ice
	if (x > iceProp->x && x < iceProp->x + iceProp->width && y > iceProp->y && y < iceProp->y + iceProp->height) {
		clickIce();
		return true;
	}
	// ����Ƿ�����bomb
	if (x > bombProp->x && x < bombProp->x + bombProp->width && y > bombProp->y && y < bombProp->y + bombProp->height) {
		clickBomb();
		return true;
	}
	// ����Ƿ�����ȡ����ť
	if (x > cancelProp->x && x < cancelProp->x + cancelProp->width && y > cancelProp->y && y < cancelProp->y + cancelProp->height && isUsingProp) {
		this->isUsingProp = false;
		return true;
	}
	// ����Ƿ�����ʹ�õ���
	if (isUsingProp) {


		useProp();

		this->isUsingProp = false;
		return true;
	}
	return false;
}

void PropSystem::clickIce()
{
	// ������Ƿ�
	if (!coinSystem->subCoin(iceProp->cost)) { return; }
	// �����ȴʱ��
	if (iceProp->countTime > 0) return;
	this->isUsingProp = true;
	this->usingType = PropType::Ice;
	
}
// ʹ�õ���
void PropSystem::useProp()
{
	switch (this->usingType)
	{
	case PropType::Boom:
		useBomb();
		break;
	case PropType::Ice:
		useIce();
		break;
	default:
		break;
	}
}

void PropSystem::useIce()
{
	// ������Ч
	vfxSystem->PlayVFX(m.x, m.y, VFXType::Ice);


	// ���������ڵĹ���
	for (int i = 0; i < monsters.size(); i++) {
		Monster* monster = monsters[i];
		if (isCircleRectangleIntersect(m.x, m.y, iceProp->range,
			monster->x - monster->width / 2, monster->y - monster->height / 2,
			monster->x + monster->width / 2, monster->y + monster->height / 2)) {
			monster->beIced();
		}
	}
	iceProp->countTime = iceProp->totalCoolTime;
}
void PropSystem::useBomb()
{
	// ������Ч
	vfxSystem->PlayVFX(m.x, m.y, VFXType::Boom);
	// ���������ڵĹ���
	for (int i = 0; i < monsters.size(); i++) {
		Monster* monster = monsters[i];
		if (isCircleRectangleIntersect(m.x, m.y, bombProp->range, 
			monster->x - monster->width / 2, monster->y - monster->height / 2,
			monster->x + monster->width / 2, monster->y + monster->height / 2)) {
			monster->subHeart(10);
		}
	}
	bombProp->countTime = bombProp->totalCoolTime;
}


void PropSystem::clickBomb()
{
	// ������Ƿ�
	if (!coinSystem->subCoin(bombProp->cost)) { return; }
	// �����ȴʱ��
	if (bombProp->countTime > 0) return;
	this->isUsingProp = true;
	this->usingType = PropType::Boom;
	
}


Prop::Prop(float x, float y, float width, float height, PropType type, float totalCoolTime, int cost, float range)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->type = type;
	this->totalCoolTime = totalCoolTime;
	this->countTime = 0;
	this->cost = cost;
	this->range = range;
}

void Prop::subCountTime()
{
	if (countTime > 0) {
		countTime -= TICK_TIME*1.0/1000;
	}
}
