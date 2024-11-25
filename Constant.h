#pragma once
#ifndef CONSTANT_H
#define CONSTANT_H

#include <map>
#include <vector>
#include "Enum.h"
#include "Images.h"

// ======= �������� =======
constexpr int WIDHT = 1056;
constexpr int HEIGHT = 672;
constexpr int ROW = 7;
constexpr int COL = 11;

constexpr int BLOCK_WIDTH = 96;
constexpr int BLOCK_HEIGHT = 96;

constexpr float MONSTER_WIDTH = 47;
constexpr float MONSTER_HEIGHT = 56;
constexpr float MONSTER_BLOCK_TIME = 200;  // ÿ1s�ƶ�һ��
constexpr float MONSTER_V = BLOCK_WIDTH / MONSTER_BLOCK_TIME;

constexpr int TOWER_WIDTH = 62;
constexpr int TOWER_HEIGHT = 61;

constexpr int ANI_MAX_COUNT = 10;  // ���������ٶ�
constexpr int GAME_TIME = 120;     // ��Ϸʱ��

const int roadMap[ROW][COL] = {
	{0,0,0,0,0,1,0,0,0,0,0},
	{0,1,1,1,0,1,1,1,1,1,0},
	{0,1,0,1,0,0,0,0,0,1,0},
	{0,1,0,1,0,0,0,0,0,1,0},
	{0,1,0,1,0,0,0,0,0,1,0},
	{0,1,0,1,1,1,1,1,1,1,0},
	{0,1,0,0,0,0,0,0,0,0,0},
};
extern int towerMap[ROW][COL];

// ======= ͼƬ =======
extern std::map<MonsterType, std::vector<IMAGE>> ims_w;
extern std::map<MonsterType, std::vector<IMAGE>> ims_a;
extern std::map<MonsterType, std::vector<IMAGE>> ims_s;
extern std::map<MonsterType, std::vector<IMAGE>> ims_d;

void addMaps();

std::vector<IMAGE> getImagesByTypeAndDirection(MonsterType type, char direction);

// ======= ������Ϣ =======
struct MonsterInfo {
    int heart;
    float speed;
    int coin;
    float im_width;
    float im_height;
};

extern std::map<MonsterType, MonsterInfo> monsterInfo;

// ======= ����ṹ =======
struct Coordinate {
    int row = -1;
    int col = -1;

    Coordinate() = default;
    Coordinate(int r, int c) : row(r), col(c) {}
};

#endif // CONSTANT_H