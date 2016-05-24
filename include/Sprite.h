#ifndef __Lore_include_Sprite_h__
#define __Lore_include_Sprite_h__

//std
#include <string>
//Lore
#include "IDrawable.h"
#include "ITransformable.h"
#include "Texture.h"
#include "Color.h"


NS_LORE_BEGIN

class Sprite : public IDrawable, public ITransformable
{
    // Typedef //
public:
    typedef std::shared_ptr<Sprite> SPtr;

    // CTOR //
public:
    Sprite();
    Sprite(const std::string &filename,
           const Rectangle &srcRect = Rectangle::Empty());


    // Public Methods //
public:
    virtual void draw() override;

    //Flip
    void setFlip (Texture::Flip flip);
    void setFlipX(bool flip);
    void setFlipY(bool flip);

    Texture::Flip getFlip () const;
    bool          getFlipX() const;
    bool          getFlipY() const;

    //Color
    void setColor(const Color &color);
    const Color& getColor() const;

    //Texture
    Texture::SPtr getTexture() const;
    void setTexture(Texture::SPtr texture,
                    const Rectangle &srcRect = Rectangle::Empty());

    void loadTexture(const std::string &filename,
                     const Rectangle &srcRect = Rectangle::Empty());

    void setSourceRectangle(const Rectangle &srcRect = Rectangle::Empty());
    const Rectangle& getSourceRectangle() const;

    //Bounds
    Rectangle getBounds() const;

    // iVars //
private:
    //Texture Stuff.
    Texture::SPtr m_pTexture;
    Rectangle     m_textureRect;
    Texture::Flip m_flip;

    Color m_color;
};

NS_LORE_END
#endif // __Lore_include_Sprite_h__ //
