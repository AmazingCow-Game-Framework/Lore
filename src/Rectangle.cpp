//Header
#include "../include/Rectangle.h"

//Usings
USING_NS_LORE

// Static Methods //
const Rectangle& Rectangle::Empty()
{
    static Rectangle s_emptyRect;
    return s_emptyRect;
}

const Rectangle& Rectangle::Unit()
{
    static Rectangle s_unitRect(1, 1, 1, 1);
    return s_unitRect;
}


// CTOR / DTOR //
Rectangle::Rectangle() :
    Rectangle(0, 0, 0, 0)
{
    //Empty...
}

Rectangle::Rectangle(float x, float y, float w, float h) :
    Rectangle(Vector2(x, y), Vector2(w, h))
{
    //Empty...
}

Rectangle::Rectangle(const Vector2 &pos, const Vector2 &size) :
    m_position(pos),
    m_size    (size)
{
    //Empty...
}


// Public Methods //
//
void  Rectangle::setX(float x)
{
    m_position.setX(x);
}
float Rectangle::getX() const
{
    return m_position.getX();
}

void  Rectangle::setY(float y)
{
    m_position.setY(y);
}
float Rectangle::getY() const
{
    return m_position.getY();
}

void  Rectangle::setWidth(float w)
{
    m_size.setX(w);
}
float Rectangle::getWidth() const
{
    return m_size.getX();
}

void  Rectangle::setHeight(float h)
{
    m_size.setY(h);
}
float Rectangle::getHeight() const
{
    return m_size.getY();
}

//
float Rectangle::getLeft() const
{
    return m_position.getX();
}
float Rectangle::getRight() const
{
    return m_position.getX() + m_size.getX();
}
float Rectangle::getTop() const
{
    return m_position.getY();
}
float Rectangle::getBottom() const
{
    return m_position.getY() + m_size.getY();
}


//
void Rectangle::setLocation(const Vector2 &pos)
{
    m_position = pos;
}
const Vector2& Rectangle::getLocation() const
{
    return m_position;
}

void Rectangle::setSize(const Vector2 &size)
{
    m_size = size;
}
const Vector2& Rectangle::getSize() const
{
    return m_size;
}

Vector2 Rectangle::getCenter() const
{
    return Vector2(getRight() / 2, getBottom() / 2);
}

//
bool Rectangle::isEmpty()
{
    (*this) == Rectangle::Empty();
}
bool Rectangle::isUnit()
{
    (*this) == Rectangle::Unit();
}


// Operators //
NS_LORE_BEGIN
bool operator ==(const Rectangle &lhs, const Rectangle &rhs)
{
    return lhs.getLocation() == rhs.getLocation() &&
           lhs.getSize()     == rhs.getSize();
}
bool operator !=(const Rectangle &lhs, const Rectangle &rhs)
{
    return !(lhs == rhs);
}
NS_LORE_END
