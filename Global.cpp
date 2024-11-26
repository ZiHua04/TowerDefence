#include "Global.h"

// 怪物
std::vector<Monster*> monsters;
// 升级按钮
ClickButton* clickButton = new ClickButton();
// 塔
std::map<Coordinate, Tower*> towers;
// 子弹
std::vector<Bullet*> bullets;

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
