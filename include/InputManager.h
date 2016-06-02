#ifndef __Lore_include_InputManager_h__
#define __Lore_include_InputManager_h__

//Lore
#include "Lore_Utils.h"


NS_LORE_BEGIN

class InputManager
{
    // Enums //
public:
    typedef Uint8 KeyScanCodeType;


    // Singleton //
public:
    COREGAME_SINGLETON_OF(InputManager);
    COREGAME_DISALLOW_COPY_MOVE_ASSIGNS(InputManager);
private:
    InputManager() {};


    // Init / Shutdown //
public:
    void initialize();
    void shutdown();


    // Public Methods //
public:
    void update();

    bool isKeyDown(KeyScanCodeType scanCode);
    bool isKeyUp  (KeyScanCodeType scanCode);

    bool wasKeyDown(KeyScanCodeType scanCode);
    bool wasKeyUp  (KeyScanCodeType scanCode);

    bool isKeyClick(KeyScanCodeType scanCode);


    // iVars //
private:
    KeyScanCodeType *m_pPrevKeys;
    KeyScanCodeType *m_pCurrKeys;

    int m_numKeys;
};

NS_LORE_END
#endif // __Lore_include_InputManager_h__ //
