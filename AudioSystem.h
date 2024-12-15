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
	AudioSystem();
	void playBGM();
	void playAudio(AudioType type);
	void sendPlayCommand(std::string name);
};


#endif // !AUDIO_SYSTEM_H




