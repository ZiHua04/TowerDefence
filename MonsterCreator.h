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
	bool isStart = false; // �Ƿ�ʼ����
	
public:
	bool isWaving = false; // �Ƿ����ڹ����
	double totalTime; // ��Ҫ���ɵ���ʱ��
	double startTime; // ��ʼʱ��
	double runTime; // ��������ʱ��
	double lastCreateTime;
	float waveTimes[3]; // ÿ�����ε�ʱ��
	float diffRate; // �Ѷȱ��ʣ���ÿ�������ɵĹ��
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



