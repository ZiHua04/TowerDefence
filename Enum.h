#pragma once
#ifndef ENUM_H
#define ENUM_H


enum class GameState {
	START_SCENE = 0, // 游戏开始场景
	PLAYING, // 游戏进行中
	PAUSE, // 游戏暂停
	WIN, // 游戏胜利
	LOSE, // 游戏失败
	EXIT // 退出游戏
};

// 定义一个枚举类，表示怪物类型
enum class MonsterType {
	// 哥布林
	Goblin = 0,
	// 蜜蜂
	Bee,
	// 狗
	Dog
};
// 表示按钮类型	
enum class ClickButtonType {
	Build = 0, // 建造
    Upgrade, // 升级
	Hide, // 隐藏
};



#endif // !ENUM_H

