#ifndef SPEAKER_H
#define SPEAKER_H

#include "sound_device.h"

class Speaker : public SoundDevice {
private:
    int diameter;
    int impedance;

public:
    Speaker();
    Speaker(std::string model, int power, double price, int diameter, int impedance);
    ~Speaker();

    void setDiameter(int diameter);
    void setImpedance(int impedance);

    virtual void display() const;
    virtual std::string getType() const;
};

#endif
