#include "Constant.h"
#include "Global.h"
std::map<MonsterType, std::vector<IMAGE>> ims_w;
std::map<MonsterType, std::vector<IMAGE>> ims_a;
std::map<MonsterType, std::vector<IMAGE>> ims_s;
std::map<MonsterType, std::vector<IMAGE>> ims_d;

int roadMap[ROW][COL];
int towerMap[ROW][COL];


void addMaps() {
    // 哥布林
    ims_w.insert(std::pair<MonsterType, std::vector<IMAGE>>(MonsterType::Goblin, ims_monster_w));
    ims_a.insert(std::pair<MonsterType, std::vector<IMAGE>>(MonsterType::Goblin, ims_monster_a));
    ims_s.insert(std::pair<MonsterType, std::vector<IMAGE>>(MonsterType::Goblin, ims_monster_s));
    ims_d.insert(std::pair<MonsterType, std::vector<IMAGE>>(MonsterType::Goblin, ims_monster_d));

    // 邪恶蜜蜂
    ims_w.insert(std::pair<MonsterType, std::vector<IMAGE>>(MonsterType::Bee, ims_bee_w));
    ims_a.insert(std::pair<MonsterType, std::vector<IMAGE>>(MonsterType::Bee, ims_bee_a));
    ims_s.insert(std::pair<MonsterType, std::vector<IMAGE>>(MonsterType::Bee, ims_bee_s));
    ims_d.insert(std::pair<MonsterType, std::vector<IMAGE>>(MonsterType::Bee, ims_bee_d));
    // 地狱犬
    ims_w.insert(std::pair<MonsterType, std::vector<IMAGE>>(MonsterType::Dog, ims_dog_w));
    ims_a.insert(std::pair<MonsterType, std::vector<IMAGE>>(MonsterType::Dog, ims_dog_a));
    ims_s.insert(std::pair<MonsterType, std::vector<IMAGE>>(MonsterType::Dog, ims_dog_s));
    ims_d.insert(std::pair<MonsterType, std::vector<IMAGE>>(MonsterType::Dog, ims_dog_d));

}



std::map<MonsterType, MonsterInfo> monsterInfo = {
    {MonsterType::Goblin, {20, 1, 5, 47, 56}},
    {MonsterType::Bee, {10, 0.5, 10, 47, 56}},
    {MonsterType::Dog, {5, 3, 10, 47, 56}},
    {MonsterType::Boss, {100, 1, 100, 192, 112}}
};
std::map<int, TowerInfo> towerInfo = {
    {1, {5, 0.5, 10, 150, 1}},
    {2, {10, 0.3, 20, 200, 1}},
    {3, {20, 0.2, 40, 220, 1}}
};

std::vector<IMAGE> getImagesByTypeAndDirection(MonsterType type, char direction, bool isAngry) {
    if (type == MonsterType::Boss) {
        if (isAngry) {
            switch (direction)
            {
            case 'd': return ims_boss_d_fly;
            case 'a': return ims_boss_a_fly;
            }
        }
        else{
            switch (direction)
            {
            case 'd': return ims_boss_d_walk;
            case 'a': return ims_boss_a_walk;
            }
        }
        return ims_boss_d_walk;
    }
    switch (direction) {
        case 'w': return ims_w[type];
        case 'a': return ims_a[type];
        case 's': return ims_s[type];
        case 'd': return ims_d[type];
    }
    return ims_w[type];
}

std::vector<IMAGE> getTowerImages(TowerType type, int grade) {
    switch (type)
    {
    case TowerType::Attack:
        if(grade == 1) return ims_tower1;
        if(grade == 2) return ims_tower2;
        if(grade == 3) return ims_tower3;
        break;
    case TowerType::Coin:
        if (grade == 1) return ims_coinTower1;
        if (grade == 2) return ims_coinTower2;
        if (grade == 3) return ims_coinTower3;
        break;
    default:
        break;
    }
    return ims_tower1;
}

// 关卡数据表
std::map<int, LevelInfo> levelInfoMap;

