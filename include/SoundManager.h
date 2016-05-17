
#ifndef __Lore_include_SoundManager_h__
#define __Lore_include_SoundManager_h__

//std
#include <map>
#include <string>
//Lore
#include "GameCommon.h"


NS_LORE_BEGIN

class SoundManager
{
    // Constants //
public:
    static const int kPlayForever;


    // Singleton //
public:
    COREGAME_SINGLETON_OF(SoundManager);
    COREGAME_DISALLOW_COPY_MOVE_ASSIGN(SoundManager);
private:
    SoundManager() {};


    // Init / Shutdown //
public:
    void initialize();
    void shutdown();


    // Public Methods //
public:
    void setVolume(int vol);
    int  getVolume() const;

    void playEffect(const std::string &name, int loopTimes = 1);
    void stopEffect(const std::string &name);
    void stopAllEffects();

    void playMusic(const std::string &name, int loopTimes = kPlayForever);
    void stopMusic();


    // iVars //
private:
    std::map<std::string, int> m_soundEffectsMap;
    std::map<std::string, int> m_musicsMap;
};

NS_LORE_END
#endif // __Lore_include_SoundManager_h__ //
