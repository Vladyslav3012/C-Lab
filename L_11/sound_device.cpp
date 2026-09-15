#include "sound_device.h"
#include <iostream>

using namespace std;

SoundDevice::SoundDevice() {
    data.model = "unknown";
    data.power = 1;
    data.price = 1.0;
    cout << "Конструктор SoundDevice\n";
}

SoundDevice::SoundDevice(string model, int power, double price) {
    data.model = "unknown";
    data.power = 1;
    data.price = 1.0;
    setModel(model);
    setPower(power);
    setPrice(price);
    cout << "Конструктор SoundDevice (з параметрами)\n";
}

SoundDevice::~SoundDevice() {
    cout << "Деструктор SoundDevice (" << data.model << ")\n";
}

void SoundDevice::setModel(string model) {
    if (model.empty()) {
        cout << "Помилка: модель не може бути порожньою!\n";
        return;
    }
    data.model = model;
}

void SoundDevice::setPower(int power) {
    if (power < 1 || power > 10000) {
        cout << "Помилка: потужність має бути від 1 до 10000 Вт!\n";
        return;
    }
    data.power = power;
}

void SoundDevice::setPrice(double price) {
    if (price <= 0) {
        cout << "Помилка: ціна має бути більшою за 0!\n";
        return;
    }
    data.price = price;
}

string SoundDevice::getModel() const { return data.model; }
int SoundDevice::getPower() const { return data.power; }
double SoundDevice::getPrice() const { return data.price; }

string SoundDevice::getType() const {
    return "Звуковий пристрій";
}
