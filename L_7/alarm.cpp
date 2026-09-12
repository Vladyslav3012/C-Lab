#include "alarm.h"
#include <iostream>

using namespace std;

AlarmSystem::AlarmSystem() {
    count = 0;
    for (int i = 0; i < SIZE; i++) {
        alarms[i].sensorCount = 0;
        alarms[i].hasWireless = false;
        alarms[i].alertMethod = "";
    }
    cout << "Викликано конструктор\n";
}

AlarmSystem::~AlarmSystem() {
    cout << "Викликано деструктор\n";
}

void AlarmSystem::addAlarm(int sensors, bool wireless, string method) {
    if (count >= SIZE) {
        cout << "Помилка: масив заповнений (макс. " << SIZE << ")!\n";
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

    alarms[count].sensorCount = sensors;
    alarms[count].hasWireless = wireless;
    alarms[count].alertMethod = method;
    count++;
}

void AlarmSystem::setSensorCount(int index, int sensors) {
    if (index < 0 || index >= count) {
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
    if (index < 0 || index >= count) {
        cout << "Помилка: некоректний індекс!\n";
        return;
    }
    alarms.at(index).hasWireless = wireless;
}

void AlarmSystem::setAlertMethod(int index, string method) {
    if (index < 0 || index >= count) {
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
    if (count == 0) {
        cout << "Немає даних для виведення.\n";
        return;
    }
    for (int i = 0; i < count; i++) {
        cout << "[" << i << "] датчиків: " << alarms[i].sensorCount
             << ", бездротові: " << (alarms[i].hasWireless ? "так" : "ні")
             << ", оповіщення: " << alarms[i].alertMethod << endl;
    }
}

void AlarmSystem::displayByWireless(bool wireless) const {
    bool found = false;
    for (int i = 0; i < count; i++) {
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

void AlarmSystem::displayByMinSensors(int minSensors) const {
    bool found = false;
    for (int i = 0; i < count; i++) {
        if (alarms[i].sensorCount >= minSensors) {
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
