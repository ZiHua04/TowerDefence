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
// ����
extern std::vector<Monster*> monsters;
// ������ť
extern ClickButton* clickButton;
// ��
extern std::map<Coordinate, Tower*> towers;
// �ӵ�
extern std::vector<Bullet*> bullets;
// �����ӵ�
extern std::vector<EnemyBullet*> enemyBullets;
// ���ϵͳ
extern CoinSystem* coinSystem;
// ��Чϵͳ
extern VFXSystem* vfxSystem;
// �ݻٹ���
void destoryMonsterById(int id);
// �ݻ��ӵ�
void destoryBulletById(int id);
// ���ٵ����ӵ�
void destoryEnemyBulletById(int id);
// �ݻ���
void destoryTowerById(int id);

#endif // _GLOBAL_H_