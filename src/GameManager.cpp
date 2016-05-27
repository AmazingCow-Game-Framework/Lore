
//Header
#include "../include/GameManager.h"
//Lore
#include "../include/WindowManager.h"
#include "../include/InputManager.h"

//Usings
USING_NS_LORE;

// Init / Shutdown  //
void GameManager::initialize(int randomNumSeed, int targetFPS)
{
    m_random.reseed(randomNumSeed);

    m_targetFPS = targetFPS;
    m_running   = true;
}

void GameManager::shutdown()
{

}

// Scene Management //
void GameManager::run(std::unique_ptr<Scene> scene)
{
    changeScene(std::move(scene));

    //Framerate stuff.
    float  delayTime  = (1000.0f / m_targetFPS);
    Uint32 frameStart = 0;
    Uint32 frameTime  = 0;

    while(m_running)
    {
        frameStart = SDL_GetTicks();

        handleEvents();
        update(1.0f / m_targetFPS);
        draw();

        frameTime = SDL_GetTicks() - frameStart;
        if(frameTime < delayTime)
            SDL_Delay(static_cast<Uint32>(delayTime - frameTime));
    }
}

void GameManager::changeScene(std::unique_ptr<Scene> scene)
{
    if(m_pScene)
        m_pScene->unload();

    m_pScene = std::move(scene);
    m_pScene->load();
}


// Public Methods //
int GameManager::getRandomNumber(int min, int max)
{
    return m_random.next(min, max);
}

bool GameManager::getRandomBool()
{
    return m_random.nextBool();
}

int GameManager::getTargetFPS() const
{
    return m_targetFPS;
}


// Private Methods //
void GameManager::update(float dt)
{
    m_pScene->update(dt);
}

void GameManager::draw()
{
    auto win = WindowManager::instance();

    win->clear();
        m_pScene->draw();
    win->render();
}

void GameManager::handleEvents()
{
    InputManager::instance()->update();

    static SDL_Event s_event;
    while(SDL_PollEvent(&s_event))
    {
        if(s_event.type == SDL_QUIT)
            m_running = false;
    }
}
