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

constexpr float TICK_TIME = 5.0;
// 0:�յ� 1:��·
extern int roadMap[ROW][COL];
// 0:�յ� -1:�ɽ���
extern int towerMap[ROW][COL];

// ======= ͼƬ =======
extern std::map<MonsterType, std::vector<IMAGE>> ims_w;
extern std::map<MonsterType, std::vector<IMAGE>> ims_a;
extern std::map<MonsterType, std::vector<IMAGE>> ims_s;
extern std::map<MonsterType, std::vector<IMAGE>> ims_d;

void addMaps();

std::vector<IMAGE> getImagesByTypeAndDirection(MonsterType type, char direction, bool isAngry = false);

std::vector<IMAGE> getTowerImages(TowerType type, int grade);

// ======= ����ṹ =======
struct Coordinate {
	int row = -1;
	int col = -1;

	Coordinate() = default;
	Coordinate(int r, int c) : row(r), col(c) {}
	bool operator<(const Coordinate& other) const {
		if (row == other.row) {
			return col < other.col;  // ��� x ��ͬ���Ƚ� y
		}
		return row < other.row;  // �Ƚ� x
	}
	bool operator==(const Coordinate& other) const {
		return (row == other.row && col == other.col);
	}
};

// ======= �ؿ���Ϣ =======
struct LevelInfo {
public:
	LevelInfo();
	LevelInfo(IMAGE im_bk, int towerMap[ROW][COL], int roadMap[ROW][COL], Coordinate monsterBirthCoordinate
		, double totalTime, double waveTimes[3], float minDiffRate, float maxDiffRate);
	IMAGE im_bk; // ����ͼƬ
	int towerMap[ROW][COL]; // ���Խ����ĵط�
	int roadMap[ROW][COL]; // ��·
	Coordinate monsterBirthCoordinate; // ���������
	double totalTime; // ��Ϸ��ʱ��
	double waveTimes[3]; // ����ʱ��
	float minDiffRate; // ��С�Ѷ�ϵ��
	float maxDiffRate; // ����Ѷ�ϵ��
};

// �ؿ����ݱ�
extern std::map<int, LevelInfo> levelInfoMap;
// ��ʼ���ؿ����ݱ�
extern void initLevelInfoMap();

// ======= ������Ϣ =======
struct MonsterInfo {
	int heart;
	float speed;
	int coin;
	float im_width;
	float im_height;
};
// ======= ������Ϣ =======
struct TowerInfo {
	int heart;
	float speed;
	int upgradeCost;
	float attackRange;
	int coinPerSecond;
};

extern std::map<MonsterType, MonsterInfo> monsterInfo;

extern std::map<int, TowerInfo> towerInfo;



#endif // CONSTANT_H
