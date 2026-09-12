#include <iostream>
#include "alarm.h"

using namespace std;

int main() {
    cout << "=== Лаб. №7, варіант 22: Сигналізація ===\n\n";

    AlarmSystem systems;

    cout << "Вхідні дані:\n";
    systems.addAlarm(8, true, "сирена");
    systems.addAlarm(12, false, "SMS");
    systems.addAlarm(5, true, "додаток");
    systems.addAlarm(20, true, "сирена + SMS");
    systems.addAlarm(3, false, "дзвінок");

    cout << "\nУсі записи:\n";
    systems.displayAll();

    cout << "\nЗміна запису [1]:\n";
    systems.setSensorCount(1, 15);
    systems.setAlertMethod(1, "електронна пошта");
    systems.displayAll();

    cout << "\nПеревірка валідації:\n";
    systems.addAlarm(0, true, "тест");
    systems.setAlertMethod(0, "");

    cout << "\nСигналізації з бездротовими сенсорами:\n";
    systems.displayByWireless(true);

    cout << "\nСигналізації з кількістю датчиків >= 10:\n";
    systems.displayByMinSensors(10);

    cout << "\nСигналізації з кількістю датчиків >= 100:\n";
    systems.displayByMinSensors(100);

    return 0;
}
