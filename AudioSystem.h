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
	// ���캯��
	AudioSystem();
	// ���ű�������
	void playBGM();
	// ������Ч������������Ӧ��Ч
	void playAudio(AudioType type);
	// ��������
	void sendPlayCommand(std::string name);
};


#endif // !AUDIO_SYSTEM_H




