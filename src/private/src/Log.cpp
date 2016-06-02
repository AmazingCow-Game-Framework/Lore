//Header
#include "../include/Log.h"



void Lore::Lore_Private::_private_log(CoreGame::Log::Type logType,
                  const std::string &owner,
                  const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);

    auto buffer = CoreGame::StringUtils::vformat(fmt, args);

    va_end(args);


    CoreGame::Log::GetDefaultLogger().log(logType,
                                          "%s - %s",
                                          owner.c_str(),
                                          buffer.c_str());
}
