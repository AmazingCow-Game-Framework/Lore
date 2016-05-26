
//Header
#include "../include/WindowManager.h"

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
    m_designRect = Rectangle(0, 0, designWidth, designHeight);
    m_windowRect = Rectangle(0, 0, windowWidth, windowHeight);


    //COWTODO: Check the errors...
    //SDL
    SDL_Init(SDL_INIT_EVERYTHING);

    //Window
    m_pWindow = SDL_CreateWindow(caption.c_str(),
                                 SDL_WINDOWPOS_CENTERED,
                                 SDL_WINDOWPOS_CENTERED,
                                 m_windowRect.getSize().x,
                                 m_windowRect.getSize().y,
                                 windowFlags);

    //Renderer
    m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, rendererFlags);

    setClearColor(Color::Black());
}

void WindowManager::shutdown()
{
    SDL_DestroyRenderer(m_pRenderer);
    SDL_DestroyWindow  (m_pWindow);
}

// Draw //
void WindowManager::clear()
{
    SDL_RenderClear(m_pRenderer);
}

void WindowManager::render()
{
    SDL_RenderPresent(m_pRenderer);
}


// Public Methods //
//Renderer
SDL_Renderer* WindowManager::getRenderer() const
{
    return m_pRenderer;
}

//Design Size
const Rectangle& WindowManager::getDesignRect() const
{
    return m_designRect;
}

int WindowManager::getDesignWidth() const
{
    return m_designRect.getWidth();
}

int WindowManager::getDesignHeight() const
{
    return m_designRect.getHeight();
}

//Window Size
const Rectangle& WindowManager::getWindowRect() const
{
    return m_windowRect;
}

int WindowManager::getWindowWidth() const
{
    return m_windowRect.getWidth();
}

int WindowManager::getWindowHeight() const
{
    return m_windowRect.getHeight();
}

//Clear color
void WindowManager::setClearColor(const Color &color)
{
    m_clearColor = color;
    SDL_SetRenderDrawColor(m_pRenderer,
                           color.r,
                           color.g,
                           color.b,
                           255);
}

const Color& WindowManager::getClearColor() const
{
    return m_clearColor;
}
