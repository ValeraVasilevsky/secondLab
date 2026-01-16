#ifndef TIMESTAMP_DECORATOR_HPP
#define TIMESTAMP_DECORATOR_HPP

#include "Logger.hpp"
#include <memory>
#include <string>

class TimestampDecorator : public Logger {
private:
    std::unique_ptr<Logger> wrapped;

public:
    explicit TimestampDecorator(std::unique_ptr<Logger> logger);
    void log(const std::string& message) override;
};

#endif // TIMESTAMP_DECORATOR_HPP