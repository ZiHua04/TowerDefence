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
	int heart; // ʣ��Ѫ��
	int currentGrade;// ��ǰ�ȼ�
	float speed; // ���Ĺ����ٶ�/�ӽ�ҵ��ٶȣ���λ����/��
	int upgradeCost; // ��������
	std::vector<IMAGE> ims_tower; // ����ͼƬ
	//- ��������
	int shootCount = 0;
	float attckRange; // ������Χ
	//- �������
	int coinPerSecond; // ÿ������������
	// ���캯��
	Tower(TowerType type, Coordinate coordinate);
	// ����
	void draw();
	// ����
	void update();
	// ���
	void Shoot();
	// ��Ǯ
	void addCoin();
	// ����
	void upgrade();
	// ����������Ϣ
	void loadTowerInfo();
	// ��Ѫ
	void subHeart(int value);
};
#endif // !TOWER_H


