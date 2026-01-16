#ifndef FILE_LOGGER_DECORATOR_HPP
#define FILE_LOGGER_DECORATOR_HPP

#include "Logger.hpp"
#include <memory>
#include <string>

class FileLoggerDecorator : public Logger {
private:
    std::unique_ptr<Logger> wrapped;
    std::string filename;

public:
    FileLoggerDecorator(std::unique_ptr<Logger> logger, const std::string& fname);
    void log(const std::string& message) override;
};

#endif // FILE_LOGGER_DECORATOR_HPP