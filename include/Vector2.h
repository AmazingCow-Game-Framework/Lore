#ifndef __Lore_include_Vector2_h__
#define __Lore_include_Vector2_h__

//Lore
#include "Lore_Utils.h"

NS_LORE_BEGIN

class Vector2
{
    // Static Methods //
public:
    static const Vector2& Zero();
    static const Vector2& One ();

    // CTOR / DTOR //
public:
    Vector2();
    Vector2(float value);
    Vector2(float x, float y);

    // Public Methods //
public:
    void  setX(float x);
    float getX() const;

    void  setY(float y);
    float getY() const;

    // Operators //
public:
    //COWTODO: Add the operators.
    //Friends
    friend bool operator ==(const Vector2 &lhs, const Vector2 &rhs);
    friend bool operator !=(const Vector2 &lhs, const Vector2 &rhs);

    friend Vector2 operator +(const Vector2 &lhs, const Vector2 &rhs);
    friend Vector2 operator -(const Vector2 &lhs, const Vector2 &rhs);

    //Members
    Vector2& operator +=(const Vector2 &rhs);
    Vector2& operator -=(const Vector2 &rhs);

    // iVars //
private:
    float m_x, m_y;
};

NS_LORE_END
#endif // __Lore_include_Vector2_h__ //
