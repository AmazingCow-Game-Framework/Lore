#ifndef __Lore_include_SDLHelpers_h__
#define __Lore_include_SDLHelpers_h__

//std
#include <string>
//Lore
#include "Lore_Utils.h"


NS_LORE_BEGIN

namespace SDLHelpers {

// Some SDL Helpers //
SDL_Point    make_point(int x, int y);
SDL_Rect     make_rect(int x, int y, int w, int h);
SDL_Color    make_color(int r, int g, int b, int a = 255);

//Texture
SDL_Texture* load_texture_from_file(const std::string &filename);
SDL_Texture* make_texture_free(SDL_Surface *surface);

//Font
TTF_Font* load_font_from_file(const std::string &filename, int size);

}; //namespace SDLHelpers

NS_LORE_END
#endif // __Lore_include_SDLHelpers_h__ //
