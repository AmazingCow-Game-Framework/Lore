#ifndef __Lore_include_IDrawable_h__
#define __Lore_include_IDrawable_h__

//Lore
#include "Lore_Utils.h"

NS_LORE_BEGIN

class IDrawable
{
    // CTOR / DTOR //
public:
    IDrawable()          { /* Empty */  }
    virtual ~IDrawable() { /* Empty */ }

    // Public Methods //
public:
    virtual void draw() = 0;
};

NS_LORE_END
#endif // __Lore_include_IDrawable_h__ //
