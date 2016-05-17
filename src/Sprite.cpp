//Header
#include "Sprite.h"
//Lore
#include "AssetsManager.h"
#include "WindowManager.h"

//Usings
USING_NS_LORE


// CTOR //
Sprite::Sprite() :
    m_pTexture(nullptr),
    m_srcRect ({0, 0, 0, 0}),
    m_dstRect ({0, 0, 0, 0}),
    m_flip    (Flip::None)
{
    //Empty...
}

Sprite::Sprite(const std::string &filename) :
    Sprite()
{
    loadTexture(filename);
}

Sprite::Sprite(SDL_Texture *texture) :
    Sprite()
{
    setTexture(texture);
}

// Public Methods //
void Sprite::draw()
{
    auto renderer = WindowManager::instance()->getRenderer();
    SDL_RenderCopyEx(renderer,
                     m_pTexture,
                     &m_srcRect,
                     &m_dstRect,
                     0,
                     nullptr,
                     SDL_FLIP_NONE);
}
void Sprite::draw(const SDL_Point &position)
{
    m_dstRect.x = position.x;
    m_dstRect.y = position.y;

    draw();
}

void Sprite::setSourceRect(const SDL_Rect &rect)
{
    m_srcRect = rect;
    m_dstRect = rect;
}


//Flip
void Sprite::setFlip(Flip flip)
{

}
void Sprite::setFlipX(bool flip)
{

}
void Sprite::setFlipY(bool flip)
{

}

Sprite::Flip Sprite::getFlip() const
{

}
bool Sprite::getFlipX() const
{

}
bool Sprite::getFlipY() const
{

}

//Texture
SDL_Texture* Sprite::getTexture() const
{
    return m_pTexture;
}

void Sprite::setTexture(SDL_Texture *texture)
{
    m_pTexture = texture;

    //Init the rects.
    SDL_QueryTexture(texture, nullptr, nullptr, &m_srcRect.w, &m_srcRect.h);
    m_dstRect = m_srcRect;
}

void Sprite::loadTexture(const std::string &filename)
{
    setTexture(AssetsManager::instance()->getTexture(filename));
}


//BoundingBox
const SDL_Rect& Sprite::getBoundingBox() const
{
    return m_dstRect;
}
