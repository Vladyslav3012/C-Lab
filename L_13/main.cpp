#include <iostream>
#include "alarm.h"
#include "home_alarm.h"
#include "office_alarm.h"
#include "alarm_catalog.h"
#include "alarm_exception.h"

using namespace std;

void showByRef(Alarm& alarm) {
    cout << "Віртуальний виклик: ";
    alarm.display();
}

int main() {
    cout << "=== Лаб. №13: Файли та винятки (Сигналізація) ===\n\n";

    const string filename = "alarms.txt";
    AlarmCatalog catalog;

    try {
        cout << "1. Створення об'єктів (дочірні класи):\n";
        HomeAlarm home(8, true, "сирена", "вітальня");
        OfficeAlarm office(12, false, "SMS", 3);
        HomeAlarm garage(5, true, "додаток", "гараж");

        cout << "\n2. Віртуальний вивід через базове посилання:\n";
        showByRef(home);
        showByRef(office);

        cout << "\n3. Перевантаження операторів:\n";
        cout << "home: " << home << "\n";
        cout << "office: " << office << "\n";
        cout << "home == office ? " << (home == office ? "так" : "ні") << "\n";
        cout << "home < office ? " << (home < office ? "так" : "ні") << "\n";
        Alarm combined = home + office;
        cout << "home + office = " << combined << "\n";

        cout << "\n4. Каталог (vector структур):\n";
        catalog.add(home, "зона=" + home.getZone());
        catalog.add(office, "поверх=" + to_string(office.getFloor()));
        catalog.add(garage, "зона=" + garage.getZone());
        catalog.displayAll();

        cout << "\n5. Запис у файл (fstream):\n";
        catalog.saveToFile(filename);
        cout << "Збережено у " << filename << "\n";

        cout << "\n6. Читання з файлу (fstream):\n";
        AlarmCatalog loaded;
        loaded.loadFromFile(filename);
        cout << "Завантажено записів: " << loaded.size() << "\n";
        loaded.displayAll();

        cout << "\n7. Результат обчислення:\n";
        cout << "Кількість записів: " << loaded.size() << "\n";
        cout << "Загальна кількість датчиків: " << loaded.totalSensors() << "\n";
        cout << "Перший запис через []: тип=" << loaded[0].type
             << ", датчиків=" << loaded[0].sensorCount << "\n";

        cout << "\n8. Перевірка винятків валідації:\n";
        try {
            home.setSensorCount(0);
        } catch (const ValidationException& ex) {
            cout << "Спіймано ValidationException: " << ex.what() << "\n";
        }

        try {
            office.setAlertMethod("");
        } catch (const ValidationException& ex) {
            cout << "Спіймано ValidationException: " << ex.what() << "\n";
        }

        try {
            loaded[100];
        } catch (const ValidationException& ex) {
            cout << "Спіймано ValidationException: " << ex.what() << "\n";
        }

        cout << "\n9. Перевірка винятку файлу:\n";
        try {
            AlarmCatalog missing;
            missing.loadFromFile("no_such_file.txt");
        } catch (const FileException& ex) {
            cout << "Спіймано FileException: " << ex.what() << "\n";
        }

    } catch (const AlarmException& ex) {
        cerr << "AlarmException: " << ex.what() << "\n";
    } catch (...) {
        cerr << "Невідомий виняток!\n";
    }

    cout << "\n=== Кінець програми ===\n";
    return 0;
}
