#include "home_alarm.h"
#include "alarm_exception.h"
#include <iostream>
#include <limits>

using namespace std;

HomeAlarm::HomeAlarm()
    : Alarm(), zone("вітальня") {}

HomeAlarm::HomeAlarm(int sensors, bool wireless, const string& method, const string& zone)
    : Alarm(sensors, wireless, method), zone("вітальня") {
    setZone(zone);
}

HomeAlarm::~HomeAlarm() {}

void HomeAlarm::setZone(const string& z) {
    if (z.empty()) {
        throw ValidationException("зона будинку не може бути порожньою");
    }
    zone = z;
}

string HomeAlarm::getZone() const {
    return zone;
}

void HomeAlarm::inputData() {
    int sensors;
    int wirelessFlag;
    string method;
    string z;

    while (true) {
        cout << "Кількість датчиків (1..1000): ";
        if (cin >> sensors && sensors >= 1 && sensors <= 1000) {
            break;
        }
        cout << "Помилка: кількість датчиків має бути від 1 до 1000!\n";
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

    while (true) {
        cout << "Зона будинку (можна кілька слів): ";
        getline(cin, z);
        if (!z.empty()) {
            break;
        }
        cout << "Помилка: зона будинку не може бути порожньою!\n";
    }

    setSensorCount(sensors);
    setHasWireless(wirelessFlag == 1);
    setAlertMethod(method);
    setZone(z);
}

string HomeAlarm::getType() const {
    return "Домашня сигналізація";
}

void HomeAlarm::display() const {
    cout << "Тип: " << getType()
         << ", датчиків: " << getSensorCount()
         << ", бездротові: " << (getHasWireless() ? "так" : "ні")
         << ", оповіщення: " << getAlertMethod()
         << ", зона: " << zone << "\n";
}
