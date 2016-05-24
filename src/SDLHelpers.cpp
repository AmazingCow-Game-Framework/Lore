
//Header
#include "../include/SDLHelpers.h"
//Lore
#include "../include/WindowManager.h"

//Usings
USING_NS_LORE

NS_LORE_BEGIN

////////////////////////////////////////////////////////////////////////////////
// Point                                                                      //
////////////////////////////////////////////////////////////////////////////////
SDL_Point SDLHelpers::make_point(int x, int y)
{
    return (SDL_Point){x, y};
}

SDL_Point SDLHelpers::make_point(const Vector2 &vector)
{
    return make_point(vector.x, vector.y);
}

SDL_Point SDLHelpers::make_point(const Rectangle &rect)
{
    return make_point(rect.getLocation());
}


////////////////////////////////////////////////////////////////////////////////
// Rectangle                                                                  //
////////////////////////////////////////////////////////////////////////////////
SDL_Rect SDLHelpers::make_rect(int x, int y, int w, int h)
{
    return (SDL_Rect){x, y, w, h};
}

SDL_Rect SDLHelpers::make_rect(const Vector2 &pos, const Vector2 &size)
{
    return make_rect(pos.x, pos.y, size.x, size.y);
}

SDL_Rect SDLHelpers::make_rect(const Rectangle &rect)
{
    return make_rect(rect.getLocation(), rect.getSize());
}


////////////////////////////////////////////////////////////////////////////////
// Color                                                                      //
////////////////////////////////////////////////////////////////////////////////
SDL_Color SDLHelpers::make_color(int r, int g, int b, int a /* = 255 */)
{
    //COWTODO: Check errors.
    return (SDL_Color){r, g, b, a};
}

SDL_Color SDLHelpers::make_color(const Color &color)
{
    return make_color(color.r, color.g, color.b, color.a);
}


////////////////////////////////////////////////////////////////////////////////
// Texture                                                                    //
////////////////////////////////////////////////////////////////////////////////
SDL_Texture* SDLHelpers::load_texture_from_file(const std::string &filename)
{
    auto surface = IMG_Load(filename.c_str());

    COREGAME_ASSERT_ARGS(surface != nullptr,
                         "Cannot load surface with filename - %s",
                         filename.c_str());

    return make_texture_free(surface);
}

SDL_Texture* SDLHelpers::make_texture_free(SDL_Surface *surface)
{
    COREGAME_ASSERT(surface != nullptr,
                    "Surface cannot be null");

    auto renderer = WindowManager::instance()->getRenderer();

    auto texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    COREGAME_ASSERT(texture != nullptr,
                    "Failed to create texture");

    return texture;
}
SDL_Texture* SDLHelpers::make_texture_empty(int width  /* = 0 */,
                                            int height /* = 0 */)
{
    //COWTODO: Check if this is the correct way to get             \
    //         an empty texture. i.e. We shouldn't check           \
    //         the renderer first to get the pixel format and all?
    auto renderer = WindowManager::instance()->getRenderer();
    auto texture = SDL_CreateTexture(renderer,
                                     SDL_PIXELFORMAT_RGBA8888,
                                     SDL_TEXTUREACCESS_STATIC,
                                     width, height);

    return texture;
}

////////////////////////////////////////////////////////////////////////////////
// Font                                                                       //
////////////////////////////////////////////////////////////////////////////////
TTF_Font* SDLHelpers::load_font_from_file(const std::string &filename, int size)
{
    auto font = TTF_OpenFont(filename.c_str(), size);

    COREGAME_ASSERT_ARGS(font != nullptr,
                         "Cannot load font with filename - %s - size - %d",
                         filename.c_str(), size);

    return font;
}

NS_LORE_END
