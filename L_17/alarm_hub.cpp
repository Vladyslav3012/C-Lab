#include "alarm_hub.h"
#include "sensor_device.h"

using namespace std;

AlarmHub::AlarmHub(const string& n) : name(n) {
    cout << "[AlarmHub] Constructor: " << name << "\n";
}

AlarmHub::~AlarmHub() {
    cout << "[AlarmHub] Destructor: " << name << "\n";
}
