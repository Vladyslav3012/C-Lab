#include "signaling.h"

using namespace std;

Signaling::Signaling()
    : sensorCount(1), hasWireless(false), alertMethod("сирена") {
    cout << "[Signaling] Constructor (default)\n";
}

Signaling::Signaling(int sensors, bool wireless, const string& method)
    : sensorCount(sensors < 1 ? 1 : sensors),
      hasWireless(wireless),
      alertMethod(method.empty() ? "сирена" : method) {
    cout << "[Signaling] Constructor: датчиків=" << sensorCount
         << ", бездротові=" << (hasWireless ? "так" : "ні")
         << ", оповіщення=" << alertMethod << "\n";
}

Signaling::~Signaling() {
    cout << "[Signaling] Destructor: оповіщення=" << alertMethod << "\n";
}

int Signaling::getSensorCount() const { return sensorCount; }
bool Signaling::getHasWireless() const { return hasWireless; }
string Signaling::getAlertMethod() const { return alertMethod; }

void Signaling::display() const {
    cout << "датчиків: " << sensorCount
         << ", бездротові: " << (hasWireless ? "так" : "ні")
         << ", оповіщення: " << alertMethod << "\n";
}
