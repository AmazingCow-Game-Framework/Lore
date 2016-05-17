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
    m_flip       (Texture::Flip::None)
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
                     Rectangle(getPosition(), m_textureRect.getSize()),
                     getRotation(),
                     getOrigin(),
                     m_flip);
}

//Flip
void Sprite::setFlip(Texture::Flip flip)
{

}
void Sprite::setFlipX(bool flip)
{

}
void Sprite::setFlipY(bool flip)
{

}

Texture::Flip Sprite::getFlip() const
{

}
bool Sprite::getFlipX() const
{

}
bool Sprite::getFlipY() const
{

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
}
