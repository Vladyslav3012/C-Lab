#ifndef DEVICE_CATALOG_H
#define DEVICE_CATALOG_H

#include "sound_device.h"
#include <vector>

class DeviceCatalog {
private:
    std::vector<SoundDevice*> devices;

public:
    DeviceCatalog();
    ~DeviceCatalog();

    void add(SoundDevice* device);
    void displayAll() const;
    double totalPrice() const;
    int count() const;
};

#endif
