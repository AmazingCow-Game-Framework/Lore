//Header
#include "../include/Sprite.h"
//Lore
#include "../include/AssetsManager.h"

//Usings
USING_NS_LORE

// CTOR //
Sprite::Sprite() :
    m_pTexture   (nullptr),
    m_textureRect(Rectangle::Empty()),
    m_flip       (Texture::Flip::None),
    m_color      ({255, 255, 255})
{
    //Empty...
}

Sprite::Sprite(const std::string &filename,
               const Rectangle &srcRect /* = Rectangle::Empty() */)
{
    loadTexture(filename, srcRect);
}


// Public Methods //
void Sprite::draw()
{
    m_pTexture->draw(m_textureRect,
                     getBounds(),
                     getRotation(),
                     getOrigin(),
                     m_flip,
                     m_color);
}

//Flip
void Sprite::setFlip(Texture::Flip flip)
{
    m_flip = flip;
}

void Sprite::setFlipX(bool flip)
{
    //COWTODO: Implement.
}

void Sprite::setFlipY(bool flip)
{
    //COWTODO: Implement.
}

Texture::Flip Sprite::getFlip() const
{
    return m_flip;
}

bool Sprite::getFlipX() const
{
    //COWTODO: Implement.
}

bool Sprite::getFlipY() const
{
    //COWTODO: Implement.
}


//Color
void Sprite::setColor(const SDL_Color &color)
{
    m_color = color;
}

const SDL_Color& Sprite::getColor() const
{
    return m_color;
}

//Texture
Texture::SPtr Sprite::getTexture() const
{
    return m_pTexture;
}

void Sprite::setTexture(Texture::SPtr texture,
                        const Rectangle &srcRect /* = Rectangle::Empty() */)
{
    m_pTexture = texture;
    setSourceRectangle(srcRect);
}

void Sprite::loadTexture(const std::string &filename,
                         const Rectangle &srcRect /* = Rectangle::Empty() */)
{
    setTexture(AssetsManager::instance()->getTexture(filename),
               srcRect);
}

void Sprite::setSourceRectangle(const Rectangle &srcRect /* = Rectangle::Empty() */)
{
    m_textureRect = srcRect;

    //Set to whole texture.
    if(m_textureRect.isEmpty())
        m_textureRect.setSize(m_pTexture->getTextureSize());
}

const Rectangle& Sprite::getSourceRectangle() const
{
    return m_textureRect;
}

//Bounds
Rectangle Sprite::getBounds() const
{
    return Rectangle(getPosition() + m_textureRect.getSize());
}
