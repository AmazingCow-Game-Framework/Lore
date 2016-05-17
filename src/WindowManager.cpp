
//Header
#include "WindowManager.h"

//Usings
USING_NS_LORE


// Init / Shutdown //
void WindowManager::initialize(const std::string &caption,
                               int designWidth, int designHeight,
                               int windowWidth, int windowHeight,
                               Uint32 windowFlags,
                               Uint32 rendererFlags)
{
    //Set the vars.
    m_designWidth  = designWidth;
    m_designHeight = designHeight;
    m_windowWidth  = windowWidth;
    m_windowHeight = windowHeight;

    //COWTODO: Check the errors...
    //SDL
    SDL_Init(SDL_INIT_EVERYTHING);

    //Window
    m_pWindow = SDL_CreateWindow(caption.c_str(),
                                 SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                 windowWidth, windowHeight,
                                 windowFlags);

    //Renderer
    m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, rendererFlags);
}

void WindowManager::shutdown()
{
    SDL_DestroyRenderer(m_pRenderer);
    SDL_DestroyWindow(m_pWindow);
}

// Draw //
void WindowManager::clear(const SDL_Color &color)
{
    SDL_SetRenderDrawColor(m_pRenderer, color.r, color.g, color.b, 255);
    SDL_RenderClear(m_pRenderer);
}

void WindowManager::render()
{
    SDL_RenderPresent(m_pRenderer);
}


// Public Methods //
SDL_Renderer* WindowManager::getRenderer() const
{
    return m_pRenderer;
}

int WindowManager::getDesignWidth() const
{
    return m_designWidth;
}
int WindowManager::getDesignHeight() const
{
    return m_designHeight;
}
int WindowManager::getWindowWidth() const
{
    return m_windowWidth;
}
int WindowManager::getWindowHeight() const
{
    return m_windowHeight;
}


