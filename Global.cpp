#include "Global.h"
#include "EnemyBullet.h"

int currentLevel = 0;

GameState currentGameState = GameState::START_SCENE;

ExMessage m;
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
// ����ϵͳ
PropSystem* propSystem = new PropSystem();
// ����������
MonsterCreator* monsterCreator;
// ��Чϵͳ
AudioSystem* audioSystem = new AudioSystem();

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
void destoryTowerById(int id) {
	// ����map���ҵ�id��ͬ��Ԫ�ز�ɾ��
	for (auto it = towers.begin(); it != towers.end(); ) {
		if (it->second->id == id) {
			delete it->second;      // ���ٶ���
			it = towers.erase(it);   // ɾ��map�е�Ԫ�أ������µ�����
			return;
		}
		else {
			++it;  // ���id��ƥ�䣬��������
		}
	}
}

void clearData() {
	while (!bullets.empty())
	{
		destoryBulletById(bullets[0]->id);
	}
	
	while (!enemyBullets.empty()) {
		destoryEnemyBulletById(enemyBullets[0]->id);
	}
	while (!monsters.empty())
	{
		destoryMonsterById(monsters[0]->id);
	}
	for (auto& pair : towers) {
		delete pair.second;  // ɾ��ÿ��ָ�� Tower �����ָ��
	}
	towers.clear();  // ��� map

	coinSystem->reset();
}