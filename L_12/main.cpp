#include <iostream>
#include "calendar_date.h"
#include "date_array.h"

using namespace std;

int main() {
    cout << "=== Лаб. №12: Перевантаження операторів (календарні дати) ===\n\n";
    cout << "День тижня: 1=Пн, 2=Вт, 3=Ср, 4=Чт, 5=Пт, 6=Сб, 7=Нд\n\n";

    cout << "1. Створення дат і перевірка дня тижня:\n";
    CalendarDate d1(12, 9, 2026); // Субота
    CalendarDate d2(14, 9, 2026); // Понеділок
    CalendarDate d3(16, 9, 2026); // Середа
    CalendarDate d4(18, 9, 2026); // П'ятниця
    CalendarDate d5(20, 9, 2026); // Неділя
    CalendarDate d6(15, 9, 2026); // Вівторок

    cout << "d1 = " << d1 << "\n";
    cout << "d2 = " << d2 << "\n";
    cout << "d3 = " << d3 << "\n";
    cout << "d4 = " << d4 << "\n";
    cout << "d5 = " << d5 << "\n";
    cout << "d6 = " << d6 << "\n";

    cout << "\n2. Оператор <= (порівняння за днем тижня):\n";
    cout << "d2 <= d4 ? " << (d2 <= d4 ? "так" : "ні")
         << " (Пн=" << d2.weekday() << ", Пт=" << d4.weekday() << ")\n";
    cout << "d4 <= d2 ? " << (d4 <= d2 ? "так" : "ні") << "\n";
    cout << "d1 <= d5 ? " << (d1 <= d5 ? "так" : "ні")
         << " (Сб=" << d1.weekday() << ", Нд=" << d5.weekday() << ")\n";

    cout << "\n3. Оператор + (найближча дата із заданим днем тижня):\n";
    CalendarDate toFriday = d1 + 5; // від суботи найближча п'ятниця
    CalendarDate toMonday = d3 + d2; // від середи до дня тижня d2 (Пн)
    cout << d1 << " + 5(Пт) = " << toFriday << "\n";
    cout << d3 << " + d2(Пн) = " << toMonday << "\n";
    cout << d4 << " + 5(Пт) = " << (d4 + 5) << " (вже п'ятниця)\n";

    cout << "\n4. Масив дат (до сортування):\n";
    DateArray arr;
    arr.add(d1);
    arr.add(d2);
    arr.add(d3);
    arr.add(d4);
    arr.add(d5);
    arr.add(d6);
    arr.displayAll();

    cout << "\n5. Сортування вибором за зростанням дня тижня:\n";
    arr.selectionSortByWeekday();
    arr.displayAll();

    cout << "\n6. Для кожної дати — найближча п'ятниця (день 5):\n";
    arr.findNearestForEach(5);

    cout << "\n7. Валідація некоректної дати:\n";
    CalendarDate bad;
    bad.setDate(31, 2, 2026);

    cout << "\n8. Доступ через operator[]:\n";
    cout << "arr[0] = " << arr[0] << "\n";
    arr[0].setDate(1, 9, 2026);
    cout << "після зміни arr[0] = " << arr[0] << "\n";

    cout << "\n=== Кінець програми ===\n";
    return 0;
}
