
//Header
#include "../include/SoundManager.h"

//Usings
USING_NS_LORE


// Constants //
const int SoundManager::kPlayForever = -1;

// Init / Shutdown //
void SoundManager::initialize()
{

}
void SoundManager::shutdown()
{

}


// Public Methods //
void SoundManager::setVolume(int vol)
{

}
int  SoundManager::getVolume() const
{

}

void SoundManager::playEffect(const std::string &name,
                              int loopTimes /* = 1 */)
{

}
void SoundManager::stopEffect(const std::string &name)
{

}
void SoundManager::stopAllEffects()
{

}

void SoundManager::playMusic(const std::string &name,
                             int loopTimes /* = kPlayForever */)
{

}
void SoundManager::stopMusic()
{

}
