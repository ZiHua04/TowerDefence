#include "Images.h"
IMAGE im_bk;// ����ͼƬ

// ����ͼƬ
std::vector<IMAGE> ims_monster_w;
std::vector<IMAGE> ims_monster_a;
std::vector<IMAGE> ims_monster_s;
std::vector<IMAGE> ims_monster_d;
// ����ȮͼƬ
std::vector<IMAGE> ims_dog_w;
std::vector<IMAGE> ims_dog_a;
std::vector<IMAGE> ims_dog_s;
std::vector<IMAGE> ims_dog_d;
// а���۷�ͼƬ 
std::vector<IMAGE> ims_bee_w;
std::vector<IMAGE> ims_bee_a;
std::vector<IMAGE> ims_bee_s;
std::vector<IMAGE> ims_bee_d;

// ��ͼƬ
std::vector<IMAGE> ims_tower1;
std::vector<IMAGE> ims_tower2;
std::vector<IMAGE> ims_tower3;
// �����ͼƬ
std::vector<IMAGE> ims_coinTower1;
std::vector<IMAGE> ims_coinTower2;
std::vector<IMAGE> ims_coinTower3;
// ����ͼƬ
IMAGE im_arrow;
// �ܻ���Ч
std::vector<IMAGE> ims_vfx_hit;
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
	// ���ص���ȮͼƬ
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
	// ����а���۷�ͼƬ
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
	// ���ؽ����ͼƬ
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
	// �����ܻ���Ч
	for (int i = 0; i < 12; i++) {
		_stprintf_s(filename, _T("res/images/VFX/hit/%d.png"), i);
		IMAGE im;
		loadimage(&im, filename);
		ims_vfx_hit.push_back(im);
	}

	// ���ع���ͼƬ
	loadimage(&im_arrow, _T("res/images/Tower/arrow.png"));
	printf_s("����ͼƬ�������");

	
}