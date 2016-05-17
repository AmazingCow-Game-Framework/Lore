#ifndef __Lore_include_Texture_h__
#define __Lore_include_Texture_h__

//std
#include <string>
//Lore
#include "Lore_Utils.h"
#include "Rectangle.h"
#include "Vector2.h"

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
    Texture(const std::string &filename);
    ~Texture();

    COREGAME_DISALLOW_COPY_MOVE_ASSIGNS(Texture);

    // Public Methods //
public:
    void draw(const Rectangle &srcRect,
              const Rectangle &dstRect,
              float angle,
              const Vector2 &origin,
              Flip  flip);

    const Vector2& getTextureSize() const;

    // iVars //
private:
    SDL_Texture *m_pTexture;
    Vector2      m_size;
};

NS_LORE_END
#endif // __Lore_include_Texture_h__ //
