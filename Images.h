#pragma once
#ifndef IMAGES_H
#define IMAGES_H

#include <vector>
#include <graphics.h>

extern IMAGE im_bk;// ±³¾°Í¼Æ¬

// ¹ÖÎïÍ¼Æ¬
extern std::vector<IMAGE> ims_monster_w;
extern std::vector<IMAGE> ims_monster_a;
extern std::vector<IMAGE> ims_monster_s;
extern std::vector<IMAGE> ims_monster_d;
// µØÓüÈ®Í¼Æ¬
extern std::vector<IMAGE> ims_dog_w;
extern std::vector<IMAGE> ims_dog_a;
extern std::vector<IMAGE> ims_dog_s;
extern std::vector<IMAGE> ims_dog_d;
// Ğ°¶ñÃÛ·äÍ¼Æ¬ 
extern std::vector<IMAGE> ims_bee_w;
extern std::vector<IMAGE> ims_bee_a;
extern std::vector<IMAGE> ims_bee_s;
extern std::vector<IMAGE> ims_bee_d;
// ËşÍ¼Æ¬
extern std::vector<IMAGE> ims_tower1;
extern std::vector<IMAGE> ims_tower2;
extern std::vector<IMAGE> ims_tower3;
// ½ğ±ÒËşÍ¼Æ¬
extern std::vector<IMAGE> ims_coinTower1;
extern std::vector<IMAGE> ims_coinTower2;
extern std::vector<IMAGE> ims_coinTower3;
// ½ğ±ÒÍ¼Æ¬
extern std::vector<IMAGE> ims_coin;
// °®ĞÄÍ¼Æ¬
extern std::vector<IMAGE> ims_heart;
// ¹­¼ıÍ¼Æ¬
extern IMAGE im_arrow;
// µĞÈË×Óµ¯Í¼Æ¬
extern IMAGE im_enemyBullet;

extern std::vector<IMAGE> ims_upgrade_button;

extern IMAGE im_build;

extern std::vector<IMAGE> ims_vfx_hit;

void loadAllImages();

#endif // !IMAGES_H




