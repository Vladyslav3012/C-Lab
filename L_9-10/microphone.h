#ifndef MICROPHONE_H
#define MICROPHONE_H

#include "sound_device.h"
#include <string>

class Microphone : public SoundDevice {
private:
    bool wireless;
    std::string pattern;

public:
    Microphone();
    Microphone(std::string model, int power, double price, bool wireless, std::string pattern);
    ~Microphone();

    void setWireless(bool wireless);
    void setPattern(std::string pattern);

    void inputData();

    virtual void display() const;
    virtual std::string getType() const;
};

#endif
