#include "Controller/SoundController.h"

static char soundNames [ES_LAST][60]= {
	"sound/fire.wav",//	ES_FIRE

};

SoundController::SoundController()
{
	_musics = new std::vector<std::string>;
	_statusPlay = false;
	countPlayed = 0;
}

void SoundController::preloadEffect(ESounds sound)
{
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect(soundNames[sound]);
}

void SoundController::playEffect(ESounds sound)
{
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(soundNames[sound]);
}

void SoundController::preloadMusic(std::string path)
{
	_musics->push_back(path);
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic(path.c_str() );
}

void SoundController::playMusic()
{
	_statusPlay = true;
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic(_musics->at(countPlayed).c_str() );
}

void SoundController::stopMusic()
{
	_statusPlay = false;
	CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
}

void SoundController::update()
{
	if(_statusPlay && !CocosDenshion::SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying() )
	{
		countPlayed++;
		if(countPlayed >= _musics->size() )countPlayed = 0;
		playMusic();
	}
}