#ifndef __Lore_include_GameObject_h__
#define __Lore_include_GameObject_h__

//Lore
#include "GameCommon.h"
#include "Sprite.h"


NS_LORE_BEGIN

class GameObject
{
    // Enums //
public:
    enum class State { Alive, Dying, Dead };

    // CTOR / DTOR //
public:
    GameObject();
    virtual ~GameObject();

    // Update / Draw //
public:
    virtual void update(float dt) = 0;
    virtual void draw  ()         = 0;

    // Position / Bounds / Movement //
public:
    //Position
    SDL_Point getPosition () const;
    int       getPositionX() const;
    int       getPositionY() const;

    void setPosition (const SDL_Point &pos);
    void setPositionX(int x);
    void setPositionY(int y);

    //Bounding Box
    const SDL_Rect& getBoundingBox() const;

    //Movement
    const SDL_Point& getSpeed() const;
    void setSpeed(const SDL_Point &speed);

    // Actions //
public:
    virtual bool checkCollision(const GameObject &obj) const;

    // Other //
public:
    State getState() const;
    void setState(State state);

    // Protected Methods //
protected:
    //Bounding Box
    void setBoundingBox(const SDL_Rect &rect);
    //Sprite
    Sprite& getSprite();
    const Sprite& getSprite() const;

    // iVars //
private:
    Sprite m_sprite;

    SDL_Rect  m_boundingBox;
    SDL_Point m_speed;

    State m_state;
};

NS_LORE_END
#endif // __Lore_include_GameObject_h__ //
