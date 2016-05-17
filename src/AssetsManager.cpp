
//Header
#include "AssetsManager.h"
//Lore
#include "WindowManager.h"

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
SDL_Texture* AssetsManager::getTexture(const std::string &filename)
{
    auto it = m_texturesMap.find(filename);
    if(it == std::end(m_texturesMap))
        return loadTexture(filename);

    return it->second;
}

TTF_Font* AssetsManager::getFont(const std::string &filename, int size)
{
    auto it = m_fontsMap.find(std::make_pair(filename, size));
    if(it == std::end(m_fontsMap))
        return loadFont(filename, size);

    return it->second;
}


// Private Functions //
SDL_Texture* AssetsManager::loadTexture(const std::string &filename)
{
    auto renderer = WindowManager::instance()->getRenderer();

    //COWTODO: Handle errors...
    auto surface = IMG_Load(fullpath(filename).c_str());
    auto texture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_FreeSurface(surface);

    m_texturesMap[filename] = texture;
    return texture;
}

TTF_Font* AssetsManager::loadFont(const std::string &filename,
                                                 int size)
{
    //COWTODO: Handle errors.
    auto font = TTF_OpenFont(fullpath(filename).c_str(), size);
    m_fontsMap[std::make_pair(filename, size)] = font;

    return font;
}

std::string AssetsManager::fullpath(const std::string &filename)
{
    return m_searchPath + filename;
}
