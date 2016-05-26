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


//Left
float Rectangle::getLeft() const
{
    return m_position.x;
}

Vector2 Rectangle::getTopLeft() const
{
    return m_position;
}

Vector2 Rectangle::getMiddleLeft() const
{
    return Vector2(m_position.x, getBottom() / 2);
}

Vector2 Rectangle::getBottomLeft() const
{
    return Vector2(m_position.x, getBottom());
}

//Right
float Rectangle::getRight() const
{
    return m_position.x + m_size.x;
}

Vector2 Rectangle::getTopRight() const
{
    return Vector2(getRight(), m_position.y);
}

Vector2 Rectangle::getMiddleRight() const
{
    return Vector2(getRight(), getBottom() / 2);
}

Vector2 Rectangle::getBottomRight() const
{
    return Vector2(getRight(), getBottom());
}

//Top
float Rectangle::getTop() const
{
    return m_position.y;
}

//Bottom
float Rectangle::getBottom() const
{
    return m_position.y + m_size.y;
}

//Center
Vector2 Rectangle::getCenter() const
{
    return Vector2(getRight() / 2, getBottom() / 2);
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
