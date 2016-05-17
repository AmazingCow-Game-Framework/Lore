
//Header
#include "../include/SDLHelpers.h"
//Lore
#include "../include/WindowManager.h"

//Usings
USING_NS_LORE

NS_LORE_BEGIN

SDL_Point SDLHelpers::make_point(int x, int y)
{
    return (SDL_Point){x, y};
}

SDL_Rect SDLHelpers::make_rect(int x, int y, int w, int h)
{
    return (SDL_Rect){x, y, w, h};
}

SDL_Color SDLHelpers::make_color(int r, int g, int b, int a /* = 255 */)
{
    //COWTODO: Check errors.
    return (SDL_Color){r, g, b, a};
}

SDL_Texture* SDLHelpers::load_texture_from_file(const std::string &filename)
{
    //COWTODO: Check errors.
    auto surface = IMG_Load(filename.c_str());
    return make_texture_free(surface);
}

SDL_Texture* SDLHelpers::make_texture_free(SDL_Surface *surface)
{
    //COWTODO: Check errors.
    auto renderer = WindowManager::instance()->getRenderer();

    auto texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    return texture;
}

//Font
TTF_Font* SDLHelpers::load_font_from_file(const std::string &filename, int size)
{
    auto font = TTF_OpenFont(filename.c_str(), 16);
    return font;
}

NS_LORE_END
