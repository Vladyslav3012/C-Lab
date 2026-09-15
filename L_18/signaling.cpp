#include "signaling.h"

using namespace std;

Signaling::Signaling()
    : sensorCount(1), hasWireless(false), alertMethod("сирена") {}

Signaling::Signaling(int sensors, bool wireless, const string& method)
    : sensorCount(sensors < 1 ? 1 : sensors),
      hasWireless(wireless),
      alertMethod(method.empty() ? "сирена" : method) {}

Signaling::~Signaling() {}

int Signaling::getSensorCount() const { return sensorCount; }
bool Signaling::getHasWireless() const { return hasWireless; }
string Signaling::getAlertMethod() const { return alertMethod; }

void Signaling::display() const {
    cout << "датчиків: " << sensorCount
         << ", бездротові: " << (hasWireless ? "так" : "ні")
         << ", оповіщення: " << alertMethod;
}

bool Signaling::operator>(const Signaling& other) const {
    return sensorCount > other.sensorCount;
}

ostream& operator<<(ostream& out, const Signaling& s) {
    out << "датчиків: " << s.sensorCount
        << ", бездротові: " << (s.hasWireless ? "так" : "ні")
        << ", оповіщення: " << s.alertMethod;
    return out;
}
