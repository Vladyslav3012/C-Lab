#include "signaling.h"
#include <cstring>
#include <iostream>
#include <limits>
#include <string>

using namespace std;

void Signaling::allocate(size_t count, bool wireless, const char* method) {
    if (count < 1) {
        count = 1;
    }
    sensorCount = count;
    hasWireless = wireless;
    sensors = new int[sensorCount];
    for (size_t i = 0; i < sensorCount; ++i) {
        sensors[i] = static_cast<int>(i + 1);
    }
    size_t len = strlen(method);
    alertMethod = new char[len + 1];
    strcpy(alertMethod, method);
}

void Signaling::freeResources() {
    delete[] sensors;
    delete[] alertMethod;
    sensors = nullptr;
    alertMethod = nullptr;
    sensorCount = 0;
    hasWireless = false;
}

Signaling::Signaling(size_t count, bool wireless, const char* method)
    : sensors(nullptr), sensorCount(0), hasWireless(false), alertMethod(nullptr) {
    allocate(count, wireless, method);
    cout << "[Constructor] Ресурс виділено, датчиків: " << sensorCount
         << ", адреса sensors: " << sensors << "\n";
}

Signaling::~Signaling() {
    if (sensors != nullptr || alertMethod != nullptr) {
        cout << "[Destructor] Звільнення ресурсу, адреса sensors: " << sensors << "\n";
    } else {
        cout << "[Destructor] Об'єкт порожній, видаляти нічого\n";
    }
    freeResources();
}

Signaling::Signaling(const Signaling& other)
    : sensors(nullptr), sensorCount(0), hasWireless(false), alertMethod(nullptr) {
    allocate(other.sensorCount, other.hasWireless, other.alertMethod);
    for (size_t i = 0; i < sensorCount; ++i) {
        sensors[i] = other.sensors[i];
    }
    cout << "[Copy Constructor] Глибоке копіювання, адреса sensors: " << sensors << "\n";
}

Signaling& Signaling::operator=(const Signaling& other) {
    if (this != &other) {
        freeResources();
        allocate(other.sensorCount, other.hasWireless, other.alertMethod);
        for (size_t i = 0; i < sensorCount; ++i) {
            sensors[i] = other.sensors[i];
        }
    }
    cout << "[Copy Assignment] Копіююче присвоювання\n";
    return *this;
}

Signaling::Signaling(Signaling&& other) noexcept
    : sensors(other.sensors),
      sensorCount(other.sensorCount),
      hasWireless(other.hasWireless),
      alertMethod(other.alertMethod) {
    other.sensors = nullptr;
    other.sensorCount = 0;
    other.hasWireless = false;
    other.alertMethod = nullptr;
    cout << "[Move Constructor] Ресурс передано, адреса sensors: " << sensors << "\n";
}

Signaling& Signaling::operator=(Signaling&& other) noexcept {
    if (this != &other) {
        freeResources();
        sensors = other.sensors;
        sensorCount = other.sensorCount;
        hasWireless = other.hasWireless;
        alertMethod = other.alertMethod;
        other.sensors = nullptr;
        other.sensorCount = 0;
        other.hasWireless = false;
        other.alertMethod = nullptr;
    }
    cout << "[Move Assignment] Присвоювання переміщенням\n";
    return *this;
}

Signaling Signaling::inputFromKeyboard() {
    size_t count;
    int wirelessFlag;
    string method;

    while (true) {
        cout << "Кількість датчиків (>= 1): ";
        if (cin >> count && count >= 1) {
            break;
        }
        cout << "Помилка: кількість датчиків має бути >= 1!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    while (true) {
        cout << "Бездротові сенсори (1 - так, 0 - ні): ";
        if (cin >> wirelessFlag && (wirelessFlag == 0 || wirelessFlag == 1)) {
            break;
        }
        cout << "Помилка: введіть 0 або 1!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while (true) {
        cout << "Спосіб оповіщення (можна кілька слів): ";
        getline(cin, method);
        if (!method.empty()) {
            break;
        }
        cout << "Помилка: спосіб оповіщення не може бути порожнім!\n";
    }

    return Signaling(count, wirelessFlag == 1, method.c_str());
}

size_t Signaling::getSensorCount() const { return sensorCount; }
bool Signaling::getHasWireless() const { return hasWireless; }
const char* Signaling::getAlertMethod() const { return alertMethod; }
const int* Signaling::getSensors() const { return sensors; }

void Signaling::display() const {
    cout << "датчиків: " << sensorCount
         << ", бездротові: " << (hasWireless ? "так" : "ні")
         << ", оповіщення: " << (alertMethod ? alertMethod : "(порожньо)")
         << ", sensors@: " << sensors << "\n";
}
