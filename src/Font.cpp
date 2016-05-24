//Header
#include "../include/Font.h"
//Lore
#include "../include/SDLHelpers.h"

//Usings
USING_NS_LORE;


// CTOR //
Font::Font(TTF_Font *font) :
    m_pFont(font)
{
    //Empty...
}

Font::~Font()
{
    COREGAME_DLOG(CoreGame::Log::Type::Debug4, "Lore::Font DTOR");

    TTF_CloseFont(m_pFont);
    m_pFont = nullptr;
}


// Public Methods //
Texture::SPtr Font::prepareTexture(const std::string &str,
                                   const Color &fgColor,
                                   const Color &bgColor)
{
    if(str.empty())
        return std::make_shared<Texture>(SDLHelpers::make_texture_empty());


    auto tmp_surface = TTF_RenderText_Shaded(m_pFont,
                                             str.c_str(),
                                             SDLHelpers::make_color(fgColor),
                                             SDLHelpers::make_color(bgColor));

    return std::make_shared<Texture>(SDLHelpers::make_texture_free(tmp_surface));
}
