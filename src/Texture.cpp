//Header
#include "../include/Texture.h"
//Lore
#include "../include/SDLHelpers.h"
#include "../include/WindowManager.h"
#include "../include/AssetsManager.h"

//Usings
USING_NS_LORE

// Operators for Texture::Flip //
NS_LORE_BEGIN
Texture::Flip operator | (Texture::Flip lhs, Texture::Flip rhs)
{
    return static_cast<Texture::Flip>(
            static_cast<int>(lhs) | static_cast<int>(rhs)
        );
}

Texture::Flip operator & (Texture::Flip lhs, Texture::Flip rhs)
{
    return static_cast<Texture::Flip>(
            static_cast<int>(lhs) & static_cast<int>(rhs)
        );
}

Texture::Flip operator ^ (Texture::Flip lhs, Texture::Flip rhs)
{
    return static_cast<Texture::Flip>(
            static_cast<int>(lhs) ^ static_cast<int>(rhs)
        );
}


Texture::Flip& operator |=(Texture::Flip &lhs, Texture::Flip rhs)
{
    lhs = static_cast<Texture::Flip>(
            static_cast<int>(lhs) | static_cast<int>(rhs)
        );

    return lhs;
}

Texture::Flip& operator &=(Texture::Flip &lhs, Texture::Flip rhs)
{
    lhs = static_cast<Texture::Flip>(
            static_cast<int>(lhs) & static_cast<int>(rhs)
        );

    return lhs;
}

Texture::Flip& operator ^=(Texture::Flip &lhs, Texture::Flip rhs)
{
    lhs = static_cast<Texture::Flip>(
            static_cast<int>(lhs) ^ static_cast<int>(rhs)
        );

    return lhs;
}
NS_LORE_END


// CTOR / DTOR //
Texture::Texture(SDL_Texture *texture) :
    m_pTexture(texture),
    m_size    (Vector2::Zero())
{
    //Initialized with nullptr texture
    //There is no need to get the size...
    if(!m_pTexture)
        return;

    int w, h;
    SDL_QueryTexture(m_pTexture, nullptr, nullptr, &w, &h);

    m_size.x = w;
    m_size.y = h;
}

Texture::~Texture()
{
    COREGAME_DLOG(CoreGame::Log::Type::Debug4, "Lore::Texture DTOR");

    //COWTODO: Check errors.
    SDL_DestroyTexture(m_pTexture);
    m_pTexture = nullptr;
}

// Public Methods //
void Texture::draw(const Rectangle &srcRect,
                   const Rectangle &dstRect,
                   float angle,
                   const Vector2 &origin,
                   Flip  flip,
                   const Color &color)
{
    //Turn the Lore types to SDL types...
    auto sdl_srcRect = SDLHelpers::make_rect(srcRect);
    auto sdl_dstRect = SDLHelpers::make_rect(dstRect);

    //Origin is in range of [0, 1].
    auto sdl_origin = SDLHelpers::make_point(origin.getX() * srcRect.getWidth(),
                                             origin.getY() * srcRect.getHeight());

    auto sdl_flip = static_cast<SDL_RendererFlip>(flip);

    //Offset the position.
    sdl_dstRect.x -= sdl_origin.x;
    sdl_dstRect.y -= sdl_origin.y;

    //Set the tint color.
    SDL_SetTextureColorMod(m_pTexture, color.r, color.g, color.b);

    auto renderer = WindowManager::instance()->getRenderer();
    SDL_RenderCopyEx(renderer,
                     m_pTexture,
                     &sdl_srcRect,
                     &sdl_dstRect,
                     angle,
                     &sdl_origin,
                     sdl_flip);
}

const Vector2& Texture::getTextureSize() const
{
    return m_size;
}
