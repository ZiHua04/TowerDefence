#pragma once
#ifndef IMAGES_H
#define IMAGES_H

#include <vector>
#include <graphics.h>
// 首页背景图片
extern IMAGE im_front_bk;
// 关卡图片
extern IMAGE im_front_level;

extern IMAGE im_bk;// 背景图片

extern IMAGE im_bk2; // 背景图片2
extern IMAGE im_bk3; // 背景图片3

// 怪物图片
extern std::vector<IMAGE> ims_monster_w;
extern std::vector<IMAGE> ims_monster_a;
extern std::vector<IMAGE> ims_monster_s;
extern std::vector<IMAGE> ims_monster_d;
// 地狱犬图片
extern std::vector<IMAGE> ims_dog_w;
extern std::vector<IMAGE> ims_dog_a;
extern std::vector<IMAGE> ims_dog_s;
extern std::vector<IMAGE> ims_dog_d;
// 邪恶蜜蜂图片 
extern std::vector<IMAGE> ims_bee_w;
extern std::vector<IMAGE> ims_bee_a;
extern std::vector<IMAGE> ims_bee_s;
extern std::vector<IMAGE> ims_bee_d;
// 关底boss
extern std::vector<IMAGE> ims_boss_a_walk;
extern std::vector<IMAGE> ims_boss_a_fly;
extern std::vector<IMAGE> ims_boss_d_walk;
extern std::vector<IMAGE> ims_boss_d_fly;
// 塔图片
extern std::vector<IMAGE> ims_tower1;
extern std::vector<IMAGE> ims_tower2;
extern std::vector<IMAGE> ims_tower3;
// 金币塔图片
extern std::vector<IMAGE> ims_coinTower1;
extern std::vector<IMAGE> ims_coinTower2;
extern std::vector<IMAGE> ims_coinTower3;
// 金币图片
extern std::vector<IMAGE> ims_coin;
// 爱心图片
extern std::vector<IMAGE> ims_heart;
// 弓箭图片
extern IMAGE im_arrow;
// 敌人子弹图片
extern IMAGE im_enemyBullet;

extern std::vector<IMAGE> ims_upgrade_button;

extern IMAGE im_build;
// 受击特效
extern std::vector<IMAGE> ims_vfx_hit;
// 大爆炸特效
extern std::vector<IMAGE> ims_vfx_boom;
// 冰魔法特效
extern std::vector<IMAGE> ims_vfx_ice;
// 收冰冻特效
extern std::vector<IMAGE> ims_vfx_beIced;
//铲子图片
extern IMAGE im_spade;
// 错误按钮
extern IMAGE im_wrong;
// 冰冻道具
extern IMAGE im_ice;
// 炸弹道具
extern IMAGE im_bomb;
// 波次旗帜
extern IMAGE im_ui_waveflag;
// boss旗帜
extern IMAGE im_ui_bossflag;
// 警告图片
extern IMAGE im_ui_warning;
// 结果图像
extern IMAGE im_result;
// 金币和怪物数量背景
extern IMAGE im_coinBK;
void loadAllImages();

#endif // !IMAGES_H




