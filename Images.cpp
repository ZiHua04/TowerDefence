#include "Images.h"
IMAGE im_bk;// ����ͼƬ

// ����ͼƬ
std::vector<IMAGE> ims_monster_w;
std::vector<IMAGE> ims_monster_a;
std::vector<IMAGE> ims_monster_s;
std::vector<IMAGE> ims_monster_d;
// ��ͼƬ
std::vector<IMAGE> ims_tower1;
std::vector<IMAGE> ims_tower2;
std::vector<IMAGE> ims_tower3;
// ����ͼƬ
IMAGE im_arrow;

std::vector<IMAGE> ims_upgrade_button;

IMAGE im_build;

void loadAllImages() {
	TCHAR filename[80];
	// ���ر���ͼƬ
	loadimage(&im_bk, _T("res/images/����ͼ.png"));
	printf_s("����ͼƬ�������");

	for (int i = 0; i < 12; i++) {
		_stprintf_s(filename, _T("res/images/UI/������ť/%d.png"), i);
		IMAGE im;
		loadimage(&im, filename);
		ims_upgrade_button.push_back(im);
	}
	printf_s("������ť�������");

	loadimage(&im_build, _T("res/images/UI/buildButton.png"));
	printf_s("���찴ť�������");

	// ���ع���ͼƬ
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
	printf_s("����ͼƬ�������");
	// ������ͼƬ
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
	printf_s("��ͼƬ�������");
	// ���ع���ͼƬ
	loadimage(&im_arrow, _T("res/images/Tower/arrow.png"));
	printf_s("����ͼƬ�������");

	
}