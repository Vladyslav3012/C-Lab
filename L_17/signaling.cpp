#include "signaling.h"
#include <limits>

using namespace std;

Signaling::Signaling()
    : sensorCount(1), hasWireless(false), alertMethod("сирена") {
    cout << "[Signaling] Constructor (default)\n";
}

Signaling::Signaling(int sensors, bool wireless, const string& method)
    : sensorCount(sensors < 1 ? 1 : sensors),
      hasWireless(wireless),
      alertMethod(method.empty() ? "сирена" : method) {
    cout << "[Signaling] Constructor: датчиків=" << sensorCount
         << ", бездротові=" << (hasWireless ? "так" : "ні")
         << ", оповіщення=" << alertMethod << "\n";
}

Signaling::~Signaling() {
    cout << "[Signaling] Destructor: оповіщення=" << alertMethod << "\n";
}

void Signaling::setSensorCount(int sensors) {
    if (sensors < 1) {
        cout << "Помилка: кількість датчиків має бути >= 1!\n";
        return;
    }
    sensorCount = sensors;
}

void Signaling::setHasWireless(bool wireless) {
    hasWireless = wireless;
}

void Signaling::setAlertMethod(const string& method) {
    if (method.empty()) {
        cout << "Помилка: спосіб оповіщення не може бути порожнім!\n";
        return;
    }
    alertMethod = method;
}

void Signaling::inputData() {
    int sensors;
    int wirelessFlag;
    string method;

    while (true) {
        cout << "Кількість датчиків (>= 1): ";
        if (cin >> sensors && sensors >= 1) {
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

    setSensorCount(sensors);
    setHasWireless(wirelessFlag == 1);
    setAlertMethod(method);
}

int Signaling::getSensorCount() const { return sensorCount; }
bool Signaling::getHasWireless() const { return hasWireless; }
string Signaling::getAlertMethod() const { return alertMethod; }

void Signaling::display() const {
    cout << "датчиків: " << sensorCount
         << ", бездротові: " << (hasWireless ? "так" : "ні")
         << ", оповіщення: " << alertMethod << "\n";
}
