//Header
#include "GameObject.h"

//Usings
USING_NS_LORE;


// CTOR / DTOR //
GameObject::GameObject() :
    // m_sprite()
    m_boundingBox(make_rect(0, 0, 0, 0)),
    m_speed(make_point(0, 0)),
    m_state(GameObject::State::Alive)
{
    //Empty...
}

GameObject::~GameObject()
{
    //Empty...
}

// Position / Bounds / Movement //
//Position
SDL_Point GameObject::getPosition() const
{
    return make_point(m_boundingBox.x, m_boundingBox.y);
}

int GameObject::getPositionX() const
{
    return m_boundingBox.x;
}

int GameObject::getPositionY() const
{
    return m_boundingBox.y;
}

void GameObject::setPosition(const SDL_Point &pos)
{
    m_boundingBox.x = pos.x;
    m_boundingBox.y = pos.y;
}

void GameObject::setPositionX(int x)
{
    m_boundingBox.x = x;
}

void GameObject::setPositionY(int y)
{
    m_boundingBox.y = y;
}


//Bounding Box
const SDL_Rect& GameObject::getBoundingBox() const
{
    return m_boundingBox;
}


//Movement
const SDL_Point& GameObject::getSpeed() const
{
    return m_speed;
}

void GameObject::setSpeed(const SDL_Point &speed)
{
    m_speed.x = speed.x;
    m_speed.y = speed.y;
}

bool GameObject::checkCollision(const GameObject &obj) const
{
    return SDL_HasIntersection(&m_boundingBox, &obj.getBoundingBox());
}


// Other //
GameObject::State GameObject::getState() const
{
    return m_state;
}
void GameObject::setState(State state)
{
    m_state = state;
}

// Protected Methods //
void GameObject::setBoundingBox(const SDL_Rect &rect)
{
    m_boundingBox = rect;
}

Sprite& GameObject::getSprite()
{
    return m_sprite;
}

const Sprite& GameObject::getSprite() const
{
    return m_sprite;
}
