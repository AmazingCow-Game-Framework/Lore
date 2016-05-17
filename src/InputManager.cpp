
//Header
#include "InputManager.h"
//std
#include <cstring>

//Usings
USING_NS_LORE;


// Init / Shutdown  //
void InputManager::initialize()
{
    m_pCurrKeys = const_cast<Uint8 *>(SDL_GetKeyboardState(&m_numKeys));
    m_pPrevKeys = new Uint8[m_numKeys];
}

void InputManager::shutdown()
{
    delete m_pPrevKeys;
}


// Public Methods //
void InputManager::update()
{
    std::memcpy(m_pPrevKeys, m_pCurrKeys, sizeof(Uint8) * m_numKeys);
    m_pCurrKeys = const_cast<Uint8 *>(SDL_GetKeyboardState(nullptr));
}

bool InputManager::isKeyDown(int scanCode)
{
    return m_pCurrKeys[scanCode];
}
bool InputManager::isKeyUp(int scanCode)
{
    return !m_pCurrKeys[scanCode];
}

bool InputManager::wasKeyDown(int scanCode)
{
    return m_pPrevKeys[scanCode] && isKeyUp(scanCode);
}
bool InputManager::wasKeyUp(int scanCode)
{
    return !m_pPrevKeys[scanCode] && isKeyDown(scanCode);
}

bool InputManager::isKeyClick(int scanCode)
{
    return isKeyUp(scanCode) && wasKeyDown(scanCode);
}
