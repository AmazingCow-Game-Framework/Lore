//Header
#include "../include/Texture.h"
//Lore
#include "../include/SDLHelpers.h"
#include "../include/WindowManager.h"
#include "../include/AssetsManager.h"

//Usings
USING_NS_LORE

// CTOR / DTOR //
Texture::Texture(SDL_Texture *texture) :
    m_pTexture(texture)
{
    int w, h;
    SDL_QueryTexture(m_pTexture, nullptr, nullptr, &w, &h);

    m_size.setX(w);
    m_size.setY(h);
}

Texture::~Texture()
{
    cerr << "Texture dtor" << endl;

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
                   const SDL_Color &color)
{
    //Turn the Lore types to SDL types...
    auto sdl_srcRect = (SDL_Rect) {
                            srcRect.getX(),     srcRect.getY(),
                            srcRect.getWidth(), srcRect.getHeight()
                        };

    auto sdl_dstRect = (SDL_Rect) {
                            dstRect.getX(),     dstRect.getY(),
                            dstRect.getWidth(), dstRect.getHeight()
                        };

    //Origin is in range of [0, 1].
    auto sdl_origin = (SDL_Point) {
                            origin.getX() * srcRect.getWidth(),
                            origin.getY() * srcRect.getHeight()
                        };

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
