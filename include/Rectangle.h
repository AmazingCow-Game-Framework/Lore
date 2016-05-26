#ifndef __Lore_include_Rectangle_h__
#define __Lore_include_Rectangle_h__

//Lore
#include "Vector2.h"

NS_LORE_BEGIN

class Rectangle
{
    // Static Methods //
public:
    static const Rectangle& Empty();
    static const Rectangle& Unit ();

    // CTOR / DTOR //
public:
    Rectangle();
    Rectangle(float x, float y, float w, float h);
    Rectangle(const Vector2 &pos, const Vector2 &size);

    // Public Methods //
public:
    //
    void  setX(float x);
    float getX() const;

    void  setY(float y);
    float getY() const;

    void  setWidth(float w);
    float getWidth() const;

    void  setHeight(float h);
    float getHeight() const;

    //////////////////////////////////////////
    //                Top                   //
    //         TL            TR             //
    //            +---------+               //
    //            |         |               //
    //    Left ML |    C    | MR  Right     //
    //            |         |               //
    //            +---------+               //
    //         BL            BR             //
    //              Bottom                  //
    //////////////////////////////////////////
    //Left
    float   getLeft      () const;
    Vector2 getTopLeft   () const;
    Vector2 getMiddleLeft() const;
    Vector2 getBottomLeft() const;
    //Right
    float   getRight      () const;
    Vector2 getTopRight   () const;
    Vector2 getMiddleRight() const;
    Vector2 getBottomRight() const;
    //Top
    float getTop() const;
    //Bottom
    float getBottom() const;
    //Center
    Vector2 getCenter() const;


    //
    void setLocation(const Vector2 &pos);
    const Vector2& getLocation() const;

    void setSize(const Vector2 &size);
    const Vector2& getSize() const;

    //
    bool isEmpty();
    bool isUnit();


    // Operators //
public:
    //COWTODO: Add the operators.
    friend bool operator ==(const Rectangle &lhs, const Rectangle &rhs);
    friend bool operator !=(const Rectangle &lhs, const Rectangle &rhs);


    // iVars //
private:
    Vector2 m_position;
    Vector2 m_size;
};

NS_LORE_END
#endif // __Lore_include_Rectangle_h__ //
