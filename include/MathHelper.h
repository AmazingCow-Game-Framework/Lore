#ifndef __Lore_include_MathHelper_h__
#define __Lore_include_MathHelper_h__

//Lore
#include "Lore_Utils.h"


NS_LORE_BEGIN

class MathHelper
{
    // Make this class static //
private:
    COREGAME_DISALLOW_CTOR_COPY_MOVE_ASSIGNS(MathHelper);

    // Public Methods //
public:
    static float clamp(float value, float min, float max);
};

NS_LORE_END
#endif // __Lore_include_MathHelper_h__ //


