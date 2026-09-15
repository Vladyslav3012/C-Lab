#include "device_friend.h"
#include <iostream>
#include <string>

using namespace std;

DeviceFriend::DeviceFriend() {
    cout << "Конструктор DeviceFriend\n";
}

DeviceFriend::~DeviceFriend() {
    items.clear();
    cout << "Деструктор DeviceFriend\n";
}

void DeviceFriend::inputMicrophone(Microphone& mic, string model, int power,
                                   double price, bool wireless, string pattern) {
    mic.setModel(model);
    mic.setPower(power);
    mic.setPrice(price);
    mic.setWireless(wireless);
    mic.setPattern(pattern);
}

void DeviceFriend::inputSpeaker(Speaker& sp, string model, int power,
                                double price, int diameter, int impedance) {
    sp.setModel(model);
    sp.setPower(power);
    sp.setPrice(price);
    sp.setDiameter(diameter);
    sp.setImpedance(impedance);
}

void DeviceFriend::printBase(SoundDevice& device) const {
    cout << "Тип: " << device.getType()
         << ", модель: " << device.data.model
         << ", потужність: " << device.data.power << " Вт"
         << ", ціна: " << device.data.price << " грн\n";
}

void DeviceFriend::printMicrophone(Microphone& mic) const {
    cout << "Тип: " << mic.getType()
         << ", модель: " << mic.data.model
         << ", потужність: " << mic.data.power << " Вт"
         << ", ціна: " << mic.data.price << " грн"
         << ", бездротовий: " << (mic.wireless ? "так" : "ні")
         << ", діаграма: " << mic.pattern << "\n";
}

void DeviceFriend::printSpeaker(Speaker& sp) const {
    cout << "Тип: " << sp.getType()
         << ", модель: " << sp.data.model
         << ", потужність: " << sp.data.power << " Вт"
         << ", ціна: " << sp.data.price << " грн"
         << ", діаметр: " << sp.diameter << " см"
         << ", опір: " << sp.impedance << " Ом\n";
}

void DeviceFriend::addToCatalog(Microphone& mic) {
    catalog_item_t item;
    item.type = mic.getType();
    item.model = mic.data.model;
    item.power = mic.data.power;
    item.price = mic.data.price;
    item.extra = string("бездротовий=") + (mic.wireless ? "так" : "ні")
               + ", діаграма=" + mic.pattern;
    items.push_back(item);
}

void DeviceFriend::addToCatalog(Speaker& sp) {
    catalog_item_t item;
    item.type = sp.getType();
    item.model = sp.data.model;
    item.power = sp.data.power;
    item.price = sp.data.price;
    item.extra = "діаметр=" + to_string(sp.diameter) + " см, опір="
               + to_string(sp.impedance) + " Ом";
    items.push_back(item);
}

void DeviceFriend::displayCatalog() const {
    if (items.empty()) {
        cout << "Каталог порожній.\n";
        return;
    }
    for (size_t i = 0; i < items.size(); i++) {
        cout << "[" << i << "] тип: " << items[i].type
             << ", модель: " << items[i].model
             << ", потужність: " << items[i].power << " Вт"
             << ", ціна: " << items[i].price << " грн"
             << ", " << items[i].extra << "\n";
    }
}

double DeviceFriend::totalPrice() const {
    double sum = 0;
    for (size_t i = 0; i < items.size(); i++) {
        sum += items[i].price;
    }
    return sum;
}

int DeviceFriend::count() const {
    return (int)items.size();
}

double DeviceFriend::maxPrice() const {
    if (items.empty()) {
        return 0;
    }
    double maxVal = items[0].price;
    for (size_t i = 1; i < items.size(); i++) {
        if (items[i].price > maxVal) {
            maxVal = items[i].price;
        }
    }
    return maxVal;
}
