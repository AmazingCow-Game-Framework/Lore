
#ifndef __Lore_include_SoundManager_h__
#define __Lore_include_SoundManager_h__

//std
#include <map>
#include <string>
//Lore
#include "Lore_Utils.h"

NS_LORE_BEGIN

class SoundManager
{
    // Constants / Enums / Typdefs //
public:
    static const int kPlayForever;
private:
    typedef std::map<std::string, Mix_Chunk*> EffectMap;
    typedef std::map<std::string, Mix_Music*> MusicMap;


    // Singleton //
public:
    COREGAME_SINGLETON_OF(SoundManager);
    COREGAME_DISALLOW_COPY_MOVE_ASSIGNS(SoundManager);
private:
    SoundManager() {};


    // Init / Shutdown //
public:
    void initialize(int    frequency,
                    Uint16 format,
                    int    channels,
                    int    chunksize);
    void shutdown();


    // Volume Methods //
public:
    void setVolume(int vol);
    int  getVolume() const;


    // Player Methods //
public:
    void playEffect(const std::string &name, int loopTimes = 1);
    void stopEffect(const std::string &name);
    void stopAllEffects();

    void playMusic(const std::string &name, int loopTimes = kPlayForever);
    void stopMusic();


    // Load / Unload Methods //
public:
    void loadEffect(const std::string &name);
    void loadMusic(const std::string &name);

    void unloadEffect(const std::string &name);
    void unloadMusic(const std::string &name);

    bool isEffectLoaded(const std::string &name);
    bool isMusicLoaded(const std::string &name);


    // iVars //
private:
    EffectMap m_effectsMap;
    MusicMap  m_musicsMap;
};

NS_LORE_END
#endif // __Lore_include_SoundManager_h__ //