void initLevelInfoMap()
{
    // 第一关
    IMAGE im = im_bk;
    int towerMap1[ROW][COL] = {
        {0,-1,-1,-1,-1,-1,-1,-1,-1,0,-1},
        {-1,-1,-1,-1,0,-1,-1,-1,-1,-1,-1},
        {-1,-1,0,-1,-1,0,-1,-1,0,-1,-1},
        {-1,-1,-1,-1,0,-1,-1,-1,-1,-1,-1},
        {0,-1,-1,-1,-1,-1,-1,-1,0,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,0,-1,-1,0,-1,-1,-1,-1},
    };
    int roadMap1[ROW][COL] = {
        {0,0,0,0,0,1,0,0,0,0,0},
        {0,1,1,1,0,1,1,1,1,1,0},
        {0,1,0,1,0,0,0,0,0,1,0},
        {0,1,0,1,0,0,0,0,0,1,0},
        {0,1,0,1,0,0,0,0,0,1,0},
        {0,1,0,1,1,1,1,1,1,1,0},
        {0,1,0,0,0,0,0,0,0,0,0},
    };
    Coordinate coordinate = Coordinate(6, 1);
    double totalTime = 120;
    double waveTime[3] = { 30,60,100 };
    float minDiffRate = 0.1;
    float maxDiffRate = 1;
    LevelInfo info1 = LevelInfo(im, towerMap1, roadMap1, coordinate, totalTime, waveTime, minDiffRate, maxDiffRate);
    levelInfoMap.insert(std::make_pair(0, info1));
    // 第二关
    im = im_bk2;
    int towerMap2[ROW][COL] = {
        {-1,-1,-1,-1,0,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,0,-1,-1,-1,0},
        {0,-1,-1,-1,0,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,0,-1,-1,-1,-1},
        {-1,-1,0,-1,-1,-1,0,-1,-1,-1,0},
        {-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1},
        {-1,-1,-1,0,-1,-1,-1,-1,-1,-1,-1},
    };
    int roadMap2[ROW][COL] = {
        {0,0,0,0,0,0,0,0,0,0,0},
        {1,1,0,1,1,1,0,1,1,1,0},
        {0,1,0,1,0,1,0,1,0,1,0},
        {0,1,0,1,0,1,0,1,0,1,0},
        {0,1,0,1,0,1,0,1,0,1,0},
        {0,1,1,1,0,1,1,1,0,1,1},
        {0,0,0,0,0,0,0,0,0,0,0},
    };
    coordinate = Coordinate(1, 0);
    totalTime = 180;
    waveTime[0] = 40;
    waveTime[1] = 100;
    waveTime[2] = 150;
    minDiffRate = 0.4;
    maxDiffRate = 1.0;
    LevelInfo info2 = LevelInfo(im, towerMap2, roadMap2, coordinate, totalTime, waveTime, minDiffRate, maxDiffRate);
    levelInfoMap.insert(std::make_pair(1, info2));
    // 第三关
    im = im_bk3;
    int towerMap3[ROW][COL] = {
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,0,-1,-1,-1,0,-1,-1},
        {-1,-1,0,-1,-1,-1,0,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0},
        {-1,-1,0,-1,0,-1,0,-1,0,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,0,-1,-1,-1,-1,-1,-1},
    };
    int roadMap3[ROW][COL] = {
        {0,0,0,0,0,0,0,0,0,1,0},
        {0,1,1,1,0,1,1,1,0,1,0},
        {0,1,0,1,0,1,0,1,0,1,0},
        {0,1,0,1,1,1,0,1,0,1,0},
        {0,1,0,0,0,0,0,1,0,1,0},
        {0,1,1,1,1,1,0,1,1,1,0},
        {0,0,0,0,0,1,0,0,0,0,0},
    };
    coordinate = Coordinate(6, 5);
    totalTime = 200;
    waveTime[0] = 40;
    waveTime[1] = 120;
    waveTime[2] = 160;
    minDiffRate = 0.5;
    maxDiffRate = 1.0;
    LevelInfo info3 = LevelInfo(im, towerMap3, roadMap3, coordinate, totalTime, waveTime, minDiffRate, maxDiffRate);
    levelInfoMap.insert(std::make_pair(2, info3));

}

LevelInfo::LevelInfo()
{
}

LevelInfo::LevelInfo(IMAGE im_bk, int towerMap[ROW][COL], int roadMap[ROW][COL], Coordinate monsterBirthCoordinate,
    double totalTime, double waveTimes[3], float minDiffRate, float maxDiffRate)
{
    this->im_bk = im_bk;
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            this->towerMap[i][j] = towerMap[i][j];
            this->roadMap[i][j] = roadMap[i][j];
        }
    }
    this->monsterBirthCoordinate = monsterBirthCoordinate;
    this->totalTime = totalTime;
    for (int i = 0; i < 3; i++) {
        this->waveTimes[i] = waveTimes[i];
    }
    this->minDiffRate = minDiffRate;
    this->maxDiffRate = maxDiffRate;

}
