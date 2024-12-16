
#include "FrontPage.h"
#include <graphics.h>
#include "Constant.h"
#include "EasyXPng.h"
#include "Toolkit.h"
// 关卡图标
std::vector<LevelIcon*> levelIcons;

void frontPageInput() {
	if (!peekmessage(&m)) return;
	// 获取一条鼠标或按键消息
	switch (m.message)
	{
	case WM_LBUTTONDOWN:
		frontPageClick(m.x, m.y);
		break;
	}
}

void frontPageClick(float x, float y) {

	// 检查是否点击外面
	if (x < 0 || x > WIDHT || y < 0 || y > HEIGHT) return;
	audioSystem->playAudio(AudioType::Click);
	// 检查是否点击Play按钮
	if (x > WIDHT/2 - 100 && x < WIDHT/2 + 100 && y > 330 && y < 400) {
		for (int i = 0; i < 3; i++) {
			LevelIcon* leveIcon = new LevelIcon((i-1) * im_front_level.getwidth() * 1.2 + WIDHT/2 - im_front_level.getwidth()/2, HEIGHT - 200, 100, 100, i);
			levelIcons.push_back(leveIcon);
		}
		return;
	}
	// 检查是否选择了某一关卡
	for (int i = 0; i < levelIcons.size(); i++) {
		LevelIcon* levelIcon = levelIcons[i];

		if (x > levelIcon->x&& x < levelIcon->x + levelIcon->width && y > levelIcon->y && y < levelIcon->y + levelIcon->height) {
			currentGameState = GameState::PLAYING;
			levelIcons.clear();
			currentLevel = i;
			return;
		}
	}
	
}

void frontPageDraw()
{
	for (int i = 0; i < levelIcons.size(); i++) {
		float x = levelIcons[i]->x;
		float y = levelIcons[i]->y;
		float width = levelIcons[i]->width;
		float height = levelIcons[i]->height;
		int diff = levelIcons[i]->diff;
		putimagePng(x, y, &im_front_level);
		int id = 0;
		switch (i)
		{
		case 0:
			levelIcons[i]->aniCount++;
			if (levelIcons[i]->aniCount >= ANI_MAX_COUNT) {
				levelIcons[i]->aniCount = 0;
				levelIcons[i]->aniId++;
				levelIcons[i]->aniId %= ims_monster_s.size();
			}
			id = levelIcons[i]->aniId;
			putimagePng(x + width / 2 - ims_monster_s[0].getwidth() / 2-5, y + 10, &ims_monster_s[id]);
			break;
		case 1:
			levelIcons[i]->aniCount++;
			if (levelIcons[i]->aniCount >= ANI_MAX_COUNT) {
				levelIcons[i]->aniCount = 0;
				levelIcons[i]->aniId++;
				levelIcons[i]->aniId %= ims_dog_s.size();
			}
			id = levelIcons[i]->aniId;
			putimagePng(x + width / 2 - ims_dog_s[0].getwidth() / 2 -5, y + 10, &ims_dog_s[id]);
			break;
		default:
			levelIcons[i]->aniCount++;
			if (levelIcons[i]->aniCount >= ANI_MAX_COUNT) {
				levelIcons[i]->aniCount = 0;
				levelIcons[i]->aniId++;
				levelIcons[i]->aniId %= ims_bee_s.size();
			}
			id = levelIcons[i]->aniId;
			putimagePng(x + width / 2 - ims_bee_s[0].getwidth() / 2-5, y + 10, &ims_bee_s[id]);
			break;
		}
		
		drawText("难度：" + std::to_string(diff), x + width/2 - 40, y + height - 20);
	}
	FlushBatchDraw();
}



LevelIcon::LevelIcon(float x, float y, float width, float height, int diff)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->diff = diff;
}
