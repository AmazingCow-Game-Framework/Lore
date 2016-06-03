//Header
#include "../include/Color.h"

//Usings
USING_NS_LORE


// Static Methods //
const Color& Color::White()
{
    static Color s_white;
    return s_white;
}

const Color& Color::Black()
{
    static Color s_black(0, 0, 0);
    return s_black;
}

const Color& Color::Transparent()
{
    static Color s_transparent(0, 0, 0, 0);
    return s_transparent;
}


// CTOR //
Color::Color() :
    Color(255, 255, 255, 255) // White //
{
    //Empty...
}

Color::Color(int red, int green, int blue, int alpha /* = 255 */) :
    r(red),
    g(green),
    b(blue),
    a(alpha)
{
    //Empty...
}


// Public Methods //
void Color::setRGBA(int red, int green, int blue, int alpha /* = 255 */)
{
    r = red;
    g = green;
    b = blue;
    a = alpha;
}
