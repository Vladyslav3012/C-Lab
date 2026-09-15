#ifndef DATE_ARRAY_H
#define DATE_ARRAY_H

#include "calendar_date.h"

const int DATE_ARRAY_SIZE = 8;

class DateArray {
private:
    CalendarDate dates[DATE_ARRAY_SIZE];
    int count;

public:
    DateArray();
    ~DateArray();

    void add(const CalendarDate& date);
    int size() const;

    CalendarDate& operator[](int index);
    const CalendarDate& operator[](int index) const;

    void selectionSortByWeekday();
    void displayAll() const;
    void findNearestForEach(int targetWeekday) const;
};

#endif
