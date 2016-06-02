#ifndef __Lore_src_private_include_Log_h__
#define __Lore_src_private_include_Log_h__

//std
#include <cstdarg>
#include <string>

//Lore
#include "../../../include/Lore_Utils.h" //Public
#include "Lore_Private_Utils.h"          //Private


NS_LORE_BEGIN
NS_LORE_PVT_BEGIN

void _private_log(CoreGame::Log::Type logType,
                  const std::string &owner,
                  const char *fmt, ...);

NS_LORE_PVT_END
NS_LORE_END


////////////////////////////////////////////////////////////////////////////////
// Log Macros - DEBUG AND RELEASE                                             //
////////////////////////////////////////////////////////////////////////////////
#define PVT_LORE_LOG_DEBUG(_owner_, _fmt_, ...)                    \
    Lore::Lore_Private::_private_log(CoreGame::Log::Type::Debug4,                      \
                                     _owner_,                      \
                                     _fmt_,                        \
                                     ##__VA_ARGS__)

#define PVT_LORE_LOG_ERROR(_owner_, _fmt_, ...)                  \
    Lore::Lore_Private::_private_log(CoreGame::Log::Type::Error,                     \
                                     _owner_,                    \
                                     _fmt_,                      \
                                     ##__VA_ARGS__)

#define PVT_LORE_LOG_WARNING(_owner_, _fmt_, ...)                  \
    Lore::Lore_Private::_private_log(CoreGame::Log::Type::Warning,                     \
                                     _owner_,                      \
                                     _fmt_,                        \
                                     ##__VA_ARGS__)


////////////////////////////////////////////////////////////////////////////////
// Log Macros - ONLY IN DEBUG                                                 //
////////////////////////////////////////////////////////////////////////////////
#if defined(NDEBUG)
    #define PVT_LORE_DLOG_DEBUG(_owner_, _fmt_, ...)   do {} while(0)
    #define PVT_LORE_DLOG_ERROR(_owner_, _fmt_, ...)   do {} while(0)
    #define PVT_LORE_DLOG_WARNING(_owner_, _fmt_, ...) do {} while(0)

#else //defined(NDEBUG)
    #define PVT_LORE_DLOG_DEBUG(_owner_, _fmt_, ...) \
        PVT_LORE_LOG_DEBUG(_owner_, _fmt_, ##__VA_ARGS__)

    #define PVT_LORE_DLOG_ERROR(_owner_, _fmt_, ...) \
        PVT_LORE_LOG_ERROR(_owner_, _fmt_, ##__VA_ARGS__)

    #define PVT_LORE_DLOG_WARNING(_owner_, _fmt_, ...) \
        PVT_LORE_LOG_WARNING(_owner_, _fmt_, ##__VA_ARGS__)

#endif //defined(NDEBUG)

#endif // __Lore_src_private_include_Log_h__ //
