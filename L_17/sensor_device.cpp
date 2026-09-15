#include "sensor_device.h"
#include "alarm_hub.h"

using namespace std;

SensorDevice::SensorDevice(const string& n) : name(n) {
    cout << "[SensorDevice] Constructor: " << name << "\n";
}

SensorDevice::~SensorDevice() {
    cout << "[SensorDevice] Destructor: " << name << "\n";
}
