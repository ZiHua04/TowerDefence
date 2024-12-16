
#include "Images.h"
#include "Constant.h"
#include "Toolkit.h"
#include <conio.h>
#include "Global.h"
#include "FrontPage.h"
#include <thread>


// 初始化一把游戏
void init() {
	initgraph(WIDHT, HEIGHT); // 初始化图形窗口
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			roadMap[i][j] = levelInfoMap[currentLevel].roadMap[i][j];
			towerMap[i][j] = levelInfoMap[currentLevel].towerMap[i][j];
		}
	}

	monsterCreator = new MonsterCreator();
	monsterCreator->startCreate();
}

// 处理鼠标和键盘输入
void input() {
	if (!peekmessage(&m)) return;
	// 获取一条鼠标或按键消息
	switch (m.message)
	{
	case WM_LBUTTONDOWN:
		float x = m.x;
		float y = m.y;
		int col = x / BLOCK_WIDTH;
		int row = y / BLOCK_HEIGHT;
		if (col < 0 || col >= COL || row < 0 || row >= ROW) return;
		if (propSystem->click(x, y)) return;
		//currentGameState = GameState::WIN;
		clickButton->clickCoordinate(Coordinate(row, col));
		break;
	}
	
}
// 处理所有碰撞事件
void detectAll() {
	// 处理子弹和怪物
	for (int i = 0; i < bullets.size(); i++) {
		for (int j = 0; j < monsters.size(); j++) {
			Bullet* bullet = bullets[i];
			Monster* monster = monsters[j];
			if (DetectTwoRectangle(bullet->x, bullet->y, monster->x-monster->width/2, monster->y-monster->heart/2, bullet->width, bullet->height, monster->width, monster->height)) {
				destoryBulletById(bullet->id);// 销毁子弹
				
				monster->subHeart(1); // 减少生命值
				return;
			}
		}
	}
	// 处理敌人子弹和塔
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

				// 播放特效
				vfxSystem->PlayVFX(enemyBullets[i]->x, enemyBullets[i]->y, VFXType::Hit);// 播放特效
				// 减少生命值
				iter->second->subHeart(1);
				// 销毁子弹
				destoryEnemyBulletById(enemyBullets[i]->id);
				return;
			}
		}
	}
}

int tempSecondCount = 0;
// 更新每秒
void updatePerSecond() {




}
// 更新所有游戏对象
void updateAll() {


	for (int i = 0; i < monsters.size(); i++) {
		monsters[i]->update();
		
	}

	for (const auto& pair : towers) {
		// pair.first 是键 (Coordinate)， pair.second 是值 (Tower*)
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
// 绘制所有游戏对象
void drawAll() {
	putimage(0, 0, &levelInfoMap[currentLevel].im_bk); // 绘制背景
	// 绘制怪物
	for (int i = 0; i < monsters.size(); i++) {
		monsters[i]->draw();
	}
	// 绘制塔
	for (const auto& pair : towers) {
		// pair.first 是键 (Coordinate)， pair.second 是值 (Tower*)
		pair.second->draw();
	}
	// 绘制子弹
	for (int i = 0; i < bullets.size(); i++) {
		bullets[i]->draw();
	}
	for (int i = 0; i < enemyBullets.size(); i++) {
		enemyBullets[i]->draw();
	}
	// 绘制ClickButton
	clickButton->draw();
	// 绘制金币
	coinSystem->draw();
	// 绘制特效
	vfxSystem->draw();
	// 绘制道具
	propSystem->draw();
	// 绘制怪物生成
	monsterCreator->draw();
	
}

#pragma region 开始界面
// 显示开始菜单界面
void ShowStartScene() {
	audioSystem->playBGM();
	initgraph(WIDHT, HEIGHT); // 初始化图形窗口
	BeginBatchDraw(); // 开始批量绘制
	while (currentGameState == GameState::START_SCENE) {
		// 检测输入
		frontPageInput();
		/*drawText("这是开始界面", WIDHT / 2, HEIGHT / 2, 40);
		drawText("按空格键开始游戏", WIDHT / 2, HEIGHT / 2 + 50, 30);*/
		putimage(0, 0, &im_front_bk);
		/*if (_getch() == ' ') {
			currentGameState = GameState::PLAYING;
		};*/
		frontPageDraw();
		Sleep(5);
	}
	EndBatchDraw(); // 结束
	closegraph();
}
#pragma endregion

#pragma region 结算界面
// 显示结算场景
void ShowResultScene() {

	IMAGE im_res;
	loadimage(&im_res, _T("res/images/result.png"), WIDHT * 0.6, HEIGHT * 0.6);
	initgraph(WIDHT, HEIGHT); // 初始化图形窗口
	if (currentGameState == GameState::WIN) {
		audioSystem->playAudio(AudioType::Cheer);
		audioSystem->playAudio(AudioType::Clap);
	}
	else {
		audioSystem->playAudio(AudioType::Lose);
	}
	while (currentGameState == GameState::WIN || currentGameState == GameState::LOSE) {
		putimage(0, 0, &im_result);
		putimage(WIDHT / 2 - im_res.getwidth() / 2, HEIGHT / 2 - im_res.getheight() / 2, &im_res);
		if (currentGameState == GameState::WIN) {
			settextcolor(RGB(255, 69, 0));
			drawText("恭喜您，游戏胜利", WIDHT / 2 - 4 * 40, HEIGHT / 2 + im_res.getheight() / 2, 40);
		}
		else {
			settextcolor(RGB(139, 0, 0));
			drawText("很遗憾，游戏失败", WIDHT / 2 - 4 * 40, HEIGHT / 2 + im_res.getheight() / 2, 40);
		}
		
		if (_getch()) {
			currentGameState = GameState::START_SCENE;
		};
	}
	closegraph();
}
#pragma endregion

#pragma region 游戏中界面
// 显示游戏界面
void ShowPlayingScene() {
	init();// 初始化游戏资源
	audioSystem->playBGM(currentLevel);
	audioSystem->playAudio(AudioType::GameStart);
	BeginBatchDraw(); // 开始批量绘制
	// 输入进程
	std::thread([]() {
		while (currentGameState == GameState::PLAYING)
		{
			input();
			std::this_thread::sleep_for(std::chrono::milliseconds((int)TICK_TIME));
		}

		}).detach();
	// 碰撞检测进程
	/*std::thread([]() {
		while (currentGameState == GameState::PLAYING)
		{
			detectAll();
			std::this_thread::sleep_for(std::chrono::milliseconds(5));
		}

		}).detach();*/
	// 更新进程
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



	
    EndBatchDraw(); // 结束批量绘制
	IMAGE im_res;
	getimage(&im_res, 0, 0, WIDHT, HEIGHT);
	saveimage(_T("res/images/result.png", &im_res));
	closegraph();
	clearData();
}
#pragma endregion

int main() {
	loadAllImages(); // 加载所有图片
	addMaps();
	initLevelInfoMap();
	while (currentGameState != GameState::EXIT) {
		ShowStartScene(); // 显示开始菜单界面
		ShowPlayingScene(); // 显示游戏界面
		ShowResultScene(); // 显示结算场景
		
	}
	return 0;
}