#ifndef SIGNALING_H
#define SIGNALING_H

#include <cstddef>
#include <iostream>

class Signaling {
private:
    int* sensors;
    std::size_t sensorCount;
    bool hasWireless;
    char* alertMethod;

    void allocate(std::size_t count, bool wireless, const char* method);
    void freeResources();

public:
    Signaling(std::size_t count, bool wireless, const char* method);
    ~Signaling();

    Signaling(const Signaling& other);
    Signaling& operator=(const Signaling& other);

    Signaling(Signaling&& other) noexcept;
    Signaling& operator=(Signaling&& other) noexcept;

    static Signaling inputFromKeyboard();

    std::size_t getSensorCount() const;
    bool getHasWireless() const;
    const char* getAlertMethod() const;
    const int* getSensors() const;

    void display() const;
};

#endif
