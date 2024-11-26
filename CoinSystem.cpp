#include "CoinSystem.h"
#include "Toolkit.h"
#include "Constant.h"

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
	if (getCoin() - value <= 0) return false;
	this->currentCoin -= value;
}

int CoinSystem::getCoin() {
	return this->currentCoin;
}

void CoinSystem::draw() {
	// ����ǰʣ����
	drawText(std::to_string(currentCoin), WIDHT - 100, 30, 30);

	for (int i = 0; i < this->texts.size(); i++) {
		drawText(texts[i].text, texts[i].x, texts[i].y, 20);
	}
}

void CoinSystem::update() {
	draw();
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