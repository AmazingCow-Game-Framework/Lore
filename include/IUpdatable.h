#ifndef __Lore_include_IUpdatable_h__
#define __Lore_include_IUpdatable_h__

//Lore
#include "Lore_Utils.h"


NS_LORE_BEGIN

class IUpdatable
{
    // CTOR / DTOR //
public:
    IUpdatable()          { /* Empty */ }
    virtual ~IUpdatable() { /* Empty */ }

    // Public Methods //
public:
    virtual void update(float dt) = 0;
};

NS_LORE_END
#endif // __Lore_include_IUpdatable_h__ //
