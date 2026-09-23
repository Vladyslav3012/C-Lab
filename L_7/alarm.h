#ifndef ALARM_H
#define ALARM_H

#include <array>
#include <string>

const int SIZE = 5;

struct alarm_s_t {
    int sensorCount;
    bool hasWireless;
    std::string alertMethod;
};

class AlarmSystem {
private:
    std::array<alarm_s_t, SIZE> alarms;
    int count;

public:
    AlarmSystem();
    ~AlarmSystem();

    void addAlarm(int sensors, bool wireless, std::string method);
    void inputAlarm();
    void setSensorCount(int index, int sensors);
    void setHasWireless(int index, bool wireless);
    void setAlertMethod(int index, std::string method);

    void displayAll() const;
    void displayByWireless(bool wireless) const;
    void displayByMinSensors(int minSensors) const;
};

#endif
