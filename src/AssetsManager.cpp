
//Header
#include "../include/AssetsManager.h"
//Lore
#include "../include/WindowManager.h"

//Usigns
USING_NS_LORE;


// Init / Shutdown  //
void AssetsManager::initialize(const std::string& searchPath)
{
    m_searchPath = searchPath;
    if(m_searchPath.back() != '/')
        m_searchPath += "/";

    //COWTODO: Check errors.
    TTF_Init();
}

void AssetsManager::shutdown()
{
}


// Public Functions //
Texture::SPtr AssetsManager::getTexture(const std::string &filename)
{
    auto it = m_texturesMap.find(filename);
    if(it == std::end(m_texturesMap))
        return loadTexture(filename);

    return it->second;
}

Font::SPtr AssetsManager::getFont(const std::string &filename, int size)
{
    auto it = m_fontsMap.find(std::make_pair(filename, size));
    if(it == std::end(m_fontsMap))
        return loadFont(filename, size);

    return it->second;
}


// Private Functions //
Texture::SPtr AssetsManager::loadTexture(const std::string &filename)
{
    auto texture = std::make_shared<Texture>(fullpath(filename));
    m_texturesMap[filename] = texture;
    return texture;
}

Font::SPtr AssetsManager::loadFont(const std::string &filename,
                                                 int size)
{
}

std::string AssetsManager::fullpath(const std::string &filename)
{
    return m_searchPath + filename;
}
