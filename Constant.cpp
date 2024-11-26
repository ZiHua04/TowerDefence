#include "Constant.h"

std::map<MonsterType, std::vector<IMAGE>> ims_w;
std::map<MonsterType, std::vector<IMAGE>> ims_a;
std::map<MonsterType, std::vector<IMAGE>> ims_s;
std::map<MonsterType, std::vector<IMAGE>> ims_d;

void addMaps() {
    ims_w.insert(std::pair<MonsterType, std::vector<IMAGE>>(MonsterType::Goblin, ims_monster_w));
    ims_a.insert(std::pair<MonsterType, std::vector<IMAGE>>(MonsterType::Goblin, ims_monster_a));
    ims_s.insert(std::pair<MonsterType, std::vector<IMAGE>>(MonsterType::Goblin, ims_monster_s));
    ims_d.insert(std::pair<MonsterType, std::vector<IMAGE>>(MonsterType::Goblin, ims_monster_d));
}



std::map<MonsterType, MonsterInfo> monsterInfo = {
    {MonsterType::Goblin, {20, 1, 5, 47, 56}},
    {MonsterType::Bee, {10, 1, 10, 47, 56}},
    {MonsterType::Dog, {5, 1, 10, 47, 56}}
};

std::vector<IMAGE> getImagesByTypeAndDirection(MonsterType type, char direction) {
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
        break;
    default:
        break;
    }
}