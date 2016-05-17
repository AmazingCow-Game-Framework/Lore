#ifndef __Lore_include_Scene_h__
#define __Lore_include_Scene_h__

//Lore
#include "GameCommon.h"

NS_LORE_BEGIN

class Scene
{
    // CTOR / DTOR //
public:
    Scene() {}
    virtual ~Scene() {}


    // Load / Unload //
public:
    virtual void load  () { /* Empty */ }
    virtual void unload() { /* Empty */ }


    // Update / Draw // Handle Events //
public:
    virtual void update(float dt)
    { /* Empty */ }

    virtual void draw()
    { /* Empty */ }

    virtual void handleEvents(const SDL_Event &event)
    { /* Empty */ }
};

NS_LORE_END
#endif // __Lore_include_Scene_h__ //
