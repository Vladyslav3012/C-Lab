#ifndef ALARM_HUB_H
#define ALARM_HUB_H

#include <iostream>
#include <memory>
#include <string>

class SensorDevice;

class AlarmHub {
public:
    std::string name;
    std::shared_ptr<SensorDevice> sensor;

    explicit AlarmHub(const std::string& n);
    ~AlarmHub();
};

#endif
