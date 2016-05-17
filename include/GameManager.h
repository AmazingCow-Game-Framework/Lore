#ifndef __Lore_include_GameManager_h__
#define __Lore_include_GameManager_h__

//Lore
#include "Lore_Utils.h"
#include "Scene.h"

NS_LORE_BEGIN

class GameManager
{
    // Singleton //
public:
    COREGAME_SINGLETON_OF(GameManager);
    COREGAME_DISALLOW_COPY_MOVE_ASSIGNS(GameManager);
private:
    GameManager() {};


    // Init / Shutdown //
public:
    void initialize(int randomNumSeed, int targetFPS);
    void shutdown();


    // Scene Management //
public:
    void run(std::unique_ptr<Scene> scene);
    void changeScene(std::unique_ptr<Scene> scene);


    // Public Methods //
public:
    int getRandomNumber(int min, int max);
    int getTargetFPS() const;


    // Private Methods //
private:
    void update(float dt);
    void draw();
    void handleEvents();


    // iVars //
private:
    CoreRandom::Random m_random;

    int  m_targetFPS;
    bool m_running;

    std::unique_ptr<Scene> m_pScene;
};

NS_LORE_END
#endif // __Lore_include_GameManager_h__ //
