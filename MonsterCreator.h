#pragma once
#ifndef MONSTERCREATOR_H
#define MONSTERCREATOR_H

#include <array>

struct Slider
{
public:
	Slider(float x, float y, float width, float height, float waveX[3]);
	float x, y;
	float width, height;
	float currentX;
	float waveX[3];
	void draw();
};

class MonsterCreator
{
private:
	Slider* slider;
	bool isStart = false; // 是否开始生成
	
public:
	bool isWaving = false; // 是否正在怪物狂潮
	double totalTime; // 需要生成的总时间
	double startTime; // 开始时间
	double runTime; // 本关游玩时间
	double lastCreateTime;
	float waveTimes[3]; // 每个波次的时间
	float diffRate; // 难度倍率，及每秒钟生成的怪物。
	float maxDiffRate;

	int maxEnterMonster;
	int currentEnterMonster;

	MonsterCreator();
	void update();
	void draw();
	void startCreate();
	void linearCreate();
	void waveCreate();
	void waveThread();
	void randomCreate();
};

#endif // !MONSTERCREATOR_H



