//Lore
#include "../include/Font.h"

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
    cerr << "Font DTOR" << endl;

    TTF_CloseFont(m_pFont);
    m_pFont = nullptr;
}

