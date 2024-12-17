#pragma once
#ifndef IMAGES_H
#define IMAGES_H

#include <vector>
#include <graphics.h>
// ��ҳ����ͼƬ
extern IMAGE im_front_bk;
// �ؿ�ͼƬ
extern IMAGE im_front_level;

extern IMAGE im_bk;// ����ͼƬ

extern IMAGE im_bk2; // ����ͼƬ2
extern IMAGE im_bk3; // ����ͼƬ3

// ����ͼƬ
extern std::vector<IMAGE> ims_monster_w;
extern std::vector<IMAGE> ims_monster_a;
extern std::vector<IMAGE> ims_monster_s;
extern std::vector<IMAGE> ims_monster_d;
// ����ȮͼƬ
extern std::vector<IMAGE> ims_dog_w;
extern std::vector<IMAGE> ims_dog_a;
extern std::vector<IMAGE> ims_dog_s;
extern std::vector<IMAGE> ims_dog_d;
// а���۷�ͼƬ 
extern std::vector<IMAGE> ims_bee_w;
extern std::vector<IMAGE> ims_bee_a;
extern std::vector<IMAGE> ims_bee_s;
extern std::vector<IMAGE> ims_bee_d;
// �ص�boss
extern std::vector<IMAGE> ims_boss_a_walk;
extern std::vector<IMAGE> ims_boss_a_fly;
extern std::vector<IMAGE> ims_boss_d_walk;
extern std::vector<IMAGE> ims_boss_d_fly;
// ��ͼƬ
extern std::vector<IMAGE> ims_tower1;
extern std::vector<IMAGE> ims_tower2;
extern std::vector<IMAGE> ims_tower3;
// �����ͼƬ
extern std::vector<IMAGE> ims_coinTower1;
extern std::vector<IMAGE> ims_coinTower2;
extern std::vector<IMAGE> ims_coinTower3;
// ���ͼƬ
extern std::vector<IMAGE> ims_coin;
// ����ͼƬ
extern std::vector<IMAGE> ims_heart;
// ����ͼƬ
extern IMAGE im_arrow;
// �����ӵ�ͼƬ
extern IMAGE im_enemyBullet;

extern std::vector<IMAGE> ims_upgrade_button;

extern IMAGE im_build;
// �ܻ���Ч
extern std::vector<IMAGE> ims_vfx_hit;
// ��ը��Ч
extern std::vector<IMAGE> ims_vfx_boom;
// ��ħ����Ч
extern std::vector<IMAGE> ims_vfx_ice;
// �ձ�����Ч
extern std::vector<IMAGE> ims_vfx_beIced;
//����ͼƬ
extern IMAGE im_spade;
// ����ť
extern IMAGE im_wrong;
// ��������
extern IMAGE im_ice;
// ը������
extern IMAGE im_bomb;
// ��������
extern IMAGE im_ui_waveflag;
// boss����
extern IMAGE im_ui_bossflag;
// ����ͼƬ
extern IMAGE im_ui_warning;
// ���ͼ��
extern IMAGE im_result;
// ��Һ͹�����������
extern IMAGE im_coinBK;
void loadAllImages();

#endif // !IMAGES_H




