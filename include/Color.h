#ifndef __Lore_include_Color_h__
#define __Lore_include_Color_h__

//Lore
#include "Lore_Utils.h"


NS_LORE_BEGIN

class Color
{
    // Static Methods //
public:
    static const Color& White      ();
    static const Color& Black      ();
    static const Color& Transparent();


    // CTOR //
public:
    Color();
    Color(int red, int green, int blue, int alpha = 255);


    // iVars //
public:
    int r, g, b, a;
};

NS_LORE_END
#endif // __Lore_include_Color_h__ //


