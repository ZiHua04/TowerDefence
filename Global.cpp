#include "Global.h"
#include "EnemyBullet.h"
ExMessage m;
// 怪物
std::vector<Monster*> monsters;
// 升级按钮
ClickButton* clickButton = new ClickButton();
// 塔
std::map<Coordinate, Tower*> towers;
// 子弹
std::vector<Bullet*> bullets;
// 敌人子弹
std::vector<EnemyBullet*> enemyBullets;
// 金币系统
CoinSystem* coinSystem = new CoinSystem();
// 特效系统
VFXSystem* vfxSystem = new VFXSystem();

void destoryMonsterById(int id) {
	// 使用 std::find_if 查找
	auto it = std::find_if(monsters.begin(), monsters.end(), [id](Monster* monster) {
		return (monster->id == id); // 比较对象的 id
		});
	if (it != monsters.end()) {
		// 释放内存
		delete* it;
		// 从 vector 中移除指针
		monsters.erase(it);
	}
}

void destoryBulletById(int id)
{
	// 使用 std::find_if 查找
	auto it = std::find_if(bullets.begin(), bullets.end(), [id](Bullet* bullet) {
		return (bullet->id == id); // 比较对象的 id
		});
	if (it != bullets.end()) {
		// 释放内存
		delete* it;
		// 从 vector 中移除指针
		bullets.erase(it);
	}
}

void destoryEnemyBulletById(int id) {
	// 使用 std::find_if 查找
	auto it = std::find_if(enemyBullets.begin(), enemyBullets.end(), [id](EnemyBullet* enemyBullet) {
		return (enemyBullet->id == id); // 比较对象的 id
		});
	if (it != enemyBullets.end()) {
		// 释放内存
		delete* it;
		// 从 vector 中移除指针
		enemyBullets.erase(it);
	}
}
void destoryTowerById(int id) {
	// 遍历map，找到id相同的元素并删除
	for (auto it = towers.begin(); it != towers.end(); ) {
		if (it->second->id == id) {
			delete it->second;      // 销毁对象
			it = towers.erase(it);   // 删除map中的元素，并更新迭代器
			return;
		}
		else {
			++it;  // 如果id不匹配，继续遍历
		}
	}
}