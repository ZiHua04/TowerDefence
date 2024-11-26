#pragma once
#ifndef _GLOBAL_H_
#define _GLOBAL_H_

#include <map>
#include "Monster.h"
#include "ClickButton.h"
#include "Tower.h"
#include "Bullet.h"
// ����
extern std::vector<Monster*> monsters;
// ������ť
extern ClickButton* clickButton;
// ��
extern std::map<Coordinate, Tower*> towers;
// �ӵ�
extern std::vector<Bullet*> bullets;
// �ݻٹ���
void destoryMonsterById(int id);
// �ݻ��ӵ�
void destoryBulletById(int id);

#endif // _GLOBAL_H_