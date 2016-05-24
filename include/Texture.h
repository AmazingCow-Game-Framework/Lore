#ifndef __Lore_include_Texture_h__
#define __Lore_include_Texture_h__

//std
#include <string>
//Lore
#include "Lore_Utils.h"
#include "Rectangle.h"
#include "Vector2.h"
#include "Color.h"


NS_LORE_BEGIN

class Texture
{
    // Enums / Constants // Typedefs //
public:
    typedef std::shared_ptr<Texture> SPtr;

    enum class Flip {
        None = 0,
        X    = 1,
        Y    = 2,
        Both = 3
    };

    // CTOR / DTOR //
public:
    Texture(SDL_Texture *texture);
    ~Texture();

    COREGAME_DISALLOW_COPY_MOVE_ASSIGNS(Texture);

    // Public Methods //
public:
    void draw(const Rectangle &srcRect,
              const Rectangle &dstRect,
              float angle,
              const Vector2 &origin,
              Flip  flip,
              const Color &color);

    const Vector2& getTextureSize() const;

    // iVars //
private:
    SDL_Texture *m_pTexture;
    Vector2      m_size;
};


// Operators for Texture::Flip //
Texture::Flip operator | (Texture::Flip lhs, Texture::Flip rhs);
Texture::Flip operator & (Texture::Flip lhs, Texture::Flip rhs);
Texture::Flip operator ^ (Texture::Flip lhs, Texture::Flip rhs);

Texture::Flip& operator |=(Texture::Flip &lhs, Texture::Flip rhs);
Texture::Flip& operator &=(Texture::Flip &lhs, Texture::Flip rhs);
Texture::Flip& operator ^=(Texture::Flip &lhs, Texture::Flip rhs);

NS_LORE_END
#endif // __Lore_include_Texture_h__ //
