
#include "Images.h"
#include "Constant.h"
#include "Toolkit.h"
#include <conio.h>
#include "Monster.h"
std::vector<Monster*> monsters;

// 初始化一把游戏
void init() {
	initgraph(WIDHT, HEIGHT); // 初始化图形窗口
}
// 处理鼠标和键盘输入
void input() {

}
// 处理所有碰撞事件
void detectAll() {

}

int tempSecondCount = 0;
// 更新每秒
void updatePerSecond() {
	monsters.push_back(new Monster(MonsterType::Goblin, Coordinate(6, 1)));
	
}
// 更新所有游戏对象
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
// 绘制所有游戏对象
void drawAll() {
	putimage(0, 0, &im_bk); // 绘制背景
	for (int i = 0; i < monsters.size(); i++) {
		monsters[i]->draw();
	}
}
GameState currentGameState = GameState::START_SCENE;
#pragma region 开始界面，暂时用不到
// 显示开始菜单界面
void ShowStartScene() {
	initgraph(WIDHT, HEIGHT); // 初始化图形窗口
	while (currentGameState == GameState::START_SCENE) {

		drawText("这是开始界面", WIDHT / 2, HEIGHT / 2, 40);
		drawText("按任意键开始游戏", WIDHT / 2, HEIGHT / 2 + 50, 30);
		if (_getch() == ' ') {
			currentGameState = GameState::PLAYING;
		};
	}
	closegraph();
}
#pragma endregion

#pragma region 结算界面，暂时用不到
// 显示结算场景
void ShowResultScene() {
	initgraph(WIDHT, HEIGHT); // 初始化图形窗口
	while (currentGameState == GameState::WIN || currentGameState == GameState::LOSE) {
		
		drawText("这是结算界面", WIDHT / 2, HEIGHT / 2, 40);
		drawText("按任意键重启游戏", WIDHT / 2, HEIGHT / 2 + 50, 30);
		if (_getch() == ' ') {
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
	BeginBatchDraw(); // 开始批量绘制
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
    EndBatchDraw(); // 结束批量绘制
	closegraph();
}
#pragma endregion

int main() {
	loadAllImages(); // 加载所有图片
	addMaps();
	while (currentGameState != GameState::EXIT) {
		ShowStartScene(); // 显示开始菜单界面
		ShowPlayingScene(); // 显示游戏界面
		ShowResultScene(); // 显示结算场景
		
	}
	return 0;
}