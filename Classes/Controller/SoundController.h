#ifndef SOUND_CONTROLLER_H_
#define SOUND_CONTROLLER_H_

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "Common\common.h"

enum ESounds {
	ES_FIRE = 0,

	ES_LAST
};

class SoundController {
private:

	std::vector<std::string>* _musics;
	unsigned int countPlayed;
	bool _statusPlay;
public:
	SoundController();
	void preloadEffect(ESounds sound);
	void playEffect(ESounds sound);

	void preloadMusic(std::string path);
	void playMusic();
	void stopMusic();
	void update();
};

#endif /* SOUND_CONTROLLER_H_ */