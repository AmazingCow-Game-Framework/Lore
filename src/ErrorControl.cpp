
//Header
#include "../include/ErrorControl.h"
//Lore Private
#include "./private/include/Log.h"
//std
#include <cstdlib>

//Usings
USING_NS_LORE;


////////////////////////////////////////////////////////////////////////////////
// ErrorControl - Vars Definitions                                            //
////////////////////////////////////////////////////////////////////////////////
int ErrorControl::DieMode = ErrorControl::LORE_ERROR_DONT_DIE;



////////////////////////////////////////////////////////////////////////////////
// ErrorControl - Functions Implementations                                   //
////////////////////////////////////////////////////////////////////////////////
bool ErrorControl::ShouldDie(int value)
{
    return ErrorControl::DieMode & value;
}

void ErrorControl::DieIfNeeded(int errorModeValue,
                               const std::string &owner,
                               const char *fmt,
                               ...)
{
    va_list args;
    va_start(args, fmt);

    auto buffer = CoreGame::StringUtils::vformat(fmt, args);

    va_end(args);


    CoreGame::Log::GetDefaultLogger().log(CoreGame::Log::Type::Error,
                                          "%s\n----> %s",
                                          owner.c_str(),
                                          buffer.c_str());

    if(ErrorControl::ShouldDie(errorModeValue))
        abort();
}
