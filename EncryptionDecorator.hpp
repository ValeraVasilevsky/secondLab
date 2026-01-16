#ifndef ENCRYPTION_DECORATOR_HPP
#define ENCRYPTION_DECORATOR_HPP

#include "Logger.hpp"
#include <memory>
#include <string>

class EncryptionDecorator : public Logger {
private:
    std::unique_ptr<Logger> wrapped;
    int shift;

public:
    explicit EncryptionDecorator(std::unique_ptr<Logger> logger, int s = 3);
    std::string encrypt(const std::string& text) const;
    void log(const std::string& message) override;
};

#endif // ENCRYPTION_DECORATOR_HPP