#include "bad_cycle.h"

using namespace std;

BadSensorDevice::BadSensorDevice(const string& n) : name(n) {
    cout << "[BadSensorDevice] Constructor: " << name << "\n";
}

BadSensorDevice::~BadSensorDevice() {
    cout << "[BadSensorDevice] Destructor: " << name << "\n";
}

BadAlarmHub::BadAlarmHub(const string& n) : name(n) {
    cout << "[BadAlarmHub] Constructor: " << name << "\n";
}

BadAlarmHub::~BadAlarmHub() {
    cout << "[BadAlarmHub] Destructor: " << name << "\n";
}
