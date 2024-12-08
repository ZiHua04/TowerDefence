#include "Images.h"
IMAGE im_bk;// 背景图片

// 怪物图片
std::vector<IMAGE> ims_monster_w;
std::vector<IMAGE> ims_monster_a;
std::vector<IMAGE> ims_monster_s;
std::vector<IMAGE> ims_monster_d;
// 地狱犬图片
std::vector<IMAGE> ims_dog_w;
std::vector<IMAGE> ims_dog_a;
std::vector<IMAGE> ims_dog_s;
std::vector<IMAGE> ims_dog_d;
// 邪恶蜜蜂图片 
std::vector<IMAGE> ims_bee_w;
std::vector<IMAGE> ims_bee_a;
std::vector<IMAGE> ims_bee_s;
std::vector<IMAGE> ims_bee_d;

// 塔图片
std::vector<IMAGE> ims_tower1;
std::vector<IMAGE> ims_tower2;
std::vector<IMAGE> ims_tower3;
// 金币塔图片
std::vector<IMAGE> ims_coinTower1;
std::vector<IMAGE> ims_coinTower2;
std::vector<IMAGE> ims_coinTower3;
// 金币图片
std::vector<IMAGE> ims_coin;
// 爱心图片
std::vector<IMAGE> ims_heart;
// 弓箭图片
IMAGE im_arrow;
// 敌人子弹图片
IMAGE im_enemyBullet;
// 受击特效
std::vector<IMAGE> ims_vfx_hit;
// 大爆炸特效
std::vector<IMAGE> ims_vfx_boom;
// 冰魔法特效
std::vector<IMAGE> ims_vfx_ice;
// 收冰冻特效
std::vector<IMAGE> ims_vfx_beIced;

std::vector<IMAGE> ims_upgrade_button;

IMAGE im_build;

//铲子图片
IMAGE im_spade;
// 错误按钮
IMAGE im_wrong;
// 冰冻道具
IMAGE im_ice;
// 炸弹道具
IMAGE im_bomb;

