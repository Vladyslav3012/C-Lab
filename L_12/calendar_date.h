#ifndef CALENDAR_DATE_H
#define CALENDAR_DATE_H

#include <iostream>
#include <string>

struct date_s_t {
    int day;
    int month;
    int year;
};

class CalendarDate {
private:
    date_s_t data;

    static bool isLeap(int year);
    static int daysInMonth(int month, int year);
    static bool isValidDate(int day, int month, int year);

public:
    CalendarDate();
    CalendarDate(int day, int month, int year);
    ~CalendarDate();

    void setDate(int day, int month, int year);
    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);

    void inputData();

    int getDay() const;
    int getMonth() const;
    int getYear() const;

    // 1 = Понеділок ... 7 = Неділя
    int weekday() const;
    std::string weekdayName() const;

    void addDays(int n);
    void display() const;

    // порівняння за днем тижня
    friend bool operator<=(const CalendarDate& a, const CalendarDate& b);
    friend bool operator<(const CalendarDate& a, const CalendarDate& b);

    // найближча дата від left, день тижня якої = weekday() правого операнда
    friend CalendarDate operator+(const CalendarDate& date, const CalendarDate& daySpec);
    // найближча дата від date з заданим днем тижня (1..7)
    friend CalendarDate operator+(const CalendarDate& date, int targetWeekday);

    friend std::ostream& operator<<(std::ostream& out, const CalendarDate& d);
};

#endif
