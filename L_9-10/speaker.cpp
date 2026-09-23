#include "speaker.h"
#include <iostream>
#include <limits>

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

void Speaker::inputData() {
    string model;
    int power;
    double price;
    int d;
    int z;

    while (true) {
        cout << "Модель динаміка (можна кілька слів): ";
        getline(cin, model);
        if (!model.empty()) {
            break;
        }
        cout << "Помилка: модель не може бути порожньою!\n";
    }

    while (true) {
        cout << "Потужність (1..10000 Вт): ";
        if (cin >> power && power >= 1 && power <= 10000) {
            break;
        }
        cout << "Помилка: потужність має бути від 1 до 10000 Вт!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    while (true) {
        cout << "Ціна (> 0): ";
        if (cin >> price && price > 0) {
            break;
        }
        cout << "Помилка: ціна має бути більшою за 0!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    while (true) {
        cout << "Діаметр (1..100 см): ";
        if (cin >> d && d >= 1 && d <= 100) {
            break;
        }
        cout << "Помилка: діаметр має бути від 1 до 100 см!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    while (true) {
        cout << "Опір (1..32 Ом): ";
        if (cin >> z && z >= 1 && z <= 32) {
            break;
        }
        cout << "Помилка: опір має бути від 1 до 32 Ом!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    setModel(model);
    setPower(power);
    setPrice(price);
    setDiameter(d);
    setImpedance(z);
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
