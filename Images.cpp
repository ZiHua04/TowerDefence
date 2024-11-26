#include "Images.h"
IMAGE im_bk;// ±³¾°Í¼Æ¬

// ¹ÖÎïÍ¼Æ¬
std::vector<IMAGE> ims_monster_w;
std::vector<IMAGE> ims_monster_a;
std::vector<IMAGE> ims_monster_s;
std::vector<IMAGE> ims_monster_d;
// ËşÍ¼Æ¬
std::vector<IMAGE> ims_tower1;
std::vector<IMAGE> ims_tower2;
std::vector<IMAGE> ims_tower3;
// ¹­¼ıÍ¼Æ¬
IMAGE im_arrow;

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
	// ¼ÓÔØ¹­¼ıÍ¼Æ¬
	loadimage(&im_arrow, _T("res/images/Tower/arrow.png"));
	printf_s("¹­¼ıÍ¼Æ¬¼ÓÔØÍê±Ï");

	
}