#ifndef ALARM_EXCEPTION_H
#define ALARM_EXCEPTION_H

#include <string>

class AlarmException {
private:
    std::string message;

public:
    AlarmException(const std::string& msg);
    virtual ~AlarmException();
    virtual const char* what() const;
};

class ValidationException : public AlarmException {
public:
    ValidationException(const std::string& msg);
};

class FileException : public AlarmException {
public:
    FileException(const std::string& msg);
};

#endif
