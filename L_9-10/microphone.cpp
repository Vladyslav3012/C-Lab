#include "microphone.h"
#include <iostream>
#include <limits>

using namespace std;

Microphone::Microphone()
    : SoundDevice(), wireless(false), pattern("кардіоїдна") {
    cout << "Конструктор Microphone\n";
}

Microphone::Microphone(string model, int power, double price, bool wireless, string pattern)
    : SoundDevice(model, power, price), wireless(false), pattern("кардіоїдна") {
    setWireless(wireless);
    setPattern(pattern);
    cout << "Конструктор Microphone (з параметрами)\n";
}

Microphone::~Microphone() {
    cout << "Деструктор Microphone\n";
}

void Microphone::setWireless(bool w) {
    wireless = w;
}

void Microphone::setPattern(string p) {
    if (p.empty()) {
        cout << "Помилка: діаграма спрямованості не може бути порожньою!\n";
        return;
    }
    pattern = p;
}

void Microphone::inputData() {
    string model;
    int power;
    double price;
    int wirelessFlag;
    string pat;

    while (true) {
        cout << "Модель мікрофона (можна кілька слів): ";
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
        cout << "Бездротовий (1 - так, 0 - ні): ";
        if (cin >> wirelessFlag && (wirelessFlag == 0 || wirelessFlag == 1)) {
            break;
        }
        cout << "Помилка: введіть 0 або 1!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while (true) {
        cout << "Діаграма спрямованості (можна кілька слів): ";
        getline(cin, pat);
        if (!pat.empty()) {
            break;
        }
        cout << "Помилка: діаграма спрямованості не може бути порожньою!\n";
    }

    setModel(model);
    setPower(power);
    setPrice(price);
    setWireless(wirelessFlag == 1);
    setPattern(pat);
}

void Microphone::display() const {
    cout << "Тип: " << getType()
         << ", модель: " << getModel()
         << ", потужність: " << getPower() << " Вт"
         << ", ціна: " << getPrice() << " грн"
         << ", бездротовий: " << (wireless ? "так" : "ні")
         << ", діаграма: " << pattern << "\n";
}

string Microphone::getType() const {
    return "Мікрофон";
}
