#ifndef __Lore_include_Text_h__
#define __Lore_include_Text_h__

//std
#include <string>
//Lore
#include "Lore_Utils.h"
#include "Color.h"
#include "Font.h"
#include "IDrawable.h"
#include "ITransformable.h"
#include "Rectangle.h"
#include "Texture.h"


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
    void setString(const std::string &str);
    void setString(const char *fmt, ...);
    const std::string& getString() const;

    //Color
    void setForegroundColor(const Color &color);
    const Color& getForegroundColor() const;

    void setBackgroundColor(const Color &color);
    const Color& getBackgroundColor() const;

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

    Font::SPtr    m_pFont;
    Texture::SPtr m_pCurrentTexture;
    Rectangle     m_textureRect;

    Texture::Flip m_flip;

    Color m_fgColor;
    Color m_bgColor;
};

NS_LORE_END
#endif // __Lore_include_Text_h__ //
