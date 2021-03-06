//----------------------------------------------------------------------------//
//               █      █                                                     //
//               ████████                                                     //
//             ██        ██                                                   //
//            ███  █  █  ███        WindowManager.h                           //
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

#ifndef __Lore_include_WindowManager_h__
#define __Lore_include_WindowManager_h__

//Lore
#include "Lore_Utils.h"
#include "Color.h"
#include "Rectangle.h"


NS_LORE_BEGIN

class WindowManager
{
    // Singleton //
public:
    COREGAME_SINGLETON_OF(WindowManager);
    COREGAME_DISALLOW_COPY_MOVE_ASSIGNS(WindowManager);
private:
    WindowManager() {};

    // Init / Shutdown //
public:
    void initialize(const std::string &caption,
                    int designWidth, int designHeight,
                    int windowWidth, int windowHeight,
                    Uint32 windowFlags,
                    Uint32 rendererFlags);

    void shutdown();


    // Draw //
public:
    void clear();
    void render();


    // Public Methods //
public:
    //Renderer
    SDL_Renderer* getRenderer() const;

    //Design Size
    const Rectangle& getDesignRect() const;
    int getDesignWidth () const;
    int getDesignHeight() const;

    //Window Size
    const Rectangle& getWindowRect() const;
    int getWindowWidth () const;
    int getWindowHeight() const;

    //Clear color
    void setClearColor(const Color &color);
    const Color& getClearColor() const;

    //Icon
    void setIcon(const std::string &filename);


    // iVars //
private:
    SDL_Window   *m_pWindow;
    SDL_Renderer *m_pRenderer;

    Rectangle m_designRect;
    Rectangle m_windowRect;

    Color m_clearColor;
};

NS_LORE_END
#endif // __Lore_include_WindowManager_h__ //
