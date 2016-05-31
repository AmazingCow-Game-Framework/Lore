
//Header
#include "../include/SoundManager.h"

//Usings
USING_NS_LORE;
USING_NS_COREGAME;


////////////////////////////////////////////////////////////////////////////////
// Constants                                                                  //
////////////////////////////////////////////////////////////////////////////////
const int SoundManager::kPlayForever = -1;


////////////////////////////////////////////////////////////////////////////////
// Init / Shutdown                                                            //
////////////////////////////////////////////////////////////////////////////////
void SoundManager::initialize(int    frequency,
                              Uint16 format,
                              int    channels,
                              int    chunksize)

{
    // //Only intialize SDL_Audio if it wasn't initialized yet...
    if(SDL_WasInit(SDL_INIT_AUDIO) < 0)
    {
        //COWTODO: Handle errors...
        if(SDL_Init(SDL_INIT_AUDIO) < 0)
        {
            COREGAME_DLOG(Log::Type::Error,
                      "SDL Audio cannot be initialized - SDL error %s",
                      SDL_GetError());
        }
    }

    //Open the Mixer Audio.
    //COWTODO: Investigate a bug that is messing everything \
    //         if this function wasn't called.
    Mix_SetSoundFonts(nullptr);
    if(Mix_OpenAudio(frequency, format, channels, chunksize) <= 0)
    {
        //COWTODO: Handle errors...
        COREGAME_DLOG(Log::Type::Error,
                      "SDL_Mixer cannot be initialized - Mixer error %s",
                      Mix_GetError());
    }
}

void SoundManager::shutdown()
{
    Mix_CloseAudio();
    for(auto &item : m_effectsMap)
        unloadEffect(item.first);
}


////////////////////////////////////////////////////////////////////////////////
// Player Methods                                                             //
////////////////////////////////////////////////////////////////////////////////
void SoundManager::setVolume(int vol)
{

}

int SoundManager::getVolume() const
{

}

void SoundManager::playEffect(const std::string &name,
                              int loopTimes /* = 1 */)
{
    Mix_PlayChannel(-1, m_effectsMap[name], loopTimes);
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


////////////////////////////////////////////////////////////////////////////////
// Load / Unload Methods                                                      //
////////////////////////////////////////////////////////////////////////////////
void SoundManager::loadEffect(const std::string &name)
{
    if(isEffectLoaded(name))
    {
        COREGAME_DLOG(Log::Type::Warning, "%s - %s"
                      "Trying to load a effect that is already loaded",
                      StringUtils::format("Effect name: (%s)", name.c_str())
        );

        return;
    }

    //COWTODO: Handle errors.
    auto effect = Mix_LoadWAV(name.c_str());
    if(!effect)
    {
        COREGAME_DLOG(Log::Type::Error,
                      "Failed to load Effect - EffectName: (%s) - Mix Error (%s)",
                      name.c_str(),
                      Mix_GetError());
    }

    m_effectsMap[name] = effect;
}

void SoundManager::loadMusic(const std::string &name)
{
    //COWTODO: Implement.
}

void SoundManager::unloadEffect(const std::string &name)
{
    //COWTODO: Implement.
}

void SoundManager::unloadMusic(const std::string &name)
{
    //COWTODO: Implement.
}

bool SoundManager::isEffectLoaded(const std::string &name)
{
    return m_effectsMap.find(name) != std::end(m_effectsMap);
}

bool SoundManager::isMusicLoaded(const std::string &name)
{
    //COWTODO: Implement.
}

