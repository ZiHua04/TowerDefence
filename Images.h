#pragma once
#ifndef IMAGES_H
#define IMAGES_H

#include <vector>
#include <graphics.h>

extern IMAGE im_bk;// ����ͼƬ

// ����ͼƬ
extern std::vector<IMAGE> ims_monster_w;
extern std::vector<IMAGE> ims_monster_a;
extern std::vector<IMAGE> ims_monster_s;
extern std::vector<IMAGE> ims_monster_d;
// ��ͼƬ
extern std::vector<IMAGE> ims_tower1;
extern std::vector<IMAGE> ims_tower2;
extern std::vector<IMAGE> ims_tower3;
// �����ͼƬ
extern std::vector<IMAGE> ims_coinTower1;
extern std::vector<IMAGE> ims_coinTower2;
extern std::vector<IMAGE> ims_coinTower3;
// ����ͼƬ
extern IMAGE im_arrow;

extern std::vector<IMAGE> ims_upgrade_button;

extern IMAGE im_build;

void loadAllImages();

#endif // !IMAGES_H




