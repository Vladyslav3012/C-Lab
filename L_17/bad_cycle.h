#ifndef BAD_SENSOR_DEVICE_H
#define BAD_SENSOR_DEVICE_H

#include <iostream>
#include <memory>
#include <string>

class BadAlarmHub;

class BadSensorDevice {
public:
    std::string name;
    std::shared_ptr<BadAlarmHub> hub;

    explicit BadSensorDevice(const std::string& n);
    ~BadSensorDevice();
};

class BadAlarmHub {
public:
    std::string name;
    std::shared_ptr<BadSensorDevice> sensor;

    explicit BadAlarmHub(const std::string& n);
    ~BadAlarmHub();
};

#endif
