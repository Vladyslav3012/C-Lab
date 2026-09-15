#include "office_alarm.h"
#include "alarm_exception.h"
#include <iostream>

using namespace std;

OfficeAlarm::OfficeAlarm()
    : Alarm(), floor(1) {}

OfficeAlarm::OfficeAlarm(int sensors, bool wireless, const string& method, int floor)
    : Alarm(sensors, wireless, method), floor(1) {
    setFloor(floor);
}

OfficeAlarm::~OfficeAlarm() {}

void OfficeAlarm::setFloor(int f) {
    if (f < 1 || f > 100) {
        throw ValidationException("поверх має бути від 1 до 100");
    }
    floor = f;
}

int OfficeAlarm::getFloor() const {
    return floor;
}

string OfficeAlarm::getType() const {
    return "Офісна сигналізація";
}

void OfficeAlarm::display() const {
    cout << "Тип: " << getType()
         << ", датчиків: " << getSensorCount()
         << ", бездротові: " << (getHasWireless() ? "так" : "ні")
         << ", оповіщення: " << getAlertMethod()
         << ", поверх: " << floor << "\n";
}
