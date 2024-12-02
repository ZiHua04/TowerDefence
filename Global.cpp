#include "Global.h"
#include "EnemyBullet.h"
// ����
std::vector<Monster*> monsters;
// ������ť
ClickButton* clickButton = new ClickButton();
// ��
std::map<Coordinate, Tower*> towers;
// �ӵ�
std::vector<Bullet*> bullets;
// �����ӵ�
std::vector<EnemyBullet*> enemyBullets;
// ���ϵͳ
CoinSystem* coinSystem = new CoinSystem();
// ��Чϵͳ
VFXSystem* vfxSystem = new VFXSystem();

void destoryMonsterById(int id) {
	// ʹ�� std::find_if ����
	auto it = std::find_if(monsters.begin(), monsters.end(), [id](Monster* monster) {
		return (monster->id == id); // �Ƚ϶���� id
		});
	if (it != monsters.end()) {
		// �ͷ��ڴ�
		delete* it;
		// �� vector ���Ƴ�ָ��
		monsters.erase(it);
	}
}

void destoryBulletById(int id)
{
	// ʹ�� std::find_if ����
	auto it = std::find_if(bullets.begin(), bullets.end(), [id](Bullet* bullet) {
		return (bullet->id == id); // �Ƚ϶���� id
		});
	if (it != bullets.end()) {
		// �ͷ��ڴ�
		delete* it;
		// �� vector ���Ƴ�ָ��
		bullets.erase(it);
	}
}

void destoryEnemyBulletById(int id) {
	// ʹ�� std::find_if ����
	auto it = std::find_if(enemyBullets.begin(), enemyBullets.end(), [id](EnemyBullet* enemyBullet) {
		return (enemyBullet->id == id); // �Ƚ϶���� id
		});
	if (it != enemyBullets.end()) {
		// �ͷ��ڴ�
		delete* it;
		// �� vector ���Ƴ�ָ��
		enemyBullets.erase(it);
	}
}