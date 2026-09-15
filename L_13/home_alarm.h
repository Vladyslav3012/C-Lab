#ifndef HOME_ALARM_H
#define HOME_ALARM_H

#include "alarm.h"
#include <string>

class HomeAlarm : public Alarm {
private:
    std::string zone;

public:
    HomeAlarm();
    HomeAlarm(int sensors, bool wireless, const std::string& method, const std::string& zone);
    ~HomeAlarm();

    void setZone(const std::string& zone);
    std::string getZone() const;

    virtual std::string getType() const;
    virtual void display() const;
};

#endif
