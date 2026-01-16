#include "EncryptionDecorator.hpp"

EncryptionDecorator::EncryptionDecorator(std::unique_ptr<Logger> logger, int s)
    : wrapped(std::move(logger)), shift(s % 256) {}

std::string EncryptionDecorator::encrypt(const std::string& text) const {
    std::string result = text;
    for (char& c : result) {
        c = static_cast<char>(static_cast<unsigned char>(c) + shift);
    }
    return result;
}

void EncryptionDecorator::log(const std::string& message) {
    std::string encrypted = encrypt(message);
    wrapped->log(encrypted);
}