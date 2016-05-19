#ifndef __Lore_include_Text_h__
#define __Lore_include_Text_h__

//std
#include <string>
//Lore
#include "Lore_Utils.h"
#include "IDrawable.h"
#include "ITransformable.h"
#include "Font.h"

NS_LORE_BEGIN

class Text : public IDrawable, public ITransformable
{
    // CTOR //
public:
    Text();
    Text(const std::string &filename, int size);


    // Public Methods //
public:
    //Draw
    virtual void draw() override;

    //String
    void setString(char *fmt, ...);
    const std::string& getString() const;

    //Color
    void setForegroundColor(const SDL_Color &color);
    const SDL_Color& getForegroundColor() const;

    void setBackgroundColor(const SDL_Color &color);
    const SDL_Color& getBackgroundColor() const;

    //Font
    void setFont(Font::SPtr font);
    void loadFont(const std::string &filename, int size);

    //Bounds
    Rectangle getBounds() const;

    // Private Methods //
private:
    void calculate();

    // iVars //
private:
    std::string m_string;

    Font::SPtr m_pFont;

    SDL_Color m_fgColor;
    SDL_Color m_bgColor;

    Vector2 m_size;
};

NS_LORE_END
#endif // __Lore_include_Text_h__ //
