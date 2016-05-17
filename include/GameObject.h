#ifndef __Lore_include_GameObject_h__
#define __Lore_include_GameObject_h__

//Lore
#include "Lore_Utils.h"
#include "IUpdatable.h"


NS_LORE_BEGIN

class GameObject : public IUpdatable
{
    // CTOR / DTOR //
public:
    GameObject();
    virtual ~GameObject();

    // Update / Draw //
public:
    virtual void update(float dt) = 0;
    virtual void draw  ()         = 0;
};

NS_LORE_END
#endif // __Lore_include_GameObject_h__ //
