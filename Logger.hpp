#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>

class Logger {
public:
    virtual ~Logger() = default;
    virtual void log(const std::string& message) = 0;
};

#endif // LOGGER_HPP