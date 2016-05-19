//Header
#include "../include/Vector2.h"

//Usings
USING_NS_LORE

////////////////////////////////////////////////////////////////////////////////
// Static Methods                                                             //
////////////////////////////////////////////////////////////////////////////////
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

const Vector2& Vector2::UnitX()
{
    static Vector2 s_unitX(1, 0);
    return s_unitX;
}
const Vector2& Vector2::UnitY()
{
    static Vector2 s_unitY(0, 1);
    return s_unitY;
}


////////////////////////////////////////////////////////////////////////////////
// CTOR / DTOR                                                                //
////////////////////////////////////////////////////////////////////////////////
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
    x(x),
    y(y)
{
    //Empty...
}


////////////////////////////////////////////////////////////////////////////////
// Public Methods                                                             //
////////////////////////////////////////////////////////////////////////////////
void Vector2::setX(float x)
{
    this->x = x;
}

float Vector2::getX() const
{
    return x;
}

void Vector2::setY(float y)
{
    this->y = y;
}

float Vector2::getY() const
{
    return y;
}

////////////////////////////////////////////////////////////////////////////////
// Operators                                                                  //
////////////////////////////////////////////////////////////////////////////////
//Friends
NS_LORE_BEGIN

//Comparisons
bool operator ==(const Vector2 &lhs, const Vector2 &rhs)
{
    return lhs.x == rhs.x &&
           lhs.y == rhs.y;
}

bool operator !=(const Vector2 &lhs, const Vector2 &rhs)
{
    return !(lhs == rhs);
}


//Add / Subtract - Vectors
Vector2 operator +(const Vector2 &lhs, const Vector2 &rhs)
{
    return Vector2(lhs.x + rhs.x,
                   lhs.y + rhs.y);
}

Vector2 operator -(const Vector2 &lhs, const Vector2 &rhs)
{
    return Vector2(lhs.x - rhs.x,
                   lhs.y - rhs.y);
}


//Add / Subtract - Scalars
Vector2 operator +(const Vector2 &lhs, float rhs)
{
    return Vector2(lhs.x + rhs,
                   lhs.y + rhs);
}

Vector2 operator -(const Vector2 &lhs, float rhs)
{
    return Vector2(lhs.x - rhs,
                   lhs.y - rhs);
}


Vector2 operator +(float lhs, const Vector2 &rhs)
{
    return Vector2(lhs + rhs.x,
                   lhs + rhs.y);
}

Vector2 operator -(float lhs, const Vector2 &rhs)
{
    return Vector2(lhs - rhs.x,
                   lhs - rhs.y);
}


//Multiply / Divide - Vectors
Vector2 operator *(const Vector2 &lhs, const Vector2 &rhs)
{
    return Vector2(lhs.x * rhs.x,
                   lhs.y * rhs.y);
}

Vector2 operator /(const Vector2 &lhs, const Vector2 &rhs)
{
    return Vector2(lhs.x / rhs.x,
                   lhs.y / rhs.y);
}


//Multiply / Divide - Scalars
Vector2 operator *(const Vector2 &lhs, float rhs)
{
    return Vector2(lhs.x * rhs,
                   lhs.y * rhs);
}

Vector2 operator /(const Vector2 &lhs, float rhs)
{
    float factor = 1.0f / rhs;
    return Vector2(lhs.x * factor,
                   lhs.y * factor);
}


Vector2 operator *(float lhs, const Vector2 &rhs)
{
    return Vector2(lhs * rhs.x,
                   lhs * rhs.y);
}

Vector2 operator /(float lhs, const Vector2 &rhs)
{
    float factor = 1.0f / lhs;
    return Vector2(rhs.x * factor,
                   rhs.y * factor);
}
NS_LORE_END


//Members
//Add / Subtract - Vectors
Vector2& Vector2::operator +=(const Vector2 &rhs)
{
    this->x += rhs.x;
    this->y += rhs.y;
    return (*this);
}

Vector2& Vector2::operator -=(const Vector2 &rhs)
{
    this->x -= rhs.x;
    this->y -= rhs.y;
    return (*this);
}


//Add / Subtract - Scalars
Vector2& Vector2::operator +=(float rhs)
{
    this->x += rhs;
    this->y += rhs;
    return (*this);
}

Vector2& Vector2::operator -=(float rhs)
{
    this->x -= rhs;
    this->y -= rhs;
    return (*this);
}


//Multiply / Divide - Vectors
Vector2& Vector2::operator *=(const Vector2 &rhs)
{
    this->x *= rhs.x;
    this->y *= rhs.y;
    return (*this);
}

Vector2& Vector2::operator /=(const Vector2 &rhs)
{
    this->x /= rhs.x;
    this->y /= rhs.y;
    return (*this);
}


//Multiply / Divide - Scalars
Vector2& Vector2::operator *=(float rhs)
{
    this->x *= rhs;
    this->y *= rhs;
    return (*this);
}

Vector2& Vector2::operator /=(float rhs)
{
    this->x /= rhs;
    this->y /= rhs;
    return (*this);
}
