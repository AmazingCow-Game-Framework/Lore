
//Header
#include "../include/SoundManager.h"
//Lore
#include "../include/ErrorControl.h"
//Lore_Private
#include "./private/include/Log.h"

//Usings
USING_NS_LORE;
USING_NS_COREGAME;


////////////////////////////////////////////////////////////////////////////////
// Constants                                                                  //
////////////////////////////////////////////////////////////////////////////////
//Class
const int SoundManager::kPlayForever = -1;
const int SoundManager::kPlayOneTime =  0;

//Internal
constexpr int kFirstAvailableChannel = -1;


////////////////////////////////////////////////////////////////////////////////
// Init / Shutdown                                                            //
////////////////////////////////////////////////////////////////////////////////
void SoundManager::initialize(const std::string &searchPath,
                              int    frequency,
                              Uint16 format,
                              int    channels,
                              int    chunksize)

{
    //Only initialize SDL_Audio if it wasn't initialized yet...
    if(SDL_WasInit(SDL_INIT_AUDIO) < 0)
    {
        if(SDL_Init(SDL_INIT_AUDIO) < 0)
        {
            ErrorControl::DieIfNeeded(
                ErrorControl::LORE_ERROR_DIE_ON_SOUND_MANAGER_ERROR |
                ErrorControl::LORE_ERROR_DIE_ON_SDL_ERROR,
                "SoundManager::initialize",
                "SDL Audio cannot be initialized - SDL error %s",
                SDL_GetError()
            );
        }
    }

    //Open the Mixer Audio.
    //COWTODO: Investigate a bug that is messing everything \
    //         if this function wasn't called.
    Mix_SetSoundFonts(nullptr);

    if(Mix_OpenAudio(frequency, format, channels, chunksize) < 0)
    {
        ErrorControl::DieIfNeeded(
                ErrorControl::LORE_ERROR_DIE_ON_SOUND_MANAGER_ERROR |
                ErrorControl::LORE_ERROR_DIE_ON_SDL_ERROR,
                "SoundManager::initialize",
                "SDL_Mixer cannot be initialized - Mixer error %s",
                Mix_GetError()
        );
    }

    //Update the search path.
    setSearchPath(searchPath);
}

void SoundManager::shutdown()
{
    Mix_CloseAudio();
    //COWTODO: DO the correct umload.
}


////////////////////////////////////////////////////////////////////////////////
// Volume Methods                                                             //
////////////////////////////////////////////////////////////////////////////////
void SoundManager::setVolume(int vol)
{

}

int SoundManager::getVolume() const
{

}


////////////////////////////////////////////////////////////////////////////////
// Player Methods                                                             //
////////////////////////////////////////////////////////////////////////////////
//Effects
void SoundManager::playEffect(const std::string &name,
                              int loopTimes /* = kPlayOneTime */)
{
    auto fullname   = fullpath(name);
    auto effectInfo = getEffectInfo(fullname);

    effectInfo.playChannel = Mix_PlayChannel(kFirstAvailableChannel,
                                             effectInfo.chunk,
                                             loopTimes);
}

void SoundManager::stopEffect(const std::string &name)
{
    auto fullname   = fullpath(name);
    auto effectInfo = getEffectInfo(fullname);

    Mix_HaltChannel(effectInfo.playChannel);
}

void SoundManager::stopAllEffects()
{

}

//Music
void SoundManager::playMusic(const std::string &name,
                             int loopTimes /* = kPlayForerver */)
{

}

void SoundManager::stopMusic()
{

}


////////////////////////////////////////////////////////////////////////////////
// Load / Unload Methods                                                      //
////////////////////////////////////////////////////////////////////////////////
//Query
void SoundManager::setSearchPath(const std::string &path)
{
    m_searchPath = path;
    if(m_searchPath.back() != '/')
        m_searchPath += "/";
}

const std::string& SoundManager::getSearchPath() const
{
    return m_searchPath;
}


//Load
void SoundManager::loadEffect(const std::string &name)
{
    auto fullname = fullpath(name);

    PVT_LORE_DLOG_DEBUG(
        "SoundManager::loadEffect",
        "Loading effect (%s)",
        fullname.c_str()
    );

    if(isEffectLoaded(fullname))
    {
        PVT_LORE_DLOG_WARNING(
            "SoundManager::loadEffect",
            "Trying to load a already load effect (%s)",
            fullname.c_str()
        );

        return;
    }

    auto effect = Mix_LoadWAV(fullname.c_str());
    if(!effect)
    {
        ErrorControl::DieIfNeeded(
            ErrorControl::LORE_ERROR_DIE_ON_SOUND_MANAGER_ERROR,
            "SoundManager::loadEffect",
            "Failed to load effect - EffectName: (%s) - Mix Error (%s)",
            fullname.c_str(),
            Mix_GetError()
        );
    }

    m_effectsMap[fullname] = EffectInfo { effect, -1 };
}

void SoundManager::loadMusic(const std::string &name)
{
    //COWTODO: Implement.
}

//Unload
void SoundManager::unloadEffect(const std::string &name)
{
    //COWTODO: Implement.
}

void SoundManager::unloadMusic(const std::string &name)
{
    //COWTODO: Implement.
}

//Query
bool SoundManager::isEffectLoaded(const std::string &name)
{
    return m_effectsMap.find(name) != std::end(m_effectsMap);
}

bool SoundManager::isMusicLoaded(const std::string &name)
{
    //COWTODO: Implement.
}


////////////////////////////////////////////////////////////////////////////////
// Private Methods                                                            //
////////////////////////////////////////////////////////////////////////////////
SoundManager::EffectInfo& SoundManager::getEffectInfo(const std::string &name)
{
    //COWTODO: Handle cases that effect isn't loaded.
    return m_effectsMap[name];
}

std::string SoundManager::fullpath(const std::string &path)
{
    return m_searchPath + path;
}
