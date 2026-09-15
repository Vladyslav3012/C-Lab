#include "alarm_catalog.h"
#include "alarm_exception.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

AlarmCatalog::AlarmCatalog() {
    cout << "Конструктор AlarmCatalog\n";
}

AlarmCatalog::~AlarmCatalog() {
    cout << "Деструктор AlarmCatalog\n";
}

void AlarmCatalog::add(const Alarm& alarm, const string& extra) {
    catalog_rec_t rec;
    rec.type = alarm.getType();
    rec.sensorCount = alarm.getSensorCount();
    rec.hasWireless = alarm.getHasWireless();
    rec.alertMethod = alarm.getAlertMethod();
    rec.extra = extra;
    records.push_back(rec);
}

void AlarmCatalog::clear() {
    records.clear();
}

int AlarmCatalog::size() const {
    return (int)records.size();
}

void AlarmCatalog::displayAll() const {
    if (records.empty()) {
        cout << "Каталог порожній.\n";
        return;
    }
    for (size_t i = 0; i < records.size(); i++) {
        cout << "[" << i << "] тип: " << records[i].type
             << ", датчиків: " << records[i].sensorCount
             << ", бездротові: " << (records[i].hasWireless ? "так" : "ні")
             << ", оповіщення: " << records[i].alertMethod;
        if (!records[i].extra.empty()) {
            cout << ", " << records[i].extra;
        }
        cout << "\n";
    }
}

int AlarmCatalog::totalSensors() const {
    int sum = 0;
    for (size_t i = 0; i < records.size(); i++) {
        sum += records[i].sensorCount;
    }
    return sum;
}

catalog_rec_t& AlarmCatalog::operator[](int index) {
    if (index < 0 || index >= (int)records.size()) {
        throw ValidationException("некоректний індекс каталогу");
    }
    return records[index];
}

const catalog_rec_t& AlarmCatalog::operator[](int index) const {
    if (index < 0 || index >= (int)records.size()) {
        throw ValidationException("некоректний індекс каталогу");
    }
    return records[index];
}

void AlarmCatalog::saveToFile(const string& filename) const {
    fstream file(filename, ios::out | ios::trunc);
    if (!file) {
        throw FileException("не вдалося відкрити файл для запису: " + filename);
    }

    for (size_t i = 0; i < records.size(); i++) {
        file << records[i].type << ';'
             << records[i].sensorCount << ';'
             << (records[i].hasWireless ? 1 : 0) << ';'
             << records[i].alertMethod << ';'
             << records[i].extra << '\n';
    }

    file.close();
}

void AlarmCatalog::loadFromFile(const string& filename) {
    fstream file(filename, ios::in);
    if (!file) {
        throw FileException("не вдалося відкрити файл для читання: " + filename);
    }

    records.clear();
    string line;
    while (getline(file, line)) {
        if (line.empty()) {
            continue;
        }

        catalog_rec_t rec;
        stringstream ss(line);
        string sensorsStr, wirelessStr;

        if (!getline(ss, rec.type, ';') ||
            !getline(ss, sensorsStr, ';') ||
            !getline(ss, wirelessStr, ';') ||
            !getline(ss, rec.alertMethod, ';')) {
            file.close();
            throw FileException("пошкоджений формат рядка у файлі");
        }
        getline(ss, rec.extra); // може бути порожнім

        try {
            rec.sensorCount = stoi(sensorsStr);
            rec.hasWireless = (stoi(wirelessStr) != 0);
        } catch (...) {
            file.close();
            throw FileException("помилка розбору числових полів у файлі");
        }

        if (rec.sensorCount < 1 || rec.sensorCount > 1000) {
            file.close();
            throw ValidationException("у файлі некоректна кількість датчиків");
        }
        if (rec.alertMethod.empty()) {
            file.close();
            throw ValidationException("у файлі порожній спосіб оповіщення");
        }

        records.push_back(rec);
    }

    file.close();
}
