
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
				destoryBulletById(bullet->id);// �����ӵ�
				vfxSystem->PlayVFX(monster->x, monster->y, VFXType::Hit);// ������Ч
				monster->subHeart(1); // ��������ֵ
				return;
			}
		}
	}
	// ��������ӵ�����
	for (int i = 0; i < enemyBullets.size(); i++) {
		std::map<Coordinate, Tower*>::iterator iter;
		for (iter = towers.begin(); iter != towers.end(); iter++) {
			//cout << iter->first << " : " << iter->second << endl;
			float x1 = iter->second->x;
			float y1 = iter->second->y;
			float width1 = iter->second->width;
			float height1 = iter->second->height;
			float x2 = enemyBullets[i]->x;
			float y2 = enemyBullets[i]->y;
			float width2 = enemyBullets[i]->width;
			float height2 = enemyBullets[i]->height;
			if (DetectTwoRectangle(x1, y1, x2, y2, width1, height1, width2, height2)) {
				
				// ������Ч
				vfxSystem->PlayVFX(enemyBullets[i]->x, enemyBullets[i]->y, VFXType::Hit);// ������Ч
				// ��������ֵ
				// 
				// �����ӵ�
				destoryEnemyBulletById(enemyBullets[i]->id);
				return;
			}
		}
	}
}

int tempSecondCount = 0;
// ����ÿ��
void updatePerSecond() {
	// ��7:2:1�ĸ������ɸ粼�֣�����Ȯ��а���۷�
	if (getRate(0.7)) {
		monsters.push_back(new Monster(MonsterType::Goblin, Coordinate(6, 1)));
	}
	else if(getRate(2.0/3)){
		monsters.push_back(new Monster(MonsterType::Dog, Coordinate(6, 1)));
	}
	else {
		monsters.push_back(new Monster(MonsterType::Bee, Coordinate(6, 1)));
	}
	
	
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

	for (int i = 0; i < enemyBullets.size(); i++) {
		enemyBullets[i]->update();
	}

	coinSystem->update();
	vfxSystem->update();

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