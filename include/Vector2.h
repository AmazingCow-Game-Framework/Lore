#ifndef __Lore_include_Vector2_h__
#define __Lore_include_Vector2_h__

////////////////////////////////////////////////////////////////////////////////
// This class had heavily borrowed the implementation                         //
// ideias from the  MonoGame Vector2.cs file.                                 //
////////////////////////////////////////////////////////////////////////////////

//Lore
#include "Lore_Utils.h"

NS_LORE_BEGIN

class Vector2
{
    // Static Methods //
public:
    static const Vector2& Zero ();
    static const Vector2& One  ();
    static const Vector2& UnitX();
    static const Vector2& UnitY();


    // CTOR / DTOR //
public:
    explicit Vector2();
    explicit Vector2(float value);
    explicit Vector2(float x, float y);


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
    //Comparisons
    friend bool operator ==(const Vector2 &lhs, const Vector2 &rhs);
    friend bool operator !=(const Vector2 &lhs, const Vector2 &rhs);

    //Add / Subtract - Vectors
    friend Vector2 operator +(const Vector2 &lhs, const Vector2 &rhs);
    friend Vector2 operator -(const Vector2 &lhs, const Vector2 &rhs);

    //Add / Subtract - Scalars
    friend Vector2 operator +(const Vector2 &lhs, float rhs);
    friend Vector2 operator -(const Vector2 &lhs, float rhs);

    friend Vector2 operator +(float lhs, const Vector2 &rhs);
    friend Vector2 operator -(float lhs, const Vector2 &rhs);

    //Multiply / Divide - Vectors
    friend Vector2 operator *(const Vector2 &lhs, const Vector2 &rhs);
    friend Vector2 operator /(const Vector2 &lhs, const Vector2 &rhs);

    //Multiply / Divide - Scalars
    friend Vector2 operator *(const Vector2 &lhs, float rhs);
    friend Vector2 operator /(const Vector2 &lhs, float rhs);

    friend Vector2 operator *(float lhs, const Vector2 &rhs);
    friend Vector2 operator /(float lhs, const Vector2 &rhs);


    //Members
    //Add / Subtract - Vectors
    Vector2& operator +=(const Vector2 &rhs);
    Vector2& operator -=(const Vector2 &rhs);

    //Add / Subtract - Scalars
    Vector2& operator +=(float rhs);
    Vector2& operator -=(float rhs);

    //Multiply / Divide - Vectors
    Vector2& operator *=(const Vector2 &rhs);
    Vector2& operator /=(const Vector2 &rhs);

    //Multiply / Divide - Scalars
    Vector2& operator *=(float rhs);
    Vector2& operator /=(float rhs);


    // iVars //
public:
    float x, y;
};

NS_LORE_END
#endif // __Lore_include_Vector2_h__ //
