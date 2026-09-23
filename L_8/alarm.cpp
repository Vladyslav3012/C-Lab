#include "alarm.h"
#include <iostream>
#include <limits>

using namespace std;

AlarmSystem::AlarmSystem() {
    cout << "Викликано конструктор\n";
}

AlarmSystem::~AlarmSystem() {
    cout << "Викликано деструктор\n";
}

void AlarmSystem::addAlarm(int sensors, bool wireless, string method) {
    if (sensors < 1 || sensors > 1000) {
        cout << "Помилка: кількість датчиків має бути від 1 до 1000!\n";
        return;
    }
    if (method.empty()) {
        cout << "Помилка: спосіб оповіщення не може бути порожнім!\n";
        return;
    }

    alarm_s_t item;
    item.sensorCount = sensors;
    item.hasWireless = wireless;
    item.alertMethod = method;
    alarms.push_back(item);
}

void AlarmSystem::inputAlarm() {
    int sensors;
    int wirelessFlag;
    string method;

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

    addAlarm(sensors, wirelessFlag == 1, method);
}

void AlarmSystem::insertAlarm(int index, int sensors, bool wireless, string method) {
    if (index < 0 || index > (int)alarms.size()) {
        cout << "Помилка: некоректний індекс для вставки!\n";
        return;
    }
    if (sensors < 1 || sensors > 1000) {
        cout << "Помилка: кількість датчиків має бути від 1 до 1000!\n";
        return;
    }
    if (method.empty()) {
        cout << "Помилка: спосіб оповіщення не може бути порожнім!\n";
        return;
    }

    alarm_s_t item;
    item.sensorCount = sensors;
    item.hasWireless = wireless;
    item.alertMethod = method;
    alarms.insert(alarms.begin() + index, item);
}

void AlarmSystem::removeAlarm(int index) {
    if (index < 0 || index >= (int)alarms.size()) {
        cout << "Помилка: некоректний індекс для видалення!\n";
        return;
    }
    alarms.erase(alarms.begin() + index);
}

void AlarmSystem::swapAlarms(int i, int j) {
    if (i < 0 || j < 0 || i >= (int)alarms.size() || j >= (int)alarms.size()) {
        cout << "Помилка: некоректні індекси для обміну!\n";
        return;
    }
    swap(alarms[i], alarms[j]);
}

void AlarmSystem::clearAll() {
    alarms.clear();
    cout << "Усі записи очищено.\n";
}

void AlarmSystem::setSensorCount(int index, int sensors) {
    if (index < 0 || index >= (int)alarms.size()) {
        cout << "Помилка: некоректний індекс!\n";
        return;
    }
    if (sensors < 1 || sensors > 1000) {
        cout << "Помилка: кількість датчиків має бути від 1 до 1000!\n";
        return;
    }
    alarms.at(index).sensorCount = sensors;
}

void AlarmSystem::setHasWireless(int index, bool wireless) {
    if (index < 0 || index >= (int)alarms.size()) {
        cout << "Помилка: некоректний індекс!\n";
        return;
    }
    alarms.at(index).hasWireless = wireless;
}

void AlarmSystem::setAlertMethod(int index, string method) {
    if (index < 0 || index >= (int)alarms.size()) {
        cout << "Помилка: некоректний індекс!\n";
        return;
    }
    if (method.empty()) {
        cout << "Помилка: спосіб оповіщення не може бути порожнім!\n";
        return;
    }
    alarms.at(index).alertMethod = method;
}

void AlarmSystem::displayAll() const {
    if (alarms.empty()) {
        cout << "Немає даних для виведення.\n";
        return;
    }
    for (size_t i = 0; i < alarms.size(); i++) {
        cout << "[" << i << "] датчиків: " << alarms[i].sensorCount
             << ", бездротові: " << (alarms[i].hasWireless ? "так" : "ні")
             << ", оповіщення: " << alarms[i].alertMethod << endl;
    }
}

void AlarmSystem::displayByWireless(bool wireless) const {
    bool found = false;
    for (size_t i = 0; i < alarms.size(); i++) {
        if (alarms[i].hasWireless == wireless) {
            cout << "[" << i << "] датчиків: " << alarms[i].sensorCount
                 << ", бездротові: " << (alarms[i].hasWireless ? "так" : "ні")
                 << ", оповіщення: " << alarms[i].alertMethod << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Сигналізацій з таким критерієм не знайдено.\n";
    }
}
