#ifndef __Lore_include_SDLHelpers_h__
#define __Lore_include_SDLHelpers_h__

//std
#include <string>
//Lore
#include "Lore_Utils.h"
#include "Color.h"
#include "Rectangle.h"
#include "Vector2.h"


NS_LORE_BEGIN
namespace SDLHelpers {

// Point //
SDL_Point make_point(int x, int y);
SDL_Point make_point(const Vector2 &vector);
SDL_Point make_point(const Rectangle &rect);

// Rectangle //
SDL_Rect make_rect(int x, int y, int w, int h);
SDL_Rect make_rect(const Vector2 &pos, const Vector2 &size);
SDL_Rect make_rect(const Rectangle &rect);

// Color //
SDL_Color make_color(int r, int g, int b, int a = 255);
SDL_Color make_color(const Color &color);

// Texture //
SDL_Texture* load_texture_from_file(const std::string &filename);
SDL_Texture* make_texture_free(SDL_Surface *surface);
SDL_Texture* make_texture_empty(int width = 0, int height = 0);

// Font //
TTF_Font* load_font_from_file(const std::string &filename, int size);


}; //namespace SDLHelpers
NS_LORE_END
#endif // __Lore_include_SDLHelpers_h__ //
