#include "signaling.h"

using namespace std;

Signaling::Signaling()
    : sensorCount(1), hasWireless(false), alertMethod("сирена") {}

Signaling::Signaling(int sensors, bool wireless, const string& method)
    : sensorCount(1), hasWireless(false), alertMethod("сирена") {
    setSensorCount(sensors);
    setHasWireless(wireless);
    setAlertMethod(method);
}

Signaling::~Signaling() {}

void Signaling::setSensorCount(int sensors) {
    if (sensors < 1) {
        sensors = 1;
    }
    sensorCount = sensors;
}

void Signaling::setHasWireless(bool wireless) {
    hasWireless = wireless;
}

void Signaling::setAlertMethod(const string& method) {
    if (method.empty()) {
        alertMethod = "сирена";
    } else {
        alertMethod = method;
    }
}

int Signaling::getSensorCount() const { return sensorCount; }
bool Signaling::getHasWireless() const { return hasWireless; }
string Signaling::getAlertMethod() const { return alertMethod; }

void Signaling::display() const {
    cout << "датчиків: " << sensorCount
         << ", бездротові: " << (hasWireless ? "так" : "ні")
         << ", оповіщення: " << alertMethod;
}

bool Signaling::equals(const Signaling& other) const {
    return sensorCount == other.sensorCount
        && hasWireless == other.hasWireless
        && alertMethod == other.alertMethod;
}

ostream& operator<<(ostream& out, const Signaling& s) {
    out << "датчиків: " << s.sensorCount
        << ", бездротові: " << (s.hasWireless ? "так" : "ні")
        << ", оповіщення: " << s.alertMethod;
    return out;
}
