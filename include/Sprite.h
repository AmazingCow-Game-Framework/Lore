#ifndef __Lore_include_Sprite_h__
#define __Lore_include_Sprite_h__

//std
#include <string>
//Lore
#include "GameCommon.h"

NS_LORE_BEGIN

class Sprite
{
    // Enums / Constants //
public:
    enum class Flip { None = 0, X = 1, Y = 2, Both = 3 };


    // CTOR //
public:
    Sprite();
    Sprite(const std::string &filename);
    Sprite(SDL_Texture *texture);


    // Public Methods //
public:
    void draw();
    void draw(const SDL_Point &position);
    void setSourceRect(const SDL_Rect &rect);

    //Flip
    void setFlip (Flip flip);
    void setFlipX(bool flip);
    void setFlipY(bool flip);

    Flip getFlip () const;
    bool getFlipX() const;
    bool getFlipY() const;

    //Texture
    SDL_Texture* getTexture() const;
    void setTexture(SDL_Texture *texture);
    void loadTexture(const std::string &filename);

    //BoundingBox
    const SDL_Rect& getBoundingBox() const;

    // iVars //
private:
    SDL_Texture *m_pTexture;

    SDL_Rect  m_srcRect;
    SDL_Rect  m_dstRect;
    Flip      m_flip;
};

NS_LORE_END
#endif // __Lore_include_Sprite_h__ //
