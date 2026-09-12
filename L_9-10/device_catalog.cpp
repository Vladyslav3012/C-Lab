#include "device_catalog.h"
#include <iostream>

using namespace std;

DeviceCatalog::DeviceCatalog() {
    cout << "Конструктор DeviceCatalog\n";
}

DeviceCatalog::~DeviceCatalog() {
    devices.clear();
    cout << "Деструктор DeviceCatalog\n";
}

void DeviceCatalog::add(SoundDevice* device) {
    if (device == nullptr) {
        cout << "Помилка: порожній вказівник!\n";
        return;
    }
    devices.push_back(device);
}

void DeviceCatalog::displayAll() const {
    if (devices.empty()) {
        cout << "Каталог порожній.\n";
        return;
    }
    for (size_t i = 0; i < devices.size(); i++) {
        cout << "[" << i << "] ";
        devices[i]->display();
    }
}

double DeviceCatalog::totalPrice() const {
    double sum = 0;
    for (size_t i = 0; i < devices.size(); i++) {
        sum += devices[i]->getPrice();
    }
    return sum;
}

int DeviceCatalog::count() const {
    return (int)devices.size();
}
