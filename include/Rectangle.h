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

    //
    float getLeft  () const;
    float getRight () const;
    float getTop   () const;
    float getBottom() const;


    //
    void setLocation(const Vector2 &pos);
    const Vector2& getLocation() const;

    void setSize(const Vector2 &size);
    const Vector2& getSize() const;

    const Vector2& getCenter() const;

    //
    bool isEmpty();
    bool isUnit();


    //COWTODO: Add the operators.

    // iVars //
private:
    Vector2 m_position;
    Vector2 m_size;
};

NS_LORE_END
#endif // __Lore_include_Rectangle_h__ //
