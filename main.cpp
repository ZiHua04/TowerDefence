
#include "Images.h"
#include "Constant.h"
#include "Toolkit.h"
#include <conio.h>
#include "Global.h"




// ��ʼ��һ����Ϸ
void init() {
	initgraph(WIDHT, HEIGHT); // ��ʼ��ͼ�δ���
}
ExMessage m;
// �������ͼ�������
void input() {
	if (!peekmessage(&m)) return;
	// ��ȡһ�����򰴼���Ϣ
	switch (m.message)
	{
	case WM_LBUTTONDOWN:
		float x = m.x;
		float y = m.y;
		int col = x / BLOCK_WIDTH;
		int row = y / BLOCK_HEIGHT;
		if (col < 0 || col >= COL || row < 0 || row >= ROW) return;
		clickButton->clickCoordinate(Coordinate(row, col));
		break;
	}
}
// ����������ײ�¼�
void detectAll() {
	// �����ӵ��͹���
	for (int i = 0; i < bullets.size(); i++) {
		for (int j = 0; j < monsters.size(); j++) {
			Bullet* bullet = bullets[i];
			Monster* monster = monsters[j];
			if (DetectTwoRectangle(bullet->x, bullet->y, monster->x-monster->width/2, monster->y-monster->heart/2, bullet->width, bullet->height, monster->width, monster->height)) {
				destoryBulletById(bullet->id);
				monster->subHeart(1);
				return;
			}
		}
	}
}

int tempSecondCount = 0;
// ����ÿ��
void updatePerSecond() {
	monsters.push_back(new Monster(MonsterType::Goblin, Coordinate(6, 1)));
	
}
// ����������Ϸ����
void updateAll() {
	for (int i = 0; i < monsters.size(); i++) {
		monsters[i]->update();
		if (monsters[i]->isArrived) {
			destoryMonsterById(monsters[i]->id);
			i--;
			continue;
		}
		if (monsters[i]->heart < 0) {
			destoryMonsterById(monsters[i]->id);
			i--;
			continue;
		}
	}

	clickButton->update();

	for (const auto& pair : towers) {
		// pair.first �Ǽ� (Coordinate)�� pair.second ��ֵ (Tower*)
		pair.second->update();
	}

	for (int i = 0; i < bullets.size(); i++) {
		bullets[i]->update();
	}

	coinSystem->update();

	tempSecondCount+=5;
	if (tempSecondCount >= 1000) {
		updatePerSecond();
		tempSecondCount = 0;
	}
}
// ����������Ϸ����
void drawAll() {
	putimage(0, 0, &im_bk); // ���Ʊ���
	for (int i = 0; i < monsters.size(); i++) {
		monsters[i]->draw();
	}
}
GameState currentGameState = GameState::START_SCENE;
#pragma region ��ʼ���棬��ʱ�ò���
// ��ʾ��ʼ�˵�����
void ShowStartScene() {
	initgraph(WIDHT, HEIGHT); // ��ʼ��ͼ�δ���
	while (currentGameState == GameState::START_SCENE) {

		drawText("���ǿ�ʼ����", WIDHT / 2, HEIGHT / 2, 40);
		drawText("���ո����ʼ��Ϸ", WIDHT / 2, HEIGHT / 2 + 50, 30);
		if (_getch() == ' ') {
			currentGameState = GameState::PLAYING;
		};
	}
	closegraph();
}
#pragma endregion

#pragma region ������棬��ʱ�ò���
// ��ʾ���㳡��
void ShowResultScene() {
	initgraph(WIDHT, HEIGHT); // ��ʼ��ͼ�δ���
	while (currentGameState == GameState::WIN || currentGameState == GameState::LOSE) {
		
		drawText("���ǽ������", WIDHT / 2, HEIGHT / 2, 40);
		drawText("���ո��������Ϸ", WIDHT / 2, HEIGHT / 2 + 50, 30);
		if (_getch() == ' ') {
			currentGameState = GameState::START_SCENE;
		};
	}
	closegraph();
}
#pragma endregion

#pragma region ��Ϸ�н���
// ��ʾ��Ϸ����
void ShowPlayingScene() {
	init();// ��ʼ����Ϸ��Դ
	BeginBatchDraw(); // ��ʼ��������
	while (currentGameState == GameState::PLAYING)
	{
		input();

		detectAll();
		
		cleardevice();
		drawAll();
		updateAll();
		FlushBatchDraw();

		Sleep(5);
		
		
	}
    EndBatchDraw(); // ������������
	closegraph();
}
#pragma endregion

int main() {
	loadAllImages(); // ��������ͼƬ
	addMaps();
	while (currentGameState != GameState::EXIT) {
		ShowStartScene(); // ��ʾ��ʼ�˵�����
		ShowPlayingScene(); // ��ʾ��Ϸ����
		ShowResultScene(); // ��ʾ���㳡��
		
	}
	return 0;
}