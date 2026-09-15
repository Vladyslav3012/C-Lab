#include "home_alarm.h"
#include "alarm_exception.h"
#include <iostream>

using namespace std;

HomeAlarm::HomeAlarm()
    : Alarm(), zone("вітальня") {}

HomeAlarm::HomeAlarm(int sensors, bool wireless, const string& method, const string& zone)
    : Alarm(sensors, wireless, method), zone("вітальня") {
    setZone(zone);
}

HomeAlarm::~HomeAlarm() {}

void HomeAlarm::setZone(const string& z) {
    if (z.empty()) {
        throw ValidationException("зона будинку не може бути порожньою");
    }
    zone = z;
}

string HomeAlarm::getZone() const {
    return zone;
}

string HomeAlarm::getType() const {
    return "Домашня сигналізація";
}

void HomeAlarm::display() const {
    cout << "Тип: " << getType()
         << ", датчиків: " << getSensorCount()
         << ", бездротові: " << (getHasWireless() ? "так" : "ні")
         << ", оповіщення: " << getAlertMethod()
         << ", зона: " << zone << "\n";
}
