#pragma once
#ifndef COINSYSTEM_H
#define COINSYSTEM_H

#include <map>
#include <string>
#include <vector>

struct TextWithPos
{
public:
	float x;
	float y;
	std::string text;
	int counter = 50;
};

class CoinSystem
{
private:
	int currentCoin = 0; // ��ʼ���
public:
	std::vector<TextWithPos> texts; // ��������ʾ�ļӽ������

	CoinSystem(); // ���캯��
	
	void addCoin(int value, float x, float y); // �ӽ��
	bool subCoin(int value); // ����ң������Ҳ�������false
	int getCoin(); // ��ѯ��ǰ���
	void draw(); // ����
	void update(); // ����
	
};


#endif // !COINSYSTEM_H






