
#include "Images.h"
#include "Constant.h"
#include "Toolkit.h"
#include <conio.h>
#include "Monster.h"
#include "ClickButton.h"
// ����
std::vector<Monster*> monsters;
// ������ť
ClickButton* clickButton = new ClickButton();

void destoryMonsterById(int id) {
	// ʹ�� std::find_if ����
	auto it = std::find_if(monsters.begin(), monsters.end(), [id](Monster* monster) {
		return (monster->id == id); // �Ƚ϶���� id
		});
	if (it != monsters.end()) {
		// �ͷ��ڴ�
		delete* it;
		// �� vector ���Ƴ�ָ��
		monsters.erase(it);
	}
}
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
	}

	clickButton->update();

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