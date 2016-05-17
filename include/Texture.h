#ifndef __Lore_include_Texture_h__
#define __Lore_include_Texture_h__

//std
#include <string>
//Lore
#include "Lore_Utils.h"
#include "Rectangle.h"

NS_LORE_BEGIN

class Texture
{
    // CTOR / DTOR //
public:
    Texture(const std::string &filename);
    Texture(const std::string &filename, const Rectangle &sourceRect);

    ~Texture();


    // Public Methods //
public:
    void setSourceRect(const Rectangle &rect);
    const Rectangle& getSourceRect() const;

    // iVars //
private:
    SDL_Texture *m_pTexture;
};

NS_LORE_END
#endif // __Lore_include_Texture_h__ //
