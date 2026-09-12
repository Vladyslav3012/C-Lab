#include "speaker.h"
#include <iostream>

using namespace std;

Speaker::Speaker()
    : SoundDevice(), diameter(10), impedance(8) {
    cout << "Конструктор Speaker\n";
}

Speaker::Speaker(string model, int power, double price, int diameter, int impedance)
    : SoundDevice(model, power, price), diameter(10), impedance(8) {
    setDiameter(diameter);
    setImpedance(impedance);
    cout << "Конструктор Speaker (з параметрами)\n";
}

Speaker::~Speaker() {
    cout << "Деструктор Speaker\n";
}

void Speaker::setDiameter(int d) {
    if (d < 1 || d > 100) {
        cout << "Помилка: діаметр має бути від 1 до 100 см!\n";
        return;
    }
    diameter = d;
}

void Speaker::setImpedance(int z) {
    if (z < 1 || z > 32) {
        cout << "Помилка: опір має бути від 1 до 32 Ом!\n";
        return;
    }
    impedance = z;
}

void Speaker::display() const {
    cout << "Тип: " << getType()
         << ", модель: " << getModel()
         << ", потужність: " << getPower() << " Вт"
         << ", ціна: " << getPrice() << " грн"
         << ", діаметр: " << diameter << " см"
         << ", опір: " << impedance << " Ом\n";
}

string Speaker::getType() const {
    return "Динамік";
}
