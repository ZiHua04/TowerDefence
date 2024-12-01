#include "Images.h"
IMAGE im_bk;// ±³¾°Í¼Æ¬

// ¹ÖÎïÍ¼Æ¬
std::vector<IMAGE> ims_monster_w;
std::vector<IMAGE> ims_monster_a;
std::vector<IMAGE> ims_monster_s;
std::vector<IMAGE> ims_monster_d;
// µØÓüÈ®Í¼Æ¬
std::vector<IMAGE> ims_dog_w;
std::vector<IMAGE> ims_dog_a;
std::vector<IMAGE> ims_dog_s;
std::vector<IMAGE> ims_dog_d;
// Ğ°¶ñÃÛ·äÍ¼Æ¬ 
std::vector<IMAGE> ims_bee_w;
std::vector<IMAGE> ims_bee_a;
std::vector<IMAGE> ims_bee_s;
std::vector<IMAGE> ims_bee_d;

// ËşÍ¼Æ¬
std::vector<IMAGE> ims_tower1;
std::vector<IMAGE> ims_tower2;
std::vector<IMAGE> ims_tower3;
// ½ğ±ÒËşÍ¼Æ¬
std::vector<IMAGE> ims_coinTower1;
std::vector<IMAGE> ims_coinTower2;
std::vector<IMAGE> ims_coinTower3;
// ¹­¼ıÍ¼Æ¬
IMAGE im_arrow;
// ÊÜ»÷ÌØĞ§
std::vector<IMAGE> ims_vfx_hit;
std::vector<IMAGE> ims_upgrade_button;

IMAGE im_build;

void loadAllImages() {
	TCHAR filename[80];
	// ¼ÓÔØ±³¾°Í¼Æ¬
	loadimage(&im_bk, _T("res/images/±³¾°Í¼.png"));
	printf_s("±³¾°Í¼Æ¬¼ÓÔØÍê±Ï");

	for (int i = 0; i < 12; i++) {
		_stprintf_s(filename, _T("res/images/UI/Éı¼¶°´Å¥/%d.png"), i);
		IMAGE im;
		loadimage(&im, filename);
		ims_upgrade_button.push_back(im);
	}
	printf_s("Éı¼¶°´Å¥¼ÓÔØÍê±Ï");

	loadimage(&im_build, _T("res/images/UI/buildButton.png"));
	printf_s("½¨Ôì°´Å¥¼ÓÔØÍê±Ï");

	// ¼ÓÔØ¹ÖÎïÍ¼Æ¬
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
	// ¼ÓÔØµØÓüÈ®Í¼Æ¬
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
	// ¼ÓÔØĞ°¶ñÃÛ·äÍ¼Æ¬
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
	printf_s("¹ÖÎïÍ¼Æ¬¼ÓÔØÍê±Ï");
	// ¼ÓÔØËşÍ¼Æ¬
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
	printf_s("ËşÍ¼Æ¬¼ÓÔØÍê±Ï");
	// ¼ÓÔØ½ğ±ÒËşÍ¼Æ¬
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
	// ¼ÓÔØÊÜ»÷ÌØĞ§
	for (int i = 0; i < 12; i++) {
		_stprintf_s(filename, _T("res/images/VFX/hit/%d.png"), i);
		IMAGE im;
		loadimage(&im, filename);
		ims_vfx_hit.push_back(im);
	}

	// ¼ÓÔØ¹­¼ıÍ¼Æ¬
	loadimage(&im_arrow, _T("res/images/Tower/arrow.png"));
	printf_s("¹­¼ıÍ¼Æ¬¼ÓÔØÍê±Ï");

	
}