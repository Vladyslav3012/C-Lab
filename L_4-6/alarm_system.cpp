#include <iostream>
#include <string>

using namespace std;

class AlarmSystem {
private:
    int sensorCount;
    bool hasWireless;
    string alertMethod;

public:
    AlarmSystem() {
        sensorCount = 1;
        hasWireless = false;
        alertMethod = "сирена";
        cout << "Викликано конструктор за замовчуванням\n";
    }

    AlarmSystem(int sensors, bool wireless, string method) {
        sensorCount = sensors;
        hasWireless = wireless;
        alertMethod = method;
        cout << "Викликано конструктор з параметрами\n";
    }

    ~AlarmSystem() {
        cout << "Викликано деструктор\n";
    }

    void setSensorCount(int count) {
        if (count < 1 || count > 1000) {
            cout << "Помилка: кількість датчиків має бути від 1 до 1000!\n";
            return;
        }
        sensorCount = count;
    }

    void setHasWireless(bool wireless) {
        hasWireless = wireless;
    }

    void setAlertMethod(string method) {
        if (method.empty()) {
            cout << "Помилка: спосіб оповіщення не може бути порожнім!\n";
            return;
        }
        alertMethod = method;
    }

    void setSensorCountByRef(int& count) {
        if (count < 1 || count > 1000) {
            cout << "Помилка: кількість датчиків має бути від 1 до 1000!\n";
            return;
        }
        sensorCount = count;
    }

    void inputData(int sensors, bool wireless, string method) {
        setSensorCount(sensors);
        setHasWireless(wireless);
        setAlertMethod(method);
    }

    void displayInfo() {
        cout << "Кількість датчиків: " << sensorCount << endl;
        cout << "Бездротові сенсори: " << (hasWireless ? "так" : "ні") << endl;
        cout << "Спосіб оповіщення: " << alertMethod << endl;
    }
};

void changeSensors(AlarmSystem& system, int newCount) {
    cout << "Зміна через посилання на об'єкт...\n";
    system.setSensorCount(newCount);
}

int main() {
    cout << "=== Лаб. №4-6, варіант 22: Сигналізація ===\n\n";

    cout << "1. Об'єкт homeAlarm (за замовчуванням):\n";
    AlarmSystem homeAlarm;
    homeAlarm.displayInfo();
    cout << endl;

    cout << "2. Об'єкт officeAlarm (з параметрами):\n";
    AlarmSystem officeAlarm(12, true, "SMS");
    officeAlarm.displayInfo();
    cout << endl;

    cout << "3. Зміна homeAlarm методами:\n";
    homeAlarm.setSensorCount(8);
    homeAlarm.setHasWireless(true);
    homeAlarm.setAlertMethod("додаток");
    homeAlarm.displayInfo();
    cout << endl;

    cout << "4. Зміна за посиланням:\n";
    int n = 15;
    homeAlarm.setSensorCountByRef(n);
    homeAlarm.displayInfo();
    cout << endl;

    cout << "5. Зміна officeAlarm через функцію з посиланням:\n";
    changeSensors(officeAlarm, 20);
    officeAlarm.displayInfo();
    cout << endl;

    cout << "6. Спроба задати некоректні значення:\n";
    homeAlarm.setSensorCount(0);
    homeAlarm.setAlertMethod("");
    homeAlarm.displayInfo();
    cout << endl;

    cout << "7. Введення даних для garageAlarm (метод inputData):\n";
    AlarmSystem garageAlarm;
    cout << "Вхідні дані: 6 датчиків, бездротові = ні, оповіщення = сирена\n";
    garageAlarm.inputData(6, false, "сирена");
    cout << "Результат:\n";
    garageAlarm.displayInfo();

    return 0;
}
