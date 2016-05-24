
#ifndef __Lore_include_WindowManager_h__
#define __Lore_include_WindowManager_h__

//Lore
#include "Lore_Utils.h"
#include "Color.h"

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
    SDL_Renderer* getRenderer() const;

    int getDesignWidth () const;
    int getDesignHeight() const;
    int getWindowWidth () const;
    int getWindowHeight() const;

    void setClearColor(const Color &color);

    // iVars //
private:
    SDL_Window   *m_pWindow;
    SDL_Renderer *m_pRenderer;

    int m_designWidth;
    int m_designHeight;
    int m_windowWidth;
    int m_windowHeight;
};

NS_LORE_END
#endif // __Lore_include_WindowManager_h__ //
