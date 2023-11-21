#ifndef FTD_TOOLS_SPDLOGGER_H
#define FTD_TOOLS_SPDLOGGER_H

#include "ftd/Log.h"

#include <spdlog/spdlog.h>

#include <memory>

namespace ftd {

class SpdLogger: public Logger {
public:
    SpdLogger();
    explicit SpdLogger(const std::string& name);

    void error(std::string_view message) noexcept override;
    void warning(std::string_view message) noexcept override;
    void debug(std::string_view message) noexcept override;
    void info(std::string_view message) noexcept override;
    void trace(std::string_view message) noexcept override;

    void level(LogLevel level) noexcept override;
    void pattern(const std::string& fmt) noexcept override;

private:
    std::shared_ptr<spdlog::logger> logger_;
};

} // namespace ftd

#endif // FTD_TOOLS_SPDLOGGER_H
