//Header
#include "../include/MathHelper.h"

//Usings
USING_NS_LORE


////////////////////////////////////////////////////////////////////////////////
// Public Methods                                                             //
////////////////////////////////////////////////////////////////////////////////
float MathHelper::clamp(float value, float min, float max)
{
    if(value > max) return max;
    if(value < min) return min;
    return value;
}
