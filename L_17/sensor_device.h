#ifndef SENSOR_DEVICE_H
#define SENSOR_DEVICE_H

#include <iostream>
#include <memory>
#include <string>

class AlarmHub;

class SensorDevice {
public:
    std::string name;
    std::weak_ptr<AlarmHub> hub;

    explicit SensorDevice(const std::string& n);
    ~SensorDevice();
};

#endif
