//Header
#include "../include/ITransformable.h"
//Lore
#include "../include/AssetsManager.h"

//Usings
USING_NS_LORE


////////////////////////////////////////////////////////////////////////////////
// Inner Types                                                                //
////////////////////////////////////////////////////////////////////////////////
const Vector2 ITransformable::OriginHelpers::TopLeft()
{
    static Vector2 s_topLeft(0, 0);
    return s_topLeft;
}

const Vector2 ITransformable::OriginHelpers::MiddleLeft()
{
    static Vector2 s_middleLeft(0, 0.5);
    return s_middleLeft;
}

const Vector2 ITransformable::OriginHelpers::BottomLeft()
{
    static Vector2 s_bottomLeft(0, 1);
    return s_bottomLeft;
}


const Vector2 ITransformable::OriginHelpers::TopCenter()
{
    static Vector2 s_topCenter(0.5, 0);
    return s_topCenter;
}

const Vector2 ITransformable::OriginHelpers::Center()
{
    static Vector2 s_center(0.5, 0.5);
    return s_center;
}

const Vector2 ITransformable::OriginHelpers::BottomCenter()
{
    static Vector2 s_bottomCenter(0.5, 1);
    return s_bottomCenter;
}


const Vector2 ITransformable::OriginHelpers::TopRight()
{
    static Vector2 s_topRight(1, 0);
    return s_topRight;
}

const Vector2 ITransformable::OriginHelpers::MiddleRight()
{
    static Vector2 s_middleRight(1, 0.5);
    return s_middleRight;
}

const Vector2 ITransformable::OriginHelpers::BottomRight()
{
    static Vector2 s_bottomRight(1, 1);
    return s_bottomRight;
}



////////////////////////////////////////////////////////////////////////////////
// CTOR / DTOR                                                                //
////////////////////////////////////////////////////////////////////////////////
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


////////////////////////////////////////////////////////////////////////////////
// Public Methods                                                             //
////////////////////////////////////////////////////////////////////////////////
//Position
void ITransformable::setPosition(const Vector2 &position)
{
    m_position = position;
}
void ITransformable::setPosition(float x, float y)
{
    m_position.x = x;
    m_position.y = y;
}
void ITransformable::setPositionX(float x)
{
    m_position.x = x;
}
void ITransformable::setPositionY(float y)
{
    m_position.y = y;
}

const Vector2& ITransformable::getPosition() const
{
    return m_position;
}
float ITransformable::getPositionX() const
{
    return m_position.x;
}
float ITransformable::getPositionY() const
{
    return m_position.y;
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
    m_scale.x = x;
    m_scale.y = y;
}
void ITransformable::setScaleX(float x)
{
    m_scale.x = x;
}
void ITransformable::setScaleY(float y)
{
    m_scale.y = y;
}

const Vector2& ITransformable::getScale() const
{
    return m_scale;
}
float ITransformable::getScaleX() const
{
    return m_scale.x;
}
float ITransformable::getScaleY() const
{
    return m_scale.y;
}


//Origin
void ITransformable::setOrigin(const Vector2 &origin)
{
    m_origin = origin;
}
void ITransformable::setOrigin(float x, float y)
{
    m_origin.x = x;
    m_origin.y = y;
}
void ITransformable::setOriginX(float x)
{
    m_origin.x = x;
}
void ITransformable::setOriginY(float y)
{
    m_origin.y = y;
}

const Vector2& ITransformable::getOrigin() const
{
    return m_origin;
}
float ITransformable::getOriginX() const
{
    return m_origin.x;
}
float ITransformable::getOriginY() const
{
    return m_origin.y;
}


////////////////////////////////////////////////////////////////////////////////
// Transforms                                                                 //
////////////////////////////////////////////////////////////////////////////////
//Move
void ITransformable::move(const Vector2 &displacement)
{
    m_position += displacement;
}
void ITransformable::moveX(float x)
{
    m_position.x += x;
}
void ITransformable::moveY(float y)
{
    m_position.y += y;
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
