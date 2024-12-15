#pragma once
#ifndef AUDIO_SYSTEM_H
#define AUDIO_SYSTEM_H

#include<Windows.h>
#include<mmsystem.h>
#include "Enum.h"
#include <string>
#pragma comment(lib, "winmm.lib")
class AudioSystem
{
private:
	std::string folderPath = "res/sounds/";
public:
	// 构造函数
	AudioSystem();
	// 播放背景音乐
	void playBGM();
	// 根据音效种类来播放相应音效
	void playAudio(AudioType type);
	// 发送命令
	void sendPlayCommand(std::string name);
};


#endif // !AUDIO_SYSTEM_H




