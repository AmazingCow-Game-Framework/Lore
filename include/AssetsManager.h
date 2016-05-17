
#ifndef __Lore_include_AssetsManager_h__
#define __Lore_include_AssetsManager_h__

//std
#include <string>
#include <map>
#include <utility>
//Lore
#include "GameCommon.h"

NS_LORE_BEGIN

class AssetsManager
{
    // Constants / Enums / Typdefs //
private:
    //Texture
    typedef std::map<std::string, SDL_Texture*> TextureMap;
    //Font
    typedef std::pair<std::string, int> FontValue;
    typedef std::map<FontValue, TTF_Font*> FontMap;

    // Singleton //
public:
    COREGAME_SINGLETON_OF(AssetsManager);
    COREGAME_DISALLOW_COPY_MOVE_ASSIGN(AssetsManager);
private:
    AssetsManager() {};

    // Init / Shutdown  //
public:
    void initialize(const std::string& searchPath);
    void shutdown();

    // Public Functions //
public:
    SDL_Texture* getTexture(const std::string &filename);
    TTF_Font*    getFont   (const std::string &filename, int size);

    // Private Functions //
private:
    SDL_Texture* loadTexture(const std::string &filename);
    TTF_Font*    loadFont(const std::string &filename, int size);

    std::string fullpath(const std::string &filename);

    // iVars //
private:
    std::string m_searchPath;

    TextureMap m_texturesMap;
    FontMap    m_fontsMap;
};

NS_LORE_END
#endif // __Lore_include_AssetsManager_h__ //
