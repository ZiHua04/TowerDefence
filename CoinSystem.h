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
	int currentCoin = 0;
public:
	CoinSystem();
	std::vector<TextWithPos> texts;
	void addCoin(int value, float x, float y);
	bool subCoin(int value);
	int getCoin();
	void draw();
	void update();
	
};


#endif // !COINSYSTEM_H






