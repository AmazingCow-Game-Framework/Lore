#ifndef __Lore_include_ErrorControl_h__
#define __Lore_include_ErrorControl_h__

//std
#include <string>
//Lore
#include "Lore_Utils.h"


NS_LORE_BEGIN
namespace ErrorControl {

// Enums / Constants //
enum {
    LORE_ERROR_DONT_DIE                    = 0,

    LORE_ERROR_DIE_ON_SDL_ERROR            = 1 << 1,
    LORE_ERROR_DIE_ON_SOUND_MANAGER_ERROR  = 1 << 2,
    LORE_ERROR_DIE_ON_GAME_MANAGER_ERROR   = 1 << 3,
    LORE_ERROR_DIE_ON_ASSETS_MANAGER_ERROR = 1 << 4,
    LORE_ERROR_DIE_ON_WINDOW_MANAGER_ERROR = 1 << 5,
    LORE_ERROR_DIE_ON_INPUT_MANAGER_ERROR  = 1 << 6,

    LORE_ERROR_DIE_ON_ALL_ERRORS =
        LORE_ERROR_DIE_ON_SDL_ERROR            |
        LORE_ERROR_DIE_ON_SOUND_MANAGER_ERROR  |
        LORE_ERROR_DIE_ON_GAME_MANAGER_ERROR   |
        LORE_ERROR_DIE_ON_ASSETS_MANAGER_ERROR |
        LORE_ERROR_DIE_ON_WINDOW_MANAGER_ERROR |
        LORE_ERROR_DIE_ON_INPUT_MANAGER_ERROR
};


// Vars Declarations //
extern int DieMode;


// Functions //
bool ShouldDie(int value);

void DieIfNeeded(int errorModeValue,
                 const std::string &owner,
                 const char *fmt,
                 ...);

} //namespace ErrorControl
NS_LORE_END
#endif // __Lore_include_ErrorControl_h__ //
