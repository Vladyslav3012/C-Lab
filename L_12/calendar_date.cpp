#include "calendar_date.h"
#include <limits>

using namespace std;

bool CalendarDate::isLeap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int CalendarDate::daysInMonth(int month, int year) {
    static const int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeap(year)) {
        return 29;
    }
    if (month < 1 || month > 12) {
        return 0;
    }
    return days[month];
}

bool CalendarDate::isValidDate(int day, int month, int year) {
    if (year < 1 || month < 1 || month > 12 || day < 1) {
        return false;
    }
    return day <= daysInMonth(month, year);
}

CalendarDate::CalendarDate() {
    data.day = 1;
    data.month = 1;
    data.year = 2026;
}

CalendarDate::CalendarDate(int day, int month, int year) {
    data.day = 1;
    data.month = 1;
    data.year = 2026;
    setDate(day, month, year);
}

CalendarDate::~CalendarDate() {
    // тихий деструктор, щоб не засмічувати вивід масиву
}

void CalendarDate::setDate(int day, int month, int year) {
    if (!isValidDate(day, month, year)) {
        cout << "Помилка: некоректна дата "
             << day << "." << month << "." << year << "!\n";
        return;
    }
    data.day = day;
    data.month = month;
    data.year = year;
}

void CalendarDate::setDay(int day) {
    setDate(day, data.month, data.year);
}

void CalendarDate::setMonth(int month) {
    setDate(data.day, month, data.year);
}

void CalendarDate::setYear(int year) {
    setDate(data.day, data.month, year);
}

void CalendarDate::inputData() {
    int day;
    int month;
    int year;

    while (true) {
        cout << "День (1..31): ";
        if (!(cin >> day) || day < 1 || day > 31) {
            cout << "Помилка: день має бути від 1 до 31!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cout << "Місяць (1..12): ";
        if (!(cin >> month) || month < 1 || month > 12) {
            cout << "Помилка: місяць має бути від 1 до 12!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cout << "Рік (>= 1): ";
        if (!(cin >> year) || year < 1) {
            cout << "Помилка: рік має бути >= 1!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (!isValidDate(day, month, year)) {
            cout << "Помилка: некоректна дата "
                 << day << "." << month << "." << year << "! Спробуйте ще раз.\n";
            continue;
        }

        data.day = day;
        data.month = month;
        data.year = year;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        break;
    }
}

int CalendarDate::getDay() const { return data.day; }
int CalendarDate::getMonth() const { return data.month; }
int CalendarDate::getYear() const { return data.year; }

int CalendarDate::weekday() const {
    // алгоритм Сакамото: 0 = Неділя, 1 = Понеділок, ... 6 = Субота
    int d = data.day;
    int m = data.month;
    int y = data.year;
    static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    if (m < 3) {
        y -= 1;
    }
    int w = (y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7;
    // перетворюємо у 1 = Пн ... 7 = Нд
    return (w == 0) ? 7 : w;
}

string CalendarDate::weekdayName() const {
    static const char* names[] = {
        "", "Понеділок", "Вівторок", "Середа", "Четвер",
        "П'ятниця", "Субота", "Неділя"
    };
    int w = weekday();
    return names[w];
}

void CalendarDate::addDays(int n) {
    if (n >= 0) {
        while (n > 0) {
            data.day++;
            if (data.day > daysInMonth(data.month, data.year)) {
                data.day = 1;
                data.month++;
                if (data.month > 12) {
                    data.month = 1;
                    data.year++;
                }
            }
            n--;
        }
        return;
    }

    while (n < 0) {
        data.day--;
        if (data.day < 1) {
            data.month--;
            if (data.month < 1) {
                data.month = 12;
                data.year--;
            }
            data.day = daysInMonth(data.month, data.year);
        }
        n++;
    }
}

void CalendarDate::display() const {
    cout << *this;
}

bool operator<=(const CalendarDate& a, const CalendarDate& b) {
    return a.weekday() <= b.weekday();
}

bool operator<(const CalendarDate& a, const CalendarDate& b) {
    return a.weekday() < b.weekday();
}

CalendarDate operator+(const CalendarDate& date, int targetWeekday) {
    if (targetWeekday < 1 || targetWeekday > 7) {
        cout << "Помилка: день тижня має бути від 1 до 7!\n";
        return date;
    }

    CalendarDate result = date;
    int current = date.weekday();
    int forward = (targetWeekday - current + 7) % 7;
    int backward = (current - targetWeekday + 7) % 7;

    // найближча дата: мінімальна кількість днів уперед або назад
    if (forward <= backward) {
        result.addDays(forward);
    } else {
        result.addDays(-backward);
    }
    return result;
}

CalendarDate operator+(const CalendarDate& date, const CalendarDate& daySpec) {
    return date + daySpec.weekday();
}

ostream& operator<<(ostream& out, const CalendarDate& d) {
    if (d.data.day < 10) out << "0";
    out << d.data.day << ".";
    if (d.data.month < 10) out << "0";
    out << d.data.month << "." << d.data.year
        << " (" << d.weekdayName() << ", день " << d.weekday() << ")";
    return out;
}
