#ifndef FTD_TOOLS_LOG_H
#define FTD_TOOLS_LOG_H

#include <format>
#include <string_view>
#include <utility>

namespace ftd {

enum class LogLevel {
    Off,
    Error,
    Warning,
    Debug,
    Info,
    Trace
};

class Logger {
public:
    static Logger* get();

public:
    virtual ~Logger() = default;

    virtual void error(std::string_view message) noexcept = 0;
    virtual void warning(std::string_view message) noexcept = 0;
    virtual void debug(std::string_view message) noexcept = 0;
    virtual void info(std::string_view message) noexcept = 0;
    virtual void trace(std::string_view message) noexcept = 0;

    constexpr LogLevel level() const noexcept { return level_; }
    virtual void level(LogLevel level) noexcept = 0;

    virtual void pattern(const std::string& fmt) noexcept = 0;

protected:
    LogLevel level_ = LogLevel::Debug;
};

// 使用默认logger输出，即Logger::get_logger()返回的logger
namespace log {

void pattern(const std::string& fmt);
void level(LogLevel level);

template<typename... T>
void error(std::format_string<T...> std, T&&... args)
{
    Logger::get()->error(std::format(std, std::forward<T>(args)...));
}

template<typename... T>
void warning(std::format_string<T...> std, T&&... args)
{
    Logger::get()->warning(std::format(std, std::forward<T>(args)...));
}

template<typename... T>
void debug(std::format_string<T...> std, T&&... args)
{
    Logger::get()->debug(std::format(std, std::forward<T>(args)...));
}

template<typename... T>
void info(std::format_string<T...> std, T&&... args)
{
    Logger::get()->info(std::format(std, std::forward<T>(args)...));
}

template<typename... T>
void trace(std::format_string<T...> std, T&&... args)
{
    Logger::get()->trace(std::format(std, std::forward<T>(args)...));
}

} // namespace ftd::log
} // namespace ftd

#endif // FTD_TOOLS_LOG_H
