#include "date_array.h"
#include <iostream>

using namespace std;

DateArray::DateArray() {
    count = 0;
    cout << "Конструктор DateArray\n";
}

DateArray::~DateArray() {
    cout << "Деструктор DateArray\n";
}

void DateArray::add(const CalendarDate& date) {
    if (count >= DATE_ARRAY_SIZE) {
        cout << "Помилка: масив дат заповнений!\n";
        return;
    }
    dates[count] = date;
    count++;
}

int DateArray::size() const {
    return count;
}

CalendarDate& DateArray::operator[](int index) {
    if (index < 0 || index >= count) {
        cout << "Помилка: некоректний індекс!\n";
        return dates[0];
    }
    return dates[index];
}

const CalendarDate& DateArray::operator[](int index) const {
    if (index < 0 || index >= count) {
        cout << "Помилка: некоректний індекс!\n";
        return dates[0];
    }
    return dates[index];
}

void DateArray::selectionSortByWeekday() {
    // сортування вибором за зростанням дня тижня (через operator< / operator<=)
    for (int i = 0; i < count - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < count; j++) {
            if (dates[j] < dates[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            CalendarDate temp = dates[i];
            dates[i] = dates[minIndex];
            dates[minIndex] = temp;
        }
    }
}

void DateArray::displayAll() const {
    if (count == 0) {
        cout << "Масив порожній.\n";
        return;
    }
    for (int i = 0; i < count; i++) {
        cout << "[" << i << "] " << dates[i] << "\n";
    }
}

void DateArray::findNearestForEach(int targetWeekday) const {
    if (targetWeekday < 1 || targetWeekday > 7) {
        cout << "Помилка: день тижня має бути від 1 до 7!\n";
        return;
    }
    for (int i = 0; i < count; i++) {
        CalendarDate nearest = dates[i] + targetWeekday;
        cout << "[" << i << "] від " << dates[i]
             << " -> найближчий день " << targetWeekday
             << ": " << nearest << "\n";
    }
}
