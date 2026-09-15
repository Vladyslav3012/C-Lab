#ifndef OFFICE_ALARM_H
#define OFFICE_ALARM_H

#include "alarm.h"

class OfficeAlarm : public Alarm {
private:
    int floor;

public:
    OfficeAlarm();
    OfficeAlarm(int sensors, bool wireless, const std::string& method, int floor);
    ~OfficeAlarm();

    void setFloor(int floor);
    int getFloor() const;

    virtual std::string getType() const;
    virtual void display() const;
};

#endif
