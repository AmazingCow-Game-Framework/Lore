#ifndef __Lore_include_Sprite_h__
#define __Lore_include_Sprite_h__

//std
#include <string>
//Lore
#include "IDrawable.h"
#include "ITransformable.h"
#include "Texture.h"

NS_LORE_BEGIN

class Sprite : public IDrawable, public ITransformable
{
    // Enums / Constants //
public:
    enum class Flip {
        None = 0,
        X    = 1,
        Y    = 2,
        Both = 3
    };


    // CTOR //
public:
    Sprite();
    Sprite(const Texture &texture);
    Sprite(const std::string &filename,
           const Rectangle &srcRect = Rectangle::Empty());


    // Public Methods //
public:
    virtual void draw() override;

    //Flip
    void setFlip (Flip flip);
    void setFlipX(bool flip);
    void setFlipY(bool flip);

    Flip getFlip () const;
    bool getFlipX() const;
    bool getFlipY() const;

    //Texture
    const Texture& getTexture() const;
    void setTexture(const Texture &texture);
    void loadTexture(const std::string &filename,
                     const Rectangle &srcRect = Rectangle::Empty());

    //BoundingBox
    const Rectangle& getBoundingBox() const;

    // iVars //
private:
    Texture m_texture;

    SDL_Rect  m_srcRect;
    SDL_Rect  m_dstRect;
    Flip      m_flip;
};

NS_LORE_END
#endif // __Lore_include_Sprite_h__ //
