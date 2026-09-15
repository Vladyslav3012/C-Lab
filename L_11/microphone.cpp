#include "microphone.h"
#include <iostream>

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

string Microphone::getType() const {
    return "Мікрофон";
}
