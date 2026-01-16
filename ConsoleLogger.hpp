#ifndef CONSOLE_LOGGER_HPP
#define CONSOLE_LOGGER_HPP

#include "Logger.hpp"

class ConsoleLogger : public Logger {
public:
    void log(const std::string& message) override;
};

#endif // CONSOLE_LOGGER_HPP