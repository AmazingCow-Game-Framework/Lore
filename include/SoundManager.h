
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
    // Inner Types //
private:
    struct EffectInfo
    {
        Mix_Chunk *chunk;
        int        playChannel;
    };


    // Constants / Enums / Typedefs //
public:
    static const int kPlayForever;
    static const int kPlayOneTime;


private:
    typedef std::map<std::string, EffectInfo> EffectMap;
    typedef std::map<std::string, Mix_Music*> MusicMap;


    // Singleton //
public:
    COREGAME_SINGLETON_OF(SoundManager);
    COREGAME_DISALLOW_COPY_MOVE_ASSIGNS(SoundManager);
private:
    SoundManager() {};


    // Init / Shutdown //
public:
    void initialize(const std::string &searchPath,
                    int    frequency,
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
    //Effect
    void playEffect(const std::string &name, int loopTimes = kPlayOneTime);
    void stopEffect(const std::string &name);
    void stopAllEffects();

    //Music
    void playMusic(const std::string &name, int loopTimes = kPlayForever);
    void stopMusic();


    // Load / Unload Methods //
public:
    //Path
    void setSearchPath(const std::string &path);
    const std::string& getSearchPath() const;

    //Load
    void loadEffect(const std::string &name);
    void loadMusic(const std::string &name);

    //Unload
    void unloadEffect(const std::string &name);
    void unloadMusic(const std::string &name);

    //Query
    bool isEffectLoaded(const std::string &name);
    bool isMusicLoaded(const std::string &name);


    // Private Methods //
private:
    EffectInfo& getEffectInfo(const std::string &name);
    std::string fullpath(const std::string &path);


    // iVars //
private:
    std::string m_searchPath;

    EffectMap m_effectsMap;
    MusicMap  m_musicsMap;
};

NS_LORE_END
#endif // __Lore_include_SoundManager_h__ //
