#ifndef __Lore_include_Font_h__
#define __Lore_include_Font_h__

//std
#include <string>
//Lore
#include "Lore_Utils.h"

NS_LORE_BEGIN

class Font
{
public:
    typedef std::shared_ptr<Font> SPtr;

    // CTOR //
public:
    Font(TTF_Font *font);
    ~Font();

    COREGAME_DISALLOW_COPY_MOVE_ASSIGNS(Font);

    // iVars //
private:
    TTF_Font *m_pFont;
};

NS_LORE_END
#endif // __Lore_include_Font_h__ //


