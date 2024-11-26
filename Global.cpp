#include "Global.h"

// ����
std::vector<Monster*> monsters;
// ������ť
ClickButton* clickButton = new ClickButton();
// ��
std::map<Coordinate, Tower*> towers;
// �ӵ�
std::vector<Bullet*> bullets;

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
