
#ifndef __Lore_include_AssetsManager_h__
#define __Lore_include_AssetsManager_h__

//std
#include <string>
#include <map>
#include <utility>
//Lore
#include "Lore_Utils.h"
#include "Texture.h"
#include "Font.h"

NS_LORE_BEGIN

class AssetsManager
{
    // Constants / Enums / Typdefs //
private:
    //Texture
    typedef std::map<std::string, Texture::SPtr> TextureMap;
    //Font
    typedef std::pair<std::string, int>     FontValue;
    typedef std::map<FontValue, Font::SPtr> FontMap;

    // Singleton //
public:
    COREGAME_SINGLETON_OF(AssetsManager);
    COREGAME_DISALLOW_COPY_MOVE_ASSIGNS(AssetsManager);
private:
    AssetsManager() {};

    // Init / Shutdown  //
public:
    void initialize(const std::string& searchPath);
    void shutdown();

    // Public Functions //
public:
    Texture::SPtr getTexture(const std::string &filename);
    Font::SPtr    getFont   (const std::string &filename, int size);

    // Private Functions //
private:
    Texture::SPtr loadTexture(const std::string &filename);
    Font::SPtr    loadFont(const std::string &filename, int size);

    std::string fullpath(const std::string &filename);

    // iVars //
private:
    std::string m_searchPath;

    TextureMap m_texturesMap;
    FontMap    m_fontsMap;
};

NS_LORE_END
#endif // __Lore_include_AssetsManager_h__ //
