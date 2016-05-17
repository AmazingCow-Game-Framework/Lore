//Header
#include "../include/ITransformable.h"
//Lore
#include "../include/AssetsManager.h"

//Usings
USING_NS_LORE

// CTOR / DTOR //
ITransformable::ITransformable() :
    m_position(Vector2::Zero()),
    m_rotation(0),
    m_scale   (Vector2::One()),
    m_origin  (Vector2::Zero())
{
    //Empty...
}
ITransformable::~ITransformable()
{
    //Empty...
}


// Public Methods //
//Position
void ITransformable::setPosition(const Vector2 &position)
{
    m_position = position;
}
void ITransformable::setPosition(float x, float y)
{
    m_position.setX(x);
    m_position.setY(y);
}
void ITransformable::setPositionX(float x)
{
    m_position.setX(x);
}
void ITransformable::setPositionY(float y)
{
    m_position.setY(y);
}

const Vector2& ITransformable::getPosition() const
{
    return m_position;
}
float ITransformable::getPositionX() const
{
    return m_position.getX();
}
float ITransformable::getPositionY() const
{
    return m_position.getY();
}


//Rotation
void ITransformable::setRotation(float angle)
{
    m_rotation = angle;
}
float ITransformable::getRotation() const
{
    return m_rotation;
}


//Scale
void ITransformable::setScale(const Vector2 &scale)
{
    m_scale = scale;
}
void ITransformable::setScale(float x, float y)
{
    m_scale.setX(x);
    m_scale.setY(y);
}
void ITransformable::setScaleX(float x)
{
    m_scale.setX(x);
}
void ITransformable::setScaleY(float y)
{
    m_scale.setY(y);
}

const Vector2& ITransformable::getScale() const
{
    return m_scale;
}
float ITransformable::getScaleX() const
{
    return m_scale.getX();
}
float ITransformable::getScaleY() const
{
    return m_scale.getY();
}


//Origin
void ITransformable::setOrigin(const Vector2 &point)
{
    m_origin = point;
}
void ITransformable::setOrigin(float x, float y)
{
    m_origin.setX(x);
    m_origin.setY(y);
}
void ITransformable::setOriginX(float x)
{
    m_origin.setX(x);
}
void ITransformable::setOriginY(float y)
{
    m_origin.setY(y);
}

const Vector2& ITransformable::getOrigin() const
{
    return m_origin;
}
float ITransformable::getOriginX() const
{
    return m_origin.getX();
}
float ITransformable::getOriginY() const
{
    return m_origin.getY();
}


////////////////////////////////////////////////////////////////////////////////

//Move
void ITransformable::move(const Vector2 &displacement)
{
    //COWTODO: Implement.
}
void ITransformable::moveX(float x)
{
    //COWTODO: Implement.
}
void ITransformable::moveY(float y)
{
    //COWTODO: Implement.
}

//Rotate
void ITransformable::rotate(float angle)
{
    m_rotation += angle;
    if(m_rotation >= 360.0f)
        m_rotation -= 360.0f;
}

//Scale
void ITransformable::scale(const Vector2 factor)
{
    //COWTODO: Implement.
}
void ITransformable::scale(float scale)
{
    //COWTODO: Implement.
}
void ITransformable::scaleX(float x)
{
    //COWTODO: Implement.
}
void ITransformable::scaleY(float y)
{
    //COWTODO: Implement.
}
