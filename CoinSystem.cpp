#include "CoinSystem.h"
#include "Toolkit.h"
#include "Constant.h"
#include "EasyXPng.h"

CoinSystem::CoinSystem() {
	
}

void CoinSystem::addCoin(int value, float x, float y) {
	TextWithPos text;
	text.text = std::to_string(value);
	text.x = x;
	text.y = y;
	texts.push_back(text);
	this->currentCoin += value;
}

bool CoinSystem::subCoin(int value) {
	if (getCoin() - value < 0) return false;
	this->currentCoin -= value;
}

int CoinSystem::getCoin() {
	return this->currentCoin;
}

void CoinSystem::draw() {
	if (this == nullptr) return;
	putimagePng(WIDHT - 70, 20, &ims_coin[aniId]);
	aniCount++;
	if (aniCount > ANI_MAX_COUNT) {
		aniCount = 0;
		aniId++;
		aniId %= ims_coin.size();
	}
	// ����ǰʣ����
	settextcolor(YELLOW);
	drawText(std::to_string(currentCoin), WIDHT - 50, 10, 30);

	for (int i = 0; i < this->texts.size(); i++) {
		drawText(texts[i].text, texts[i].x, texts[i].y, 20);
		putimagePng(texts[i].x-15, texts[i].y+3, &ims_coin[texts[i].aniId]);
		texts[i].aniCount++;
		if (texts[i].aniCount > ANI_MAX_COUNT/5) {
			texts[i].aniCount = 0;
			texts[i].aniId++;
			texts[i].aniId %= ims_coin.size();
		}
	}
}

void CoinSystem::update() {
	if (this == nullptr) return;
	//draw();
	for (int i = 0; i < this->texts.size(); i++) {
		texts[i].y--;
		texts[i].counter--;
	}
	auto it = std::find_if(texts.begin(), texts.end(), [](TextWithPos text) {
		return (text.counter < 0); // �Ƚ϶���� id
		});
	if (it != texts.end()) {
		// �ͷ��ڴ�
		//delete &it;
		// �� vector ���Ƴ�ָ��
		texts.erase(it);
	}

}

void CoinSystem::reset()
{
	this->currentCoin = 100;
}
