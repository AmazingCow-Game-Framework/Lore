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
    m_color      (Color::White())
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
    if(!getIsVisible())
        return;

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
    if(flip) m_flip |= Texture::Flip::X;
    else     m_flip &= Texture::Flip::Y;
}

void Sprite::setFlipY(bool flip)
{
    if(flip) m_flip |= Texture::Flip::Y;
    else     m_flip &= Texture::Flip::X;
}

Texture::Flip Sprite::getFlip() const
{
    return m_flip;
}

bool Sprite::getFlipX() const
{
    return (m_flip & Texture::Flip::X) == Texture::Flip::X;
}

bool Sprite::getFlipY() const
{
    return (m_flip & Texture::Flip::Y) == Texture::Flip::Y;
}


//Color
void Sprite::setColor(const Color &color)
{
    m_color = color;
}

const Color& Sprite::getColor() const
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
    return Rectangle(getPosition(), m_textureRect.getSize());
}
