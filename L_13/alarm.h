#ifndef ALARM_H
#define ALARM_H

#include <iostream>
#include <string>

struct alarm_s_t {
    int sensorCount;
    bool hasWireless;
    std::string alertMethod;
};

class Alarm {
private:
    alarm_s_t data;

public:
    Alarm();
    Alarm(int sensors, bool wireless, const std::string& method);
    virtual ~Alarm();

    void setSensorCount(int sensors);
    void setHasWireless(bool wireless);
    void setAlertMethod(const std::string& method);

    int getSensorCount() const;
    bool getHasWireless() const;
    std::string getAlertMethod() const;

    virtual std::string getType() const;
    virtual void display() const;

    // порівняння за кількістю датчиків і способом оповіщення
    friend bool operator==(const Alarm& a, const Alarm& b);
    friend bool operator<(const Alarm& a, const Alarm& b);
    // об'єднання: сума датчиків, wireless = OR, method конкатенація
    friend Alarm operator+(const Alarm& a, const Alarm& b);
    friend std::ostream& operator<<(std::ostream& out, const Alarm& alarm);
};

#endif
