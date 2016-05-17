#ifndef __Lore_include_Text_h__
#define __Lore_include_Text_h__

//std
#include <string>
//Lore
#include "GameCommon.h"

NS_LORE_BEGIN

class Text
{
    // CTOR //
public:
    Text();
    Text(const std::string &filename, int size);


    // Public Methods //
public:
    //Draw
    void draw();

    //String
    void setString(char *fmt, ...);
    const std::string& getString() const;

    //Color
    void setForegroundColor(const SDL_Color &color);
    const SDL_Color& getForegroundColor() const;

    void setBackgroundColor(const SDL_Color &color);
    const SDL_Color& getBackgroundColor() const;

    //Posiiton
    void setPosition(const SDL_Point &position);
    SDL_Point getPosition() const;

    //Font
    void setFont(TTF_Font *font);
    void loadFont(const std::string &filename, int size);

    //Bounding Box
    const SDL_Rect& getBoundingBox() const;

    // Private Methods //
private:
    void calculate();


    // iVars //
private:
    std::string m_string;

    SDL_Color   m_fgColor;
    SDL_Color   m_bgColor;

    SDL_Rect m_srcRect;
    SDL_Rect m_dstRect;

    TTF_Font   *m_pFont;

    SDL_Texture *m_pTexture;
};

NS_LORE_END
#endif // __Lore_include_Text_h__ //
