#include "Images.h"

// ��ҳ����ͼƬ
IMAGE im_front_bk;
// �ؿ�ͼƬ
IMAGE im_front_level;

IMAGE im_bk;// ����ͼƬ
IMAGE im_bk2; // ����ͼƬ2
IMAGE im_bk3; // ����ͼƬ3
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
// �ص�boss
std::vector<IMAGE> ims_boss_a_walk;
std::vector<IMAGE> ims_boss_a_fly;
std::vector<IMAGE> ims_boss_d_walk;
std::vector<IMAGE> ims_boss_d_fly;
// ��ͼƬ
std::vector<IMAGE> ims_tower1;
std::vector<IMAGE> ims_tower2;
std::vector<IMAGE> ims_tower3;
// �����ͼƬ
std::vector<IMAGE> ims_coinTower1;
std::vector<IMAGE> ims_coinTower2;
std::vector<IMAGE> ims_coinTower3;
// ���ͼƬ
std::vector<IMAGE> ims_coin;
// ����ͼƬ
std::vector<IMAGE> ims_heart;
// ����ͼƬ
IMAGE im_arrow;
// �����ӵ�ͼƬ
IMAGE im_enemyBullet;
// �ܻ���Ч
std::vector<IMAGE> ims_vfx_hit;
// ��ը��Ч
std::vector<IMAGE> ims_vfx_boom;
// ��ħ����Ч
std::vector<IMAGE> ims_vfx_ice;
// �ձ�����Ч
std::vector<IMAGE> ims_vfx_beIced;

std::vector<IMAGE> ims_upgrade_button;

IMAGE im_build;

//����ͼƬ
IMAGE im_spade;
// ����ť
IMAGE im_wrong;
// ��������
IMAGE im_ice;
// ը������
IMAGE im_bomb;
// ��������
IMAGE im_ui_waveflag;
// boss����
IMAGE im_ui_bossflag;
// ����ͼƬ
IMAGE im_ui_warning;
// ���ͼ��
IMAGE im_result;


void loadAllImages() {
	TCHAR filename[80];
	// ������ҳ����ͼ
	loadimage(&im_front_bk, _T("res/images/��ҳ����ͼ.png"));
	printf_s("��ҳ����ͼ�������");
	// ���عؿ�ͼƬ
	loadimage(&im_front_level, _T("res/images/ui/LevelIcon.png"));
	printf_s("�ؿ�ͼƬ�������");
	// ���ؽ��㱳��
	loadimage(&im_result, _T("res/images/���㻭��.png"));

	// ���ر���ͼƬ1
	loadimage(&im_bk, _T("res/images/����ͼ.png"));
	printf_s("����ͼƬ1�������");
	// ���ر���ͼƬ2
	loadimage(&im_bk2, _T("res/images/��Ϸ����2.png"));
	printf_s("����ͼƬ2�������");
	// ���ر���ͼƬ1
	loadimage(&im_bk3, _T("res/images/��Ϸ����3.png"));
	printf_s("����ͼƬ3�������");

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
	printf_s("����ȮͼƬ�������");
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
	printf_s("а���۷�ͼƬ�������");
	// ���عص�bossͼƬ
	for (int i = 0; i < 6; i++) {
		_stprintf_s(filename, _T("res/images/Monster/Boss/A_Fly/%d.png"), i);
		IMAGE im;
		loadimage(&im, filename);
		ims_boss_a_fly.push_back(im);

		_stprintf_s(filename, _T("res/images/Monster/Boss/D_Fly/%d.png"), i);
		loadimage(&im, filename);
		ims_boss_d_fly.push_back(im);
	}
	for (int i = 0; i < 12; i++) {
		_stprintf_s(filename, _T("res/images/Monster/Boss/A_Walk/%d.png"), i);
		IMAGE im;
		loadimage(&im, filename);
		ims_boss_a_walk.push_back(im);

		_stprintf_s(filename, _T("res/images/Monster/Boss/D_Walk/%d.png"), i);
		loadimage(&im, filename);
		ims_boss_d_walk.push_back(im);
	}
	printf_s("�ص�bossͼƬ�������");
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
	printf_s("�����ͼƬ�������");
	// �����ܻ���Ч
	for (int i = 0; i < 12; i++) {
		_stprintf_s(filename, _T("res/images/VFX/hit/%d.png"), i);
		IMAGE im;
		loadimage(&im, filename);
		ims_vfx_hit.push_back(im);
	}
	printf_s("�ܻ���ЧͼƬ�������");
	// ���ش�ը��Ч
	for (int i = 0; i < 10; i++) {
		_stprintf_s(filename, _T("res/images/VFX/Boom/%d.png"), i);
		IMAGE im;
		loadimage(&im, filename);
		ims_vfx_boom.push_back(im);
	}
	printf_s("��ը��ЧͼƬ�������");
	// ���ر�ħ����Ч
	for (int i = 0; i < 36; i++) {
		_stprintf_s(filename, _T("res/images/VFX/Ice/%d.png"), i);
		IMAGE im;
		loadimage(&im, filename);
		ims_vfx_ice.push_back(im);
	}
	printf_s("��ħ����ЧͼƬ�������");
	// �����ܱ�����Ч
	for (int i = 0; i < 35; i++) {
		_stprintf_s(filename, _T("res/images/VFX/BeIced/%d.png"), i);
		IMAGE im;
		loadimage(&im, filename);
		ims_vfx_beIced.push_back(im);
	}
	printf_s("�ܱ�����ЧͼƬ�������");
	// ���ؽ��ͼƬ
	for (int i = 0; i < 15; i++) {
		_stprintf_s(filename, _T("res/images/UI/coin/%d.png"), i);
		IMAGE im;
		loadimage(&im, filename);
		ims_coin.push_back(im);
	}
	printf_s("���ͼƬ�������");
	// ���ذ���ͼƬ
	for (int i = 0; i < 8; i++) {
		_stprintf_s(filename, _T("res/images/UI/heart/%d.png"), i);
		IMAGE im;
		loadimage(&im, filename);
		ims_heart.push_back(im);
	}
	printf_s("����ͼƬ�������");
	// ���ع���ͼƬ
	loadimage(&im_arrow, _T("res/images/Tower/bullet.png"));
	printf_s("����ͼƬ�������");
	// ���ص����ӵ�ͼƬ
	loadimage(&im_enemyBullet, _T("res/images/Monster/EnemyBullet/2.png"));
	printf_s("����ͼƬ�������");
	// ���ز���ͼƬ
	loadimage(&im_spade, _T("res/images/UI/����.png"));
	printf_s("����ͼƬ�������");
	// ���ش���ͼƬ
	loadimage(&im_wrong, _T("res/images/UI/wrong.png"));
	printf_s("����ͼƬ�������");
	// ���ر���ͼƬ
	loadimage(&im_ice, _T("res/images/UI/����.png"));
	printf_s("�����������");
	// ����ը��ͼƬ
	loadimage(&im_bomb, _T("res/images/UI/ը��.png"));
	printf_s("ը���������");
	// ���ز�������ͼƬ
	loadimage(&im_ui_waveflag, _T("res/images/UI/waveflag.png"));
	printf_s("�������ļ������");
	// ���عص�����ͼƬ
	loadimage(&im_ui_bossflag, _T("res/images/UI/bossflag.png"));
	printf_s("�ص����ļ������");
	// ���ؾ���ͼƬ
	loadimage(&im_ui_warning, _T("res/images/UI/warning.png"));
	printf_s("����������");
}