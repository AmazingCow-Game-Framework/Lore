//Header
#include "../include/IDrawable.h"
//Lore
#include "../include/AssetsManager.h"

//Usings
USING_NS_LORE

// CTOR / DTOR //
IDrawable::IDrawable() :
    m_visible(true)
{
    //Empty...
}

IDrawable::~IDrawable()
{
    //Empty...
}

// Public Methods
void IDrawable::setIsVisible(bool visible)
{
    m_visible = visible;
}

bool IDrawable::getIsVisible() const
{
    return m_visible;
}

