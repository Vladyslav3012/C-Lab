#ifndef MICROPHONE_H
#define MICROPHONE_H

#include "sound_device.h"
#include <string>

class DeviceFriend;

class Microphone : public SoundDevice {
private:
    bool wireless;
    std::string pattern;

    friend class DeviceFriend;

public:
    Microphone();
    Microphone(std::string model, int power, double price, bool wireless, std::string pattern);
    ~Microphone();

    void setWireless(bool wireless);
    void setPattern(std::string pattern);

    virtual std::string getType() const;
};

#endif
