#pragma once
#ifndef IMAGES_H
#define IMAGES_H

#include <vector>
#include <graphics.h>

extern IMAGE im_bk;// ±³¾°Í¼Æ¬
extern IMAGE im_upgrade;
// ¹ÖÎïÍ¼Æ¬
extern std::vector<IMAGE> ims_monster_w;
extern std::vector<IMAGE> ims_monster_a;
extern std::vector<IMAGE> ims_monster_s;
extern std::vector<IMAGE> ims_monster_d;
// ËþÍ¼Æ¬
extern std::vector<IMAGE> ims_tower1;
extern std::vector<IMAGE> ims_tower2;
extern std::vector<IMAGE> ims_tower3;
// ¹­¼ýÍ¼Æ¬
extern IMAGE im_arrow;



void loadAllImages();

#endif // !IMAGES_H




