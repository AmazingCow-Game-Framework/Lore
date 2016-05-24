//Header
#include "../include/Text.h"
//std
#include <cstdarg>
//Lore
#include "../include/AssetsManager.h"

//Usings
USING_NS_LORE

// CTOR //
Text::Text() :
    // m_string - Default initialized.
    m_pFont          (nullptr),
    m_pCurrentTexture(nullptr),
    m_fgColor        (Color::White()),
    m_bgColor        (Color::Transparent())
{
    //Empty...
}

Text::Text(const std::string &filename, int size) :
    Text()
{
    loadFont(filename, size);
}


// Public Methods //
//Draw
void Text::draw()
{
    if(!getIsVisible())
        return;

    m_pCurrentTexture->draw(m_textureRect,
                            getBounds  (),
                            getRotation(),
                            getOrigin  (),
                            m_flip,
                            Color::White());
}

//String
void Text::setString(char *fmt, ...)
{
    m_string = fmt;
    calculate();
}

const std::string& Text::getString() const
{
    return m_string;
}


//Color
void Text::setForegroundColor(const Color &color)
{
    m_fgColor = color;
    calculate();
}

const Color& Text::getForegroundColor() const
{
    return m_fgColor;
}


void Text::setBackgroundColor(const Color &color)
{
    m_bgColor = color;
    calculate();
}

const Color& Text::getBackgroundColor() const
{
    return m_bgColor;
}


//Font
void Text::setFont(Font::SPtr font)
{
    m_pFont = font;
    calculate();
}

void Text::loadFont(const std::string &filename, int size)
{
    setFont(AssetsManager::instance()->getFont(filename, size));
}

//Bounds
Rectangle Text::getBounds() const
{
    return Rectangle(getPosition(), m_textureRect.getSize());
}

// Private Methods //
void Text::calculate()
{
    m_pCurrentTexture = m_pFont->prepareTexture(m_string,
                                                m_fgColor,
                                                m_bgColor);

    m_textureRect.setSize(m_pCurrentTexture->getTextureSize());
}
