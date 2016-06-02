
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
