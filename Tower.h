#pragma once
#ifndef TOWER_H
#define TOWER_H

#include "Constant.h"


static int TowerId = 0;
class Tower
{
public:
	int id; // ����id,Ψһ��ʶ��
	TowerType type; // ��������
	//- λ�����
	float x, y; // ������������
	int row, col; // �����ڵ��к���
	float width = 62, height = 62; // ���Ŀ��
	//- �������
	int aniCount = 0;
	int aniId = 0;
	//- ��������
	int heart = 5; // ʣ��Ѫ��
	int currentGrade = 1;// ��ǰ�ȼ�
	float speed = 0.5; // ���Ĺ����ٶ�/�ӽ�ҵ��ٶȣ���λ����/��
	int upgradeCost = 10; // ��������
	std::vector<IMAGE> ims_tower; // ����ͼƬ
	//- ��������
	int shootCount = 0;
	float attckRange = 150; // ������Χ
	//- �������
	int coinPerSecond = 1; // ÿ������������
	// ���캯��
	Tower(TowerType type, Coordinate coordinate);
	// ����
	void draw();
	// ����
	void update();
	// ���
	void Shoot();
	// 
	void addCoin();
};
#endif // !TOWER_H


