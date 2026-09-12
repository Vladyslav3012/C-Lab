#ifndef SOUND_DEVICE_H
#define SOUND_DEVICE_H

#include <string>

struct device_s_t {
    std::string model;
    int power;
    double price;
};

class SoundDevice {
private:
    device_s_t data;

public:
    SoundDevice();
    SoundDevice(std::string model, int power, double price);
    virtual ~SoundDevice();

    void setModel(std::string model);
    void setPower(int power);
    void setPrice(double price);

    std::string getModel() const;
    int getPower() const;
    double getPrice() const;

    virtual void display() const;
    virtual std::string getType() const;
};

#endif
