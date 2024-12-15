
#include "FrontPage.h"
#include <graphics.h>
#include "Constant.h"
#include "EasyXPng.h"
#include "Toolkit.h"
// �ؿ�ͼ��
std::vector<LevelIcon*> levelIcons;

void frontPageInput() {
	if (!peekmessage(&m)) return;
	// ��ȡһ�����򰴼���Ϣ
	switch (m.message)
	{
	case WM_LBUTTONDOWN:
		frontPageClick(m.x, m.y);
		break;
	}
}

void frontPageClick(float x, float y) {
	// ����Ƿ�������
	if (x < 0 || x > WIDHT || y < 0 || y > HEIGHT) return;
	// ����Ƿ���Play��ť
	if (x > WIDHT/2 - 100 && x < WIDHT/2 + 100 && y > 330 && y < 400) {
		for (int i = 0; i < 3; i++) {
			LevelIcon* leveIcon = new LevelIcon((i-1) * im_front_level.getwidth() * 1.2 + WIDHT/2 - im_front_level.getwidth()/2, HEIGHT - 200, 100, 100, i);
			levelIcons.push_back(leveIcon);
		}
		return;
	}
	// ����Ƿ�ѡ����ĳһ�ؿ�
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
		putimagePng(x+width/2- ims_monster_s[0].getwidth()/2, y+10, &ims_monster_s[diff]);
		drawText("�Ѷȣ�" + std::to_string(diff), x + width/2 - 40, y + height - 20);
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