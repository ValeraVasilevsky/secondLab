#include "FileLoggerDecorator.hpp"
#include <fstream>

FileLoggerDecorator::FileLoggerDecorator(std::unique_ptr<Logger> logger, const std::string& fname)
    : wrapped(std::move(logger)), filename(fname) {}

void FileLoggerDecorator::log(const std::string& message) {
    wrapped->log(message);

    std::ofstream file(filename, std::ios::app);
    if (file.is_open()) {
        file << message << std::endl;
        file.close();
    }
}