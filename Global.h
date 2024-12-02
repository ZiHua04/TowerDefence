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
// 摧毁怪物
void destoryMonsterById(int id);
// 摧毁子弹
void destoryBulletById(int id);
// 销毁敌人子弹
void destoryEnemyBulletById(int id);
// 摧毁塔
void destoryTowerById(int id);

#endif // _GLOBAL_H_