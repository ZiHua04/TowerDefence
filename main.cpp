
#include "Images.h"
#include "Constant.h"
#include "Toolkit.h"
#include <conio.h>
#include "Monster.h"
std::vector<Monster*> monsters;

// ��ʼ��һ����Ϸ
void init() {
	initgraph(WIDHT, HEIGHT); // ��ʼ��ͼ�δ���
}
// �������ͼ�������
void input() {

}
// ����������ײ�¼�
void detectAll() {

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
	}

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
		drawText("���������ʼ��Ϸ", WIDHT / 2, HEIGHT / 2 + 50, 30);
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
		drawText("�������������Ϸ", WIDHT / 2, HEIGHT / 2 + 50, 30);
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
		updateAll();

		cleardevice();
		drawAll();
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