#pragma once
#ifndef _GLOBAL_H_
#define _GLOBAL_H_

#include <map>
#include "Monster.h"
#include "ClickButton.h"
#include "Tower.h"
#include "Bullet.h"
#include "CoinSystem.h"
#include "VFXSystem.h"
#include "EnemyBullet.h"
#include "PropSystem.h"
#include "MonsterCreator.h"
#include "AudioSystem.h"

extern int currentLevel;

extern GameState currentGameState;

extern ExMessage m;

// 怪物
extern std::vector<Monster*> monsters;
// 升级按钮
extern ClickButton* clickButton;
// 塔
extern std::map<Coordinate, Tower*> towers;
// 子弹
extern std::vector<Bullet*> bullets;
// 敌人子弹
extern std::vector<EnemyBullet*> enemyBullets;
// 金币系统
extern CoinSystem* coinSystem;
// 特效系统
extern VFXSystem* vfxSystem;
// 道具系统
extern PropSystem* propSystem;
// 怪物生产器
extern MonsterCreator* monsterCreator;
// 音效系统
extern AudioSystem* audioSystem;
// 摧毁怪物
void destoryMonsterById(int id);
// 摧毁子弹
void destoryBulletById(int id);
// 销毁敌人子弹
void destoryEnemyBulletById(int id);
// 摧毁塔
void destoryTowerById(int id);

#endif // _GLOBAL_H_