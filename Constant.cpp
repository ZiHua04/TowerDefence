#include "Constant.h"

std::map<MonsterType, std::vector<IMAGE>> ims_w;
std::map<MonsterType, std::vector<IMAGE>> ims_a;
std::map<MonsterType, std::vector<IMAGE>> ims_s;
std::map<MonsterType, std::vector<IMAGE>> ims_d;

void addMaps() {
    // ∏Á≤º¡÷
    ims_w.insert(std::pair<MonsterType, std::vector<IMAGE>>(MonsterType::Goblin, ims_monster_w));
    ims_a.insert(std::pair<MonsterType, std::vector<IMAGE>>(MonsterType::Goblin, ims_monster_a));
    ims_s.insert(std::pair<MonsterType, std::vector<IMAGE>>(MonsterType::Goblin, ims_monster_s));
    ims_d.insert(std::pair<MonsterType, std::vector<IMAGE>>(MonsterType::Goblin, ims_monster_d));

    // –∞∂Ò√€∑‰
    ims_w.insert(std::pair<MonsterType, std::vector<IMAGE>>(MonsterType::Bee, ims_bee_w));
    ims_a.insert(std::pair<MonsterType, std::vector<IMAGE>>(MonsterType::Bee, ims_bee_a));
    ims_s.insert(std::pair<MonsterType, std::vector<IMAGE>>(MonsterType::Bee, ims_bee_s));
    ims_d.insert(std::pair<MonsterType, std::vector<IMAGE>>(MonsterType::Bee, ims_bee_d));
    // µÿ”¸»Æ
    ims_w.insert(std::pair<MonsterType, std::vector<IMAGE>>(MonsterType::Dog, ims_dog_w));
    ims_a.insert(std::pair<MonsterType, std::vector<IMAGE>>(MonsterType::Dog, ims_dog_a));
    ims_s.insert(std::pair<MonsterType, std::vector<IMAGE>>(MonsterType::Dog, ims_dog_s));
    ims_d.insert(std::pair<MonsterType, std::vector<IMAGE>>(MonsterType::Dog, ims_dog_d));
}



std::map<MonsterType, MonsterInfo> monsterInfo = {
    {MonsterType::Goblin, {20, 1, 5, 47, 56}},
    {MonsterType::Bee, {10, 0.5, 10, 47, 56}},
    {MonsterType::Dog, {5, 3, 10, 47, 56}}
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
        if (grade == 1) return ims_coinTower1;
        if (grade == 2) return ims_coinTower2;
        if (grade == 3) return ims_coinTower3;
        break;
    default:
        break;
    }
    return ims_tower1;
}