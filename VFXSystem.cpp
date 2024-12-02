#include "VFXSystem.h"
#include "EasyXPng.h"
#include "Images.h"
#include "Constant.h"
#include "Toolkit.h"
void VFXSystem::draw()
{
	drawOnce();
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
			setlinecolor(RED);
			drawText("-1", onceVFX[i]->x - onceVFX[i]->width / 2, onceVFX[i]->y - onceVFX[i]->height / 2, 10);
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
	default:
		break;
	}
}
