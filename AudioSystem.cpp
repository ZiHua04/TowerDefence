#include "AudioSystem.h"
#include <graphics.h>
#include <thread>
AudioSystem::AudioSystem()
{
	//this->playBGM();
}

void AudioSystem::playBGM()
{
	mciSendString(L"close bgm", 0, 0, 0);

	std::string path = this->folderPath + "Run.mp3";
	// ת�� std::string Ϊ std::wstring
	std::wstring wpath(path.begin(), path.end());
	std::wstring command = L"open " + wpath + L" alias bgm"; // ע���ǿ��ַ�
	// ʹ�� c_str() ת��Ϊ LPCWSTR
	mciSendString(command.c_str(), 0, 0, 0);

	// ������������
	mciSendString(L"play bgm repeat", 0, 0, 0); // L"play bgm" �ǿ��ַ��ַ���

	//mciSendString(_T("open res/sounds/Run.mp3 alias bgm"), 0, 0, 0);
	//mciSendString(_T("play bgm"), 0, 0, 0);
}

void AudioSystem::playBGM(int i)
{
	mciSendString(L"close bgm", 0, 0, 0);
	std::string path = "";
	
	if (i == 0) {
		path = this->folderPath + "Stars.mp3";
	}
	else if (i == 1) {
		path = this->folderPath + "Stars2.mp3";
	}
	else {
		path = this->folderPath + "Run.mp3";
	}
	
	// ת�� std::string Ϊ std::wstring
	std::wstring wpath(path.begin(), path.end());
	std::wstring command = L"open " + wpath + L" alias bgm"; // ע���ǿ��ַ�
	// ʹ�� c_str() ת��Ϊ LPCWSTR
	mciSendString(command.c_str(), 0, 0, 0);

	// ������������
	mciSendString(L"play bgm repeat", 0, 0, 0); // L"play bgm" �ǿ��ַ��ַ���
}



void AudioSystem::playAudio(AudioType type)
{
	switch (type)
	{
	case AudioType::Boom:
		this->sendPlayCommand("Boom.mp3");
		break;
	case AudioType::Ice:
		this->sendPlayCommand("Ice.mp3");
		break;
	case AudioType::Shoot:
		this->sendPlayCommand("Shoot.mp3");
		break;
	case AudioType::MonsterWave:
		this->sendPlayCommand("MonsterLaughing.mp3");
		break;
	case AudioType::Click:
		this->sendPlayCommand("button_click.mp3");
		break;
	case AudioType::MissCoin:
		this->sendPlayCommand("wrongCoin.mp3");
		break;
	case AudioType::GameStart:
		this->sendPlayCommand("game_start.mp3");
		break;
	case AudioType::Cheer:
		this->sendPlayCommand("cheer.mp3");
		break;
	case AudioType::Clap:
		this->sendPlayCommand("clap.mp3");
		break;
	case AudioType::Lose:
		this->sendPlayCommand("game_lose.mp3");
		break;
	default:
		break;
	}
}

void AudioSystem::sendPlayCommand(std::string name)
{
	// �õ�����·��
	std::string path = this->folderPath + name;
	// ת�� std::string Ϊ std::wstring
	std::wstring wpath(path.begin(), path.end());
	std::wstring command = L"open " + wpath + L" alias audio"; // 

	std::thread([this, command]() {
		// ʹ�� c_str() ת��Ϊ LPCWSTR
		mciSendString(command.c_str(), 0, 0, 0);
		// ��������
		mciSendString(L"setaudio audio volume to 500", 0, 0, 0);
		// ������������
		mciSendString(L"play audio wait", 0, 0, 0); // L"play bgm" �ǿ��ַ��ַ���
		if (this == nullptr) return;
		//std::this_thread::sleep_for(std::chrono::milliseconds(500));
		mciSendString(L"close audio", 0, 0, 0);
		}).detach();
}
