#ifndef SIGNALING_H
#define SIGNALING_H

#include <iostream>
#include <string>

class Signaling {
private:
    int sensorCount;
    bool hasWireless;
    std::string alertMethod;

public:
    Signaling();
    Signaling(int sensors, bool wireless, const std::string& method);
    ~Signaling();

    int getSensorCount() const;
    bool getHasWireless() const;
    std::string getAlertMethod() const;

    void display() const;

    bool operator>(const Signaling& other) const;
    friend std::ostream& operator<<(std::ostream& out, const Signaling& s);
};

#endif
