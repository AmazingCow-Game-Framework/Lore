//----------------------------------------------------------------------------//
//               █      █                                                     //
//               ████████                                                     //
//             ██        ██                                                   //
//            ███  █  █  ███        Font.cpp                                  //
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
#include "../include/Font.h"
//Lore
#include "../include/SDLHelpers.h"

//Usings
USING_NS_LORE;


// CTOR //
Font::Font(TTF_Font *font) :
    m_pFont(font)
{
    //Empty...
}

Font::~Font()
{
    COREGAME_DLOG(CoreGame::Log::Type::Debug4, "Lore::Font DTOR");

    TTF_CloseFont(m_pFont);
    m_pFont = nullptr;
}


// Public Methods //
Texture::SPtr Font::prepareTexture(const std::string &str,
                                   const Color &fgColor,
                                   const Color &bgColor)
{
    if(str.empty())
        return std::make_shared<Texture>(SDLHelpers::make_texture_empty());


    auto tmp_surface = TTF_RenderText_Solid(m_pFont,
                                             str.c_str(),
                                             SDLHelpers::make_color(fgColor));
                                             //{0xff, 0x0, 0xff, 0x05});
                                             //SDLHelpers::make_color(bgColor));
    SDL_SetSurfaceBlendMode(tmp_surface, SDL_BLENDMODE_BLEND);

    auto sdl_texture = SDLHelpers::make_texture_free(tmp_surface);
    SDL_SetTextureBlendMode(sdl_texture, SDL_BLENDMODE_BLEND);

    return std::make_shared<Texture>(sdl_texture);
}
