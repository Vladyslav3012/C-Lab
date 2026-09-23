#include <iostream>
#include "alarm.h"

using namespace std;

int main() {
    cout << "=== Лаб. №8, варіант 22: Сигналізація (vector) ===\n\n";

    AlarmSystem systems;

    cout << "1. Додавання (push_back):\n";
    systems.addAlarm(8, true, "сирена");
    systems.addAlarm(12, false, "SMS");
    systems.addAlarm(5, true, "додаток");
    systems.displayAll();

    cout << "\n1a. Введення одного об'єкта з клавіатури (метод inputAlarm):\n";
    systems.inputAlarm();
    systems.displayAll();

    cout << "\n2. Вставка на позицію 1:\n";
    systems.insertAlarm(1, 10, true, "сирена + SMS");
    systems.displayAll();

    cout << "\n3. Обмін елементів [0] і [2]:\n";
    systems.swapAlarms(0, 2);
    systems.displayAll();

    cout << "\n4. Видалення елемента [1]:\n";
    systems.removeAlarm(1);
    systems.displayAll();

    cout << "\n5. Зміна полів і валідація:\n";
    systems.setSensorCount(0, 20);
    systems.setAlertMethod(0, "");
    systems.addAlarm(0, true, "тест");
    systems.displayAll();

    cout << "\n6. Сигналізації з бездротовими сенсорами:\n";
    systems.displayByWireless(true);

    cout << "\n7. Очищення:\n";
    systems.clearAll();
    systems.displayAll();

    return 0;
}
