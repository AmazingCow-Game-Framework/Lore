//Header
#include "Text.h"
//std
#include <cstdarg>
//Lore
#include "AssetsManager.h"
#include "WindowManager.h"

//Usings
USING_NS_LORE


// CTOR //
Text::Text() :
    m_fgColor(make_color(255, 255, 255)), //White
    m_bgColor(make_color(0, 0, 0, 0)),    //Transparent
    m_srcRect(make_rect(0, 0, 0, 0)),
    m_dstRect(make_rect(0, 0, 0, 0)),
    m_pFont   (nullptr),
    m_pTexture(nullptr)
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
    auto renderer = WindowManager::instance()->getRenderer();
    SDL_RenderCopy(renderer, m_pTexture, &m_srcRect, &m_dstRect);
}

//String
void Text::setString(char *fmt, ...)
{
    constexpr int kBufSize = 1024;
    char buffer[kBufSize];

    //Reset the buffer
    memset(buffer, 0, kBufSize);

    //Build the buffer with the variadic args list
    va_list ap;
    va_start(ap, fmt);
    vsnprintf(buffer, kBufSize, fmt, ap);
    va_end(ap);

    m_string = buffer;
    calculate();
}

const std::string& Text::getString() const
{
    return m_string;
}


//Color
void Text::setForegroundColor(const SDL_Color &color)
{
    m_fgColor = color;
    calculate();
}

const SDL_Color& Text::getForegroundColor() const
{
    return m_fgColor;
}

void Text::setBackgroundColor(const SDL_Color &color)
{
    m_bgColor = color;
    calculate();
}

const SDL_Color& Text::getBackgroundColor() const
{
    return m_bgColor;
}


//Posiiton
void Text::setPosition(const SDL_Point &position)
{
    m_dstRect.x = position.x;
    m_dstRect.y = position.y;
}

SDL_Point Text::getPosition() const
{
    return make_point(m_dstRect.x, m_dstRect.y);
}

//Font
void Text::setFont(TTF_Font *font)
{
    m_pFont = font;
    calculate();
}

void Text::loadFont(const std::string &filename, int size)
{
    setFont(AssetsManager::instance()->getFont(filename, size));
}


//Bounding Box
const SDL_Rect& Text::getBoundingBox() const
{
    return m_dstRect;
}

// Private Methods //
void Text::calculate()
{
    //Destroy first to don't leak.
    if(m_pTexture)
        SDL_DestroyTexture(m_pTexture);

    //Create a texture.
    m_pTexture = make_texture_free(TTF_RenderText_Solid(m_pFont,
                                                        m_string.c_str(),
                                                        m_fgColor));
    //Find the bounds.
    TTF_SizeText(m_pFont,
                 m_string.c_str(),
                 &m_srcRect.w,
                 &m_srcRect.h);

    m_dstRect.w = m_srcRect.w;
    m_dstRect.h = m_srcRect.h;
}
