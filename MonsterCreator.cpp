#include "MonsterCreator.h"
#include "Constant.h"
#include <ctime>
#include "EasyXPng.h"
#include "Monster.h"
#include "Toolkit.h"
#include "Global.h"
#include <cmath>
#include <thread>
MonsterCreator::MonsterCreator(double totalTime, std::array<double, 3> waveTimes)
{
	this->startTime = -1;
	this->runTime = -1;
	this->lastCreateTime = 0;
	this->totalTime = totalTime;
	
	float waveX[3];
	for (int i = 0; i < 3; i++) {
		this->waveTimes[i] = waveTimes[i];
		waveX[i] = BLOCK_WIDTH * 2 * waveTimes[i] / totalTime;
	}
	this->slider = new Slider(BLOCK_WIDTH, 20, BLOCK_WIDTH * 2, 20, waveX);
}

void MonsterCreator::update()
{
	if (!isStart) return;
	draw();
	this->runTime = (clock() - startTime) / CLOCKS_PER_SEC;
	if (this->runTime > this->totalTime) {
		isStart = false;
		return;
	}
	// 线性生成
	linearCreate();
	// 波次生成
	waveCreate();
	// 改变难度系数
	this->diffRate = 0.1 * pow(10, this->runTime / this->totalTime);
}

void MonsterCreator::draw()
{
	this->slider->currentX = slider->x + slider->width * runTime / totalTime;
	this->slider->draw();
	settextcolor(BLACK);
	std::string str = std::to_string(this->diffRate);
	str = str.substr(0, str.find('.') + 3);  // 保留两位小数
	drawText("难度系数：" + str, slider->x, slider->y + slider->height);

	// 绘制警告图片
	if (this->isWaving) {
		putimagePng(WIDHT / 2 - im_ui_warning.getwidth() / 2, HEIGHT / 2 - im_ui_warning.getheight() / 2, &im_ui_warning);
		settextcolor(RED);
		drawText("怪物狂潮来袭", WIDHT / 2 - 3 * 40, HEIGHT / 2 + im_ui_warning.getheight() / 2, 40);
	}
}

void MonsterCreator::startCreate()
{
	startTime = clock();
	isStart = true;
}

void MonsterCreator::linearCreate()
{
	if (this->runTime - this->lastCreateTime >= 1.0f / diffRate) {
		randomCreate();
		this->lastCreateTime = this->runTime;
	}
}

void MonsterCreator::waveCreate()
{
	for (int i = 0; i < 3; i++) {
		if (this->runTime > this->waveTimes[i] && this->runTime < this->waveTimes[i] + 1) {
			if (isWaving) return;
			isWaving = true;
			waveThread();
		}
	}
}

void MonsterCreator::waveThread() {
	std::thread([this]() {
		for (int i = 0; i < 5; i++) {
			if (this == nullptr) return;
			this->randomCreate();
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
			setfillcolor(RED);
			fillrectangle(0, 0, WIDHT, HEIGHT);
		}
		this->isWaving = false;
		}).detach();
}

void MonsterCreator::randomCreate()
{
	// 按7:2:1的概率生成哥布林，地狱犬，邪恶蜜蜂
	if (getRate(0.7)) {
		monsters.push_back(new Monster(MonsterType::Goblin, Coordinate(6, 1)));
	}
	else if (getRate(2.0 / 3)) {
		monsters.push_back(new Monster(MonsterType::Dog, Coordinate(6, 1)));
	}
	else {
		monsters.push_back(new Monster(MonsterType::Bee, Coordinate(6, 1)));
	}
}

Slider::Slider(float x, float y, float width, float height, float waveX[3])
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->currentX = x;
	for (int i = 0; i < 3; i++) {
		this->waveX[i] = waveX[i] + this->x;
	}
}

void Slider::draw()
{
	
	setfillcolor(RED);
	fillrectangle(currentX, y, x + width, y + height);

	for (int i = 0; i < 3; i++) {
		putimagePng(waveX[i], this->y, &im_ui_waveflag);
	}

	setfillcolor(GREEN);
	fillrectangle(x, y, currentX, y + height);

	putimagePng(this->x + this->width, this->y - this->height/2, &im_ui_bossflag);
}
