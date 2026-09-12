#ifndef ALARM_H
#define ALARM_H

#include <string>
#include <vector>

struct alarm_s_t {
    int sensorCount;
    bool hasWireless;
    std::string alertMethod;
};

class AlarmSystem {
private:
    std::vector<alarm_s_t> alarms;

public:
    AlarmSystem();
    ~AlarmSystem();

    void addAlarm(int sensors, bool wireless, std::string method);
    void insertAlarm(int index, int sensors, bool wireless, std::string method);
    void removeAlarm(int index);
    void swapAlarms(int i, int j);
    void clearAll();

    void setSensorCount(int index, int sensors);
    void setHasWireless(int index, bool wireless);
    void setAlertMethod(int index, std::string method);

    void displayAll() const;
    void displayByWireless(bool wireless) const;
};

#endif
