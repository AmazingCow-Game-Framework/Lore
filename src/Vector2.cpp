//Header
#include "../include/Vector2.h"

//Usings
USING_NS_LORE


// Static Methods //
const Vector2& Vector2::Zero()
{
    static Vector2 s_zeroRect;
    return s_zeroRect;
}

const Vector2& Vector2::One()
{
    static Vector2 s_oneRect(1, 1);
    return s_oneRect;
}


// CTOR / DTOR //
Vector2::Vector2() :
    Vector2(0, 0)
{
    //Empty...
}

Vector2::Vector2(float value) :
    Vector2(value, value)
{
    //Empty...
}

Vector2::Vector2(float x, float y) :
    m_x(x),
    m_y(y)
{
    //Empty...
}



// Public Methods //
//
void Vector2::setX(float x)
{
    m_x = x;
}
float Vector2::getX() const
{
    return m_x;
}

void  Vector2::setY(float y)
{
    m_y = y;
}
float Vector2::getY() const
{
    return m_y;
}

// Operators //
NS_LORE_BEGIN
bool operator ==(const Vector2 &lhs, const Vector2 &rhs)
{
    return lhs.m_x == rhs.m_x &&
           lhs.m_y == rhs.m_y;
}
bool operator !=(const Vector2 &lhs, const Vector2 &rhs)
{
    return !(lhs == rhs);
}
NS_LORE_END
