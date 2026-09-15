#ifndef ALARM_CATALOG_H
#define ALARM_CATALOG_H

#include "alarm.h"
#include <string>
#include <vector>

// запис у векторі структур
struct catalog_rec_t {
    std::string type;
    int sensorCount;
    bool hasWireless;
    std::string alertMethod;
    std::string extra;
};

class AlarmCatalog {
private:
    std::vector<catalog_rec_t> records;

public:
    AlarmCatalog();
    ~AlarmCatalog();

    void add(const Alarm& alarm, const std::string& extra = "");
    void clear();
    int size() const;
    void displayAll() const;
    int totalSensors() const;

    catalog_rec_t& operator[](int index);
    const catalog_rec_t& operator[](int index) const;

    // двонаправлений файловий ввід/вивід (fstream)
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};

#endif
