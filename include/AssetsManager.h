//----------------------------------------------------------------------------//
//               █      █                                                     //
//               ████████                                                     //
//             ██        ██                                                   //
//            ███  █  █  ███        AssetsManager.h                           //
//            █ █        █ █        Lore                                      //
//             ████████████                                                   //
//           █              █       Copyright (c) 2016, 2017                  //
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

#ifndef __Lore_include_AssetsManager_h__
#define __Lore_include_AssetsManager_h__

//std
#include <map>
#include <string>
#include <utility> //pair
//Lore
#include "Lore_Utils.h"
#include "Font.h"
#include "Texture.h"


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
    void initialize(const std::vector<std::string> &searchPaths);

    void shutdown();


    // Public Functions //
public:
    Texture::SPtr getTexture(const std::string &filename);
    Font::SPtr    getFont   (const std::string &filename, int size);

    std::string fullpath(const std::string &filename) const;

    std::vector<std::string> checkFilesExists(
        const std::vector<std::string> &filesList) const;


    // Private Functions //
private:
    Texture::SPtr loadTexture(const std::string &filename);
    Font::SPtr    loadFont(const std::string &filename, int size);


    // iVars //
private:
    std::string m_searchPath;

    TextureMap m_texturesMap;
    FontMap    m_fontsMap;
};

NS_LORE_END
#endif // __Lore_include_AssetsManager_h__ //