void loadAllImages() {
	TCHAR filename[80];
	// 加载背景图片
	loadimage(&im_bk, _T("res/images/背景图.png"));
	printf_s("背景图片加载完毕");

	for (int i = 0; i < 12; i++) {
		_stprintf_s(filename, _T("res/images/UI/升级按钮/%d.png"), i);
		IMAGE im;
		loadimage(&im, filename);
		ims_upgrade_button.push_back(im);
	}
	printf_s("升级按钮加载完毕");

	loadimage(&im_build, _T("res/images/UI/buildButton.png"));
	printf_s("建造按钮加载完毕");

	// 加载怪物图片
	for (int i = 0; i < 6; i++)
	{
		_stprintf_s(filename, _T("res/images/Monster/A_Walk/%d.png"), i);
		IMAGE im;
		loadimage(&im, filename);
		ims_monster_a.push_back(im);

		_stprintf_s(filename, _T("res/images/Monster/W_Walk/%d.png"), i);
		loadimage(&im, filename);
		ims_monster_w.push_back(im);

		_stprintf_s(filename, _T("res/images/Monster/S_Walk/%d.png"), i);
		loadimage(&im, filename);
		ims_monster_s.push_back(im);

		_stprintf_s(filename, _T("res/images/Monster/D_Walk/%d.png"), i);
		loadimage(&im, filename);
		ims_monster_d.push_back(im);
	}
	printf_s("怪物图片加载完毕");
	// 加载地狱犬图片
	for (int i = 0; i < 6; i++) {
		_stprintf_s(filename, _T("res/images/Monster/Dog/A/%d.png"), i);
		IMAGE im;
		loadimage(&im, filename);
		ims_dog_a.push_back(im);

		_stprintf_s(filename, _T("res/images/Monster/Dog/W/%d.png"), i);
		loadimage(&im, filename);
		ims_dog_w.push_back(im);

		_stprintf_s(filename, _T("res/images/Monster/Dog/S/%d.png"), i);
		loadimage(&im, filename);
		ims_dog_s.push_back(im);

		_stprintf_s(filename, _T("res/images/Monster/Dog/D/%d.png"), i);
		loadimage(&im, filename);
		ims_dog_d.push_back(im);
	}
	printf_s("地狱犬图片加载完毕");
	// 加载邪恶蜜蜂图片
	for (int i = 0; i < 6; i++) {
		_stprintf_s(filename, _T("res/images/Monster/Bee/A/%d.png"), i);
		IMAGE im;
		loadimage(&im, filename);
		ims_bee_a.push_back(im);

		_stprintf_s(filename, _T("res/images/Monster/Bee/W/%d.png"), i);
		loadimage(&im, filename);
		ims_bee_w.push_back(im);

		_stprintf_s(filename, _T("res/images/Monster/Bee/S/%d.png"), i);
		loadimage(&im, filename);
		ims_bee_s.push_back(im);

		_stprintf_s(filename, _T("res/images/Monster/Bee/D/%d.png"), i);
		loadimage(&im, filename);
		ims_bee_d.push_back(im);
	}
	printf_s("怪物图片加载完毕");
	// 加载塔图片
	for (int i = 0; i < 4; i++) {
		_stprintf_s(filename, _T("res/images/Tower/tower1/%d.png"), i);
		IMAGE im;
		loadimage(&im, filename);
		ims_tower1.push_back(im);

		_stprintf_s(filename, _T("res/images/Tower/tower2/%d.png"), i);
		loadimage(&im, filename);
		ims_tower2.push_back(im);

		_stprintf_s(filename, _T("res/images/Tower/tower3/%d.png"), i);
		loadimage(&im, filename);
		ims_tower3.push_back(im);
	}
	printf_s("塔图片加载完毕");
	// 加载金币塔图片
	for (int i = 0; i < 4; i++) {
		_stprintf_s(filename, _T("res/images/Tower/coinTower1/%d.png"), i);
		IMAGE im;
		loadimage(&im, filename);
		ims_coinTower1.push_back(im);

		_stprintf_s(filename, _T("res/images/Tower/coinTower2/%d.png"), i);
		loadimage(&im, filename);
		ims_coinTower2.push_back(im);

		_stprintf_s(filename, _T("res/images/Tower/coinTower3/%d.png"), i);
		loadimage(&im, filename);
		ims_coinTower3.push_back(im);
	}
	printf_s("金币塔图片加载完毕");
	// 加载受击特效
	for (int i = 0; i < 12; i++) {
		_stprintf_s(filename, _T("res/images/VFX/hit/%d.png"), i);
		IMAGE im;
		loadimage(&im, filename);
		ims_vfx_hit.push_back(im);
	}
	printf_s("受击特效图片加载完毕");
	// 加载大爆炸特效
	for (int i = 0; i < 10; i++) {
		_stprintf_s(filename, _T("res/images/VFX/Boom/%d.png"), i);
		IMAGE im;
		loadimage(&im, filename);
		ims_vfx_boom.push_back(im);
	}
	printf_s("大爆炸特效图片加载完毕");
	// 加载冰魔法特效
	for (int i = 0; i < 36; i++) {
		_stprintf_s(filename, _T("res/images/VFX/Ice/%d.png"), i);
		IMAGE im;
		loadimage(&im, filename);
		ims_vfx_ice.push_back(im);
	}
	printf_s("冰魔法特效图片加载完毕");
	// 加载受冰冻特效
	for (int i = 0; i < 35; i++) {
		_stprintf_s(filename, _T("res/images/VFX/BeIced/%d.png"), i);
		IMAGE im;
		loadimage(&im, filename);
		ims_vfx_beIced.push_back(im);
	}
	printf_s("受冰冻特效图片加载完毕");
	// 加载金币图片
	for (int i = 0; i < 15; i++) {
		_stprintf_s(filename, _T("res/images/UI/coin/%d.png"), i);
		IMAGE im;
		loadimage(&im, filename);
		ims_coin.push_back(im);
	}
	printf_s("金币图片加载完毕");
	// 加载爱心图片
	for (int i = 0; i < 8; i++) {
		_stprintf_s(filename, _T("res/images/UI/heart/%d.png"), i);
		IMAGE im;
		loadimage(&im, filename);
		ims_heart.push_back(im);
	}
	printf_s("爱心图片加载完毕");
	// 加载弓箭图片
	loadimage(&im_arrow, _T("res/images/Tower/bullet.png"));
	printf_s("弓箭图片加载完毕");
	// 加载敌人子弹图片
	loadimage(&im_enemyBullet, _T("res/images/Monster/EnemyBullet/2.png"));
	printf_s("敌人图片加载完毕");
	// 加载铲子图片
	loadimage(&im_spade, _T("res/images/UI/铲子.png"));
	printf_s("铲子图片加载完毕");
	// 加载错误图片
	loadimage(&im_wrong, _T("res/images/UI/wrong.png"));
	printf_s("错误图片加载完毕");
	// 加载冰冻图片
	loadimage(&im_ice, _T("res/images/UI/冰冻.png"));
	printf_s("冰冻加载完毕");
	// 加载炸弹图片
	loadimage(&im_bomb, _T("res/images/UI/炸弹.png"));
	printf_s("炸弹加载完毕");
}