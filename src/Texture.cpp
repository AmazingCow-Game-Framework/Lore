//Header
#include "../include/Texture.h"
//Lore
#include "../include/SDLHelpers.h"
#include "../include/WindowManager.h"
#include "../include/AssetsManager.h"

//Usings
USING_NS_LORE

// CTOR / DTOR //
Texture::Texture(const std::string &filename) :
    m_pTexture(load_texture_from_file(filename))
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
}

// Public Methods //
void Texture::draw(const Rectangle &srcRect,
                   const Rectangle &dstRect,
                   float angle,
                   const Vector2 &origin,
                   Flip  flip)
{
    auto sdl_srcRect = (SDL_Rect){
                            srcRect.getX(),     srcRect.getY(),
                            srcRect.getWidth(), srcRect.getHeight()
                        };

    auto sdl_dstRect = (SDL_Rect){
                            dstRect.getX(),     dstRect.getY(),
                            dstRect.getWidth(), dstRect.getHeight()
                        };

    auto sdl_origin = (SDL_Point){
                            origin.getX(),
                            origin.getY()
                        };

    auto sdl_flip = static_cast<SDL_RendererFlip>(flip);

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
