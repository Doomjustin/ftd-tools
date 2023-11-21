#include "ftd/Log.h"
#include "SpdLogger.h"

namespace ftd {

Logger* Logger::get()
{
    static SpdLogger logger{};

    return &logger;
}

std::unique_ptr<Logger> Logger::make(const std::string& name)
{
    return std::make_unique<SpdLogger>(name);
}


namespace log {

void pattern(const std::string& fmt)
{
    Logger::get()->pattern(fmt);
}

void level(LogLevel level)
{
    Logger::get()->level(level);
}

} // namespace ftd::log
} // namespace ftd
