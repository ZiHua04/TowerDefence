
#include "Images.h"
#include "Constant.h"
#include "Toolkit.h"
#include <conio.h>
#include "Global.h"
#include "FrontPage.h"
#include <thread>


// ��ʼ��һ����Ϸ
void init() {
	initgraph(WIDHT, HEIGHT); // ��ʼ��ͼ�δ���
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			roadMap[i][j] = levelInfoMap[currentLevel].roadMap[i][j];
			towerMap[i][j] = levelInfoMap[currentLevel].towerMap[i][j];
		}
	}

	monsterCreator = new MonsterCreator();
	monsterCreator->startCreate();
}

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
		if (propSystem->click(x, y)) return;

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
			if (iter->second == NULL) return;
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
				iter->second->subHeart(1);
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




}
// ����������Ϸ����
void updateAll() {


	for (int i = 0; i < monsters.size(); i++) {
		monsters[i]->update();
		
	}

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
	clickButton->update();
	coinSystem->update();
	vfxSystem->update();
	propSystem->update();
	monsterCreator->update();

	tempSecondCount += TICK_TIME;
	if (tempSecondCount >= 1000) {
		updatePerSecond();
		tempSecondCount = 0;
	}
}
// ����������Ϸ����
void drawAll() {
	putimage(0, 0, &levelInfoMap[currentLevel].im_bk); // ���Ʊ���
	// ���ƹ���
	for (int i = 0; i < monsters.size(); i++) {
		monsters[i]->draw();
	}
	// ������
	for (const auto& pair : towers) {
		// pair.first �Ǽ� (Coordinate)�� pair.second ��ֵ (Tower*)
		pair.second->draw();
	}
	// �����ӵ�
	for (int i = 0; i < bullets.size(); i++) {
		bullets[i]->draw();
	}
	for (int i = 0; i < enemyBullets.size(); i++) {
		enemyBullets[i]->draw();
	}
	// ����ClickButton
	clickButton->draw();
	// ���ƽ��
	coinSystem->draw();
	// ������Ч
	vfxSystem->draw();
	// ���Ƶ���
	propSystem->draw();
	// ���ƹ�������
	monsterCreator->draw();
	
}

#pragma region ��ʼ���棬��ʱ�ò���
// ��ʾ��ʼ�˵�����
void ShowStartScene() {
	initgraph(WIDHT, HEIGHT); // ��ʼ��ͼ�δ���
	BeginBatchDraw(); // ��ʼ��������
	while (currentGameState == GameState::START_SCENE) {
		// �������
		frontPageInput();
		/*drawText("���ǿ�ʼ����", WIDHT / 2, HEIGHT / 2, 40);
		drawText("���ո����ʼ��Ϸ", WIDHT / 2, HEIGHT / 2 + 50, 30);*/
		putimage(0, 0, &im_front_bk);
		/*if (_getch() == ' ') {
			currentGameState = GameState::PLAYING;
		};*/
		frontPageDraw();
		Sleep(5);
	}
	EndBatchDraw(); // ����
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
	// �������
	std::thread([]() {
		while (currentGameState == GameState::PLAYING)
		{
			input();
			std::this_thread::sleep_for(std::chrono::milliseconds((int)TICK_TIME));
		}

		}).detach();
	// ��ײ������
	/*std::thread([]() {
		while (currentGameState == GameState::PLAYING)
		{
			detectAll();
			std::this_thread::sleep_for(std::chrono::milliseconds(5));
		}

		}).detach();*/
	// ���½���
	std::thread([]() {
		while (currentGameState == GameState::PLAYING)
		{
			detectAll();
			updateAll();
			cleardevice();
			drawAll();
			FlushBatchDraw();
			std::this_thread::sleep_for(std::chrono::milliseconds((int)TICK_TIME));
		}

		}).detach();
	
	while (currentGameState == GameState::PLAYING)
	{
		//input();

		//detectAll();
		
		//updateAll();

		//cleardevice();
		//drawAll();
		//FlushBatchDraw();

		//Sleep(TICK_TIME);
		
		
	}



	
    EndBatchDraw(); // ������������
	closegraph();
}
#pragma endregion

int main() {
	loadAllImages(); // ��������ͼƬ
	addMaps();
	initLevelInfoMap();
	while (currentGameState != GameState::EXIT) {
		ShowStartScene(); // ��ʾ��ʼ�˵�����
		ShowPlayingScene(); // ��ʾ��Ϸ����
		ShowResultScene(); // ��ʾ���㳡��
		
	}
	return 0;
}