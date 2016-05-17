#ifndef __Lore_include_InputManager_h__
#define __Lore_include_InputManager_h__

//Lore
#include "GameCommon.h"
#include "Scene.h"

NS_LORE_BEGIN

class InputManager
{
    // Singleton //
public:
    COREGAME_SINGLETON_OF(InputManager);
    COREGAME_DISALLOW_COPY_MOVE_ASSIGN(InputManager);
private:
    InputManager() {};


    // Init / Shutdown //
public:
    void initialize();
    void shutdown();

    // Public Methods //
public:
    void update();

    bool isKeyDown(int scanCode);
    bool isKeyUp  (int scanCode);

    bool wasKeyDown(int scanCode);
    bool wasKeyUp  (int scanCode);

    bool isKeyClick(int scanCode);

    // iVars //
private:
    Uint8 *m_pPrevKeys;
    Uint8 *m_pCurrKeys;
    int    m_numKeys;
};

NS_LORE_END
#endif // __Lore_include_InputManager_h__ //
