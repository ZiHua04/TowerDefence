#pragma once
#ifndef IMAGES_H
#define IMAGES_H

#include <vector>
#include <graphics.h>
// Ê×Ò³±³¾°Í¼Æ¬
extern IMAGE im_front_bk;
// ¹Ø¿¨Í¼Æ¬
extern IMAGE im_front_level;

extern IMAGE im_bk;// ±³¾°Í¼Æ¬

extern IMAGE im_bk2; // ±³¾°Í¼Æ¬2
extern IMAGE im_bk3; // ±³¾°Í¼Æ¬3

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
// ¹Øµ×boss
extern std::vector<IMAGE> ims_boss_a_walk;
extern std::vector<IMAGE> ims_boss_a_fly;
extern std::vector<IMAGE> ims_boss_d_walk;
extern std::vector<IMAGE> ims_boss_d_fly;
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
// ÊÜ»÷ÌØĞ§
extern std::vector<IMAGE> ims_vfx_hit;
// ´ó±¬Õ¨ÌØĞ§
extern std::vector<IMAGE> ims_vfx_boom;
// ±ùÄ§·¨ÌØĞ§
extern std::vector<IMAGE> ims_vfx_ice;
// ÊÕ±ù¶³ÌØĞ§
extern std::vector<IMAGE> ims_vfx_beIced;
//²ù×ÓÍ¼Æ¬
extern IMAGE im_spade;
// ´íÎó°´Å¥
extern IMAGE im_wrong;
// ±ù¶³µÀ¾ß
extern IMAGE im_ice;
// Õ¨µ¯µÀ¾ß
extern IMAGE im_bomb;
// ²¨´ÎÆìÖÄ
extern IMAGE im_ui_waveflag;
// bossÆìÖÄ
extern IMAGE im_ui_bossflag;
// ¾¯¸æÍ¼Æ¬
extern IMAGE im_ui_warning;
// ½á¹ûÍ¼Ïñ
extern IMAGE im_result;
void loadAllImages();

#endif // !IMAGES_H




