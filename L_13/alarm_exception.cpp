#include "alarm_exception.h"

AlarmException::AlarmException(const std::string& msg) : message(msg) {}

AlarmException::~AlarmException() {}

const char* AlarmException::what() const {
    return message.c_str();
}

ValidationException::ValidationException(const std::string& msg)
    : AlarmException(msg) {}

FileException::FileException(const std::string& msg)
    : AlarmException(msg) {}
