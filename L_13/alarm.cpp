#include "alarm.h"
#include "alarm_exception.h"

using namespace std;

Alarm::Alarm() {
    data.sensorCount = 1;
    data.hasWireless = false;
    data.alertMethod = "сирена";
}

Alarm::Alarm(int sensors, bool wireless, const string& method) {
    data.sensorCount = 1;
    data.hasWireless = false;
    data.alertMethod = "сирена";
    setSensorCount(sensors);
    setHasWireless(wireless);
    setAlertMethod(method);
}

Alarm::~Alarm() {}

void Alarm::setSensorCount(int sensors) {
    if (sensors < 1 || sensors > 1000) {
        throw ValidationException("кількість датчиків має бути від 1 до 1000");
    }
    data.sensorCount = sensors;
}

void Alarm::setHasWireless(bool wireless) {
    data.hasWireless = wireless;
}

void Alarm::setAlertMethod(const string& method) {
    if (method.empty()) {
        throw ValidationException("спосіб оповіщення не може бути порожнім");
    }
    data.alertMethod = method;
}

int Alarm::getSensorCount() const { return data.sensorCount; }
bool Alarm::getHasWireless() const { return data.hasWireless; }
string Alarm::getAlertMethod() const { return data.alertMethod; }

string Alarm::getType() const {
    return "Сигналізація";
}

void Alarm::display() const {
    cout << "Тип: " << getType()
         << ", датчиків: " << data.sensorCount
         << ", бездротові: " << (data.hasWireless ? "так" : "ні")
         << ", оповіщення: " << data.alertMethod << "\n";
}

bool operator==(const Alarm& a, const Alarm& b) {
    return a.data.sensorCount == b.data.sensorCount
        && a.data.hasWireless == b.data.hasWireless
        && a.data.alertMethod == b.data.alertMethod;
}

bool operator<(const Alarm& a, const Alarm& b) {
    return a.data.sensorCount < b.data.sensorCount;
}

Alarm operator+(const Alarm& a, const Alarm& b) {
    int sensors = a.data.sensorCount + b.data.sensorCount;
    if (sensors > 1000) {
        sensors = 1000;
    }
    bool wireless = a.data.hasWireless || b.data.hasWireless;
    string method = a.data.alertMethod + " + " + b.data.alertMethod;
    return Alarm(sensors, wireless, method);
}

ostream& operator<<(ostream& out, const Alarm& alarm) {
    out << alarm.getType()
        << " | датчиків: " << alarm.data.sensorCount
        << " | бездротові: " << (alarm.data.hasWireless ? "так" : "ні")
        << " | оповіщення: " << alarm.data.alertMethod;
    return out;
}
