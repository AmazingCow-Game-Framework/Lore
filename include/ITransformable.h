#ifndef __Lore_include_ITransformable_h__
#define __Lore_include_ITransformable_h__

//Lore
#include "Lore_Utils.h"
#include "Vector2.h"
#include "Rectangle.h"

NS_LORE_BEGIN

class ITransformable
{
    // CTOR / DTOR //
public:
    ITransformable();
    virtual ~ITransformable();

    // Public Methods //
public:
    //Position
    void setPosition (const Vector2 &position);
    void setPosition (float x, float y);
    void setPositionX(float x);
    void setPositionY(float y);

    const Vector2& getPosition () const;
    float          getPositionX() const;
    float          getPositionY() const;


    //Rotation
    void setRotation(float angle);
    float getRotation() const;


    //Scale
    void setScale (const Vector2 &scale);
    void setScale (float x, float y);
    void setScaleX(float x);
    void setScaleY(float y);

    const Vector2& getScale () const;
    float          getScaleX() const;
    float          getScaleY() const;


    //Origin
    void setOrigin (const Vector2 &origin);
    void setOrigin (float x, float y);
    void setOriginX(float x);
    void setOriginY(float y);

    const Vector2& getOrigin()  const;
    float          getOriginX() const;
    float          getOriginY() const;


public:
    //Move
    void move(const Vector2 &displacement);
    void moveX(float x);
    void moveY(float y);

    //Rotate
    void rotate(float angle);

    //Scale
    void scale(const Vector2 factor);
    void scale(float scale);
    void scaleX(float x);
    void scaleY(float y);

    // iVars //
private:
    Vector2 m_position;
    float   m_rotation;
    Vector2 m_scale;
    Vector2 m_origin;
};

NS_LORE_END
#endif // __Lore_include_ITransformable_h__ //
