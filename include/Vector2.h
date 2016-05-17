#ifndef __Lore_include_Vector2_h__
#define __Lore_include_Vector2_h__

NS_LORE_BEGIN

class Vector2
{
    // CTOR / DTOR //
public:
    Vector2();
    Vector2(float value);
    Vector2(float x, float y);

    // Public Methods //
public:
    void  setX(float x);
    float getX() const;

    void  setY(float y);
    float getY() const;

    //COWTODO: Add the operators.

    // iVars //
private:
    float x, y;
};

NS_LORE_END
#endif // __Lore_include_Vector2_h__ //
