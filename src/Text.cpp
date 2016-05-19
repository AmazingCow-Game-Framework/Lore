//Header
#include "../include/Text.h"
//std
#include <cstdarg>
//Lore
#include "../include/AssetsManager.h"
#include "../include/WindowManager.h"

//Usings
USING_NS_LORE

// Public Methods //
//Draw
void Text::draw()
{

}

//String
void Text::setString(char *fmt, ...)
{
    m_string = fmt;
}

const std::string& Text::getString() const
{
    return m_string;
}


//Color
void Text::setForegroundColor(const SDL_Color &color)
{
    m_fgColor = color;
}

const SDL_Color& Text::getForegroundColor() const
{
    return m_fgColor;
}


void Text::setBackgroundColor(const SDL_Color &color)
{
    m_bgColor;
}

const SDL_Color& Text::getBackgroundColor() const
{
    return m_bgColor;
}


//Font
void Text::setFont(Font::SPtr font)
{

}

void Text::loadFont(const std::string &filename, int size)
{

}

//Bounds
Rectangle Text::getBounds() const
{

}

// Private Methods //
void Text::calculate()
{

}
