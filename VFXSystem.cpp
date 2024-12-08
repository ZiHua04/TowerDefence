#include "VFXSystem.h"
#include "EasyXPng.h"
#include "Images.h"
#include "Constant.h"
#include "Toolkit.h"
void VFXSystem::draw()
{
	drawOnce();
	drawAllText();
}

void VFXSystem::drawAllText()
{
	for (int i = 0; i < texts.size(); i++) {
		Text* text = texts[i];
		settextcolor(text->color);
		drawText(text->info, text->x, text->y, text->font);
		text->y--;
		text->existTime -= TICK_TIME*1.0/1000;
		if (text->existTime < 0) {
			destoryText(text->id);
			break;
		}
	}
}

void VFXSystem::drawOnce()
{
	for (int i = 0; i < onceVFX.size(); i++) {
		switch (onceVFX[i]->type)
		{
		case VFXType::Hit:
			putimagePng(onceVFX[i]->x - onceVFX[i]->width/2, onceVFX[i]->y - onceVFX[i]->height / 2, &ims_vfx_hit[onceVFX[i]->aniId]);
			onceVFX[i]->aniCount++;
			if (onceVFX[i]->aniCount > ANI_MAX_COUNT/3) {
				onceVFX[i]->aniCount = 0;
				onceVFX[i]->aniId++;
				if (onceVFX[i]->aniId >= ims_vfx_hit.size()) {
					onceVFX[i]->aniId = 0;
					this->destoryVFX(onceVFX[i]->id);
					return;
				}
			}
			
			break;
		case VFXType::Boom:
			putimagePng(onceVFX[i]->x - onceVFX[i]->width / 2, onceVFX[i]->y - onceVFX[i]->height / 2, &ims_vfx_boom[onceVFX[i]->aniId]);
			onceVFX[i]->aniCount++;
			if (onceVFX[i]->aniCount > ANI_MAX_COUNT / 3) {
				onceVFX[i]->aniCount = 0;
				onceVFX[i]->aniId++;
				if (onceVFX[i]->aniId >= ims_vfx_boom.size()) {
					onceVFX[i]->aniId = 0;
					this->destoryVFX(onceVFX[i]->id);
					return;
				}
			}
			break;
		case VFXType::Ice:
			putimagePng(onceVFX[i]->x - onceVFX[i]->width / 2, onceVFX[i]->y - onceVFX[i]->height / 2, &ims_vfx_ice[onceVFX[i]->aniId]);
			onceVFX[i]->aniCount++;
			if (onceVFX[i]->aniCount > ANI_MAX_COUNT / 5) {
				onceVFX[i]->aniCount = 0;
				onceVFX[i]->aniId++;
				if (onceVFX[i]->aniId >= ims_vfx_ice.size()) {
					onceVFX[i]->aniId = 0;
					setfillcolor(BLUE);
					fillrectangle(0, 0, WIDHT, HEIGHT);
					this->destoryVFX(onceVFX[i]->id);
					return;
				}
			}
			break;
		case VFXType::BeIced:
			putimagePng(onceVFX[i]->x - onceVFX[i]->width / 2, onceVFX[i]->y - onceVFX[i]->height / 2, &ims_vfx_beIced[onceVFX[i]->aniId]);
			onceVFX[i]->aniCount++;
			if (onceVFX[i]->aniCount > ANI_MAX_COUNT / 3) {
				onceVFX[i]->aniCount = 0;
				onceVFX[i]->aniId++;
				if (onceVFX[i]->aniId >= ims_vfx_beIced.size()) {
					onceVFX[i]->aniId = 0;
					this->destoryVFX(onceVFX[i]->id);
					return;
				}
			}
			break;
		default:
			break;
		}
	}
}


void VFXSystem::destoryVFX(int id)
{
	// 使用 std::find_if 查找
	auto it = std::find_if(onceVFX.begin(), onceVFX.end(), [id](VFX * vfx) {
		return (vfx->id == id); // 比较对象的 id
		});
	if (it != onceVFX.end()) {
		delete* it;
		// 从 vector 中移除指针
		onceVFX.erase(it);
	}
}

void VFXSystem::destoryText(int id)
{
	// 使用 std::find_if 查找
	auto it = std::find_if(texts.begin(), texts.end(), [id](Text* text) {
		return (text->id == id); // 比较对象的 id
		});
	if (it != texts.end()) {
		delete* it;
		// 从 vector 中移除指针
		texts.erase(it);
	}
}

void VFXSystem::addText(std::string info, float x, float y, float existTime, int color, int font)
{
	texts.push_back(new Text(info, x, y, existTime, color, font));
}



void VFXSystem::update()
{
	this->draw();
}

void VFXSystem::PlayVFX(float x, float y, VFXType type, VFXPlayClass playClass)
{
	VFX* vfx = new VFX(type, x, y);
	switch (playClass)
	{
	case VFXPlayClass::Once:
		this->onceVFX.push_back(vfx);
		break;
	default:
		break;
	}
}

VFX::VFX(VFXType type, float x, float y)
{
	this->id = ++vfxId;
	this->type = type;
	this->x = x;
	this->y = y;
	this->aniCount = 0;
	this->aniId = 0;
	switch (type)
	{
	case VFXType::Hit:
		this->width = ims_vfx_hit[0].getwidth();
		this->height = ims_vfx_hit[0].getheight();
		break;
	case VFXType::Boom:
		this->width = ims_vfx_boom[0].getwidth();
		this->height = ims_vfx_boom[0].getheight();
		break;
	case VFXType::Ice:
		this->width = ims_vfx_ice.back().getwidth();
		this->height = ims_vfx_ice.back().getheight();
		break;
	case VFXType::BeIced:
		this->width = ims_vfx_beIced.back().getwidth();
		this->height = ims_vfx_beIced.back().getheight();
		break;
	default:
		break;
	}
}

Text::Text(std::string info, float x, float y, float existTime, int color, int font)
{
	this->id = ++textId;
	this->info = info;
	this->x = x;
	this->y = y;
	this->existTime = existTime;
	this->color = color;
	this->font = font;
}
