#include "TimestampDecorator.hpp"
#include <chrono>
#include <iomanip>
#include <sstream>
#include <iostream>

TimestampDecorator::TimestampDecorator(std::unique_ptr<Logger> logger)
    : wrapped(std::move(logger)) {}

void TimestampDecorator::log(const std::string& message) {
    auto now = std::chrono::system_clock::now();
    auto time_t = std::chrono::system_clock::to_time_t(now);
    std::ostringstream oss;
    oss << std::put_time(std::localtime(&time_t), "%Y-%m-%d %H:%M:%S");
    std::string timestamp = oss.str();
    wrapped->log("[" + timestamp + "] " + message);
}