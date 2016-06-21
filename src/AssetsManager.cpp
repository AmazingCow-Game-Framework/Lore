//----------------------------------------------------------------------------//
//               █      █                                                     //
//               ████████                                                     //
//             ██        ██                                                   //
//            ███  █  █  ███        AssetsManager.cpp                         //
//            █ █        █ █        Lore                                      //
//             ████████████                                                   //
//           █              █       Copyright (c) 2016                        //
//          █     █    █     █      AmazingCow - www.AmazingCow.com           //
//          █     █    █     █                                                //
//           █              █       N2OMatt - n2omatt@amazingcow.com          //
//             ████████████         www.amazingcow.com/n2omatt                //
//                                                                            //
//                  This software is licensed as GPLv3                        //
//                 CHECK THE COPYING FILE TO MORE DETAILS                     //
//                                                                            //
//    Permission is granted to anyone to use this software for any purpose,   //
//   including commercial applications, and to alter it and redistribute it   //
//               freely, subject to the following restrictions:               //
//                                                                            //
//     0. You **CANNOT** change the type of the license.                      //
//     1. The origin of this software must not be misrepresented;             //
//        you must not claim that you wrote the original software.            //
//     2. If you use this software in a product, an acknowledgment in the     //
//        product IS HIGHLY APPRECIATED, both in source and binary forms.     //
//        (See opensource.AmazingCow.com/acknowledgment.html for details).    //
//        If you will not acknowledge, just send us a email. We'll be         //
//        *VERY* happy to see our work being used by other people. :)         //
//        The email is: acknowledgment_opensource@AmazingCow.com              //
//     3. Altered source versions must be plainly marked as such,             //
//        and must not be misrepresented as being the original software.      //
//     4. This notice may not be removed or altered from any source           //
//        distribution.                                                       //
//     5. Most important, you must have fun. ;)                               //
//                                                                            //
//      Visit opensource.amazingcow.com for more open-source projects.        //
//                                                                            //
//                                  Enjoy :)                                  //
//----------------------------------------------------------------------------//

//Header
#include "../include/AssetsManager.h"
//std
#include <sys/types.h> //For stat(2)
#include <sys/stat.h>  //For stat(2)
#include <unistd.h>    //For stat(2)
#include <errno.h>

//Lore
#include "../include/SDLHelpers.h"
#include "../include/WindowManager.h"

//Usings
USING_NS_LORE;


////////////////////////////////////////////////////////////////////////////////
// Init / Shutdown                                                            //
////////////////////////////////////////////////////////////////////////////////
void AssetsManager::initialize(const std::string& searchPath)
{
    AssetsManager::initialize({searchPath});
}

void AssetsManager::initialize(const std::vector<std::string> &searchPaths)
{
    for(auto path : searchPaths)
    {
        struct stat status;
        stat(path.c_str(), &status);

        if(S_ISDIR(status.st_mode))
        {
            m_searchPath = path;
            break;
        }
    }

    if(m_searchPath.back() != '/')
        m_searchPath += "/";


    //COWTODO: Check errors.
    IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
    TTF_Init();
}

void AssetsManager::shutdown()
{
}


////////////////////////////////////////////////////////////////////////////////
// Public Functions                                                           //
////////////////////////////////////////////////////////////////////////////////
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

std::string AssetsManager::fullpath(const std::string &filename)
{
    return m_searchPath + filename;
}


////////////////////////////////////////////////////////////////////////////////
// Private Functions                                                          //
////////////////////////////////////////////////////////////////////////////////
Texture::SPtr AssetsManager::loadTexture(const std::string &filename)
{
    auto sdlTexture = SDLHelpers::load_texture_from_file(fullpath(filename));
    auto texture    = std::make_shared<Texture>(sdlTexture);

    m_texturesMap[filename] = texture;

    return texture;
}

Font::SPtr AssetsManager::loadFont(const std::string &filename,
                                   int size)
{
    auto sdlFont   = SDLHelpers::load_font_from_file(fullpath(filename), size);
    auto font      = std::make_shared<Font>(sdlFont);
    auto fontValue = std::make_pair(filename, size);

    m_fontsMap[fontValue] = font;

    return font;
}

