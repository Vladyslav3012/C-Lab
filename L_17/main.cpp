#include <iostream>
#include <memory>
#include "signaling.h"
#include "alarm_hub.h"
#include "sensor_device.h"
#include "bad_cycle.h"
#include "signaling_node.h"

using namespace std;

void demoUniquePtr() {
    cout << "=== 1. std::unique_ptr ===\n\n";

    cout << "Введення одного об'єкта з клавіатури (Signaling::inputData):\n";
    Signaling typed;
    typed.inputData();
    unique_ptr<Signaling> item1 = make_unique<Signaling>(typed);
    cout << "item1.get() = " << item1.get() << "\n";
    item1->display();

    cout << "\nКопіювання unique_ptr заборонене:\n";
    cout << "  // unique_ptr<Signaling> item2 = item1;  // помилка компіляції\n";
    cout << "  Причина: unique_ptr не можна копіювати — лише одне володіння.\n\n";

    unique_ptr<Signaling> item2 = move(item1);
    cout << "Після std::move(item1) -> item2:\n";
    cout << "  item1.get() = " << item1.get() << " (nullptr)\n";
    cout << "  item2.get() = " << item2.get() << "\n";
    if (item2) {
        item2->display();
    }

    cout << "\nВихід з блоку — item2 знищиться автоматично:\n";
    {
        unique_ptr<Signaling> scoped = make_unique<Signaling>(3, false, "SMS");
        cout << "  scoped всередині блоку: ";
        scoped->display();
    }
    cout << "  (scoped вже знищено)\n\n";
}

void demoSharedPtr() {
    cout << "=== 2. std::shared_ptr ===\n\n";

    shared_ptr<Signaling> sp1 = make_shared<Signaling>(12, true, "додаток");
    shared_ptr<Signaling> sp2 = sp1;
    shared_ptr<Signaling> sp3 = sp1;

    cout << "Після 3 shared_ptr: use_count = " << sp1.use_count() << "\n";

    {
        shared_ptr<Signaling> sp4 = sp1;
        cout << "Всередині блоку (+sp4): use_count = " << sp1.use_count() << "\n";
    }

    cout << "Після виходу з блоку: use_count = " << sp1.use_count() << "\n";
    cout << "Лічильник зменшився: sp4 знищено, об'єкт ще живий (є sp1..sp3).\n\n";
}

void demoWeakPtrCycle() {
    cout << "=== 3. std::weak_ptr (без циклу) ===\n\n";

    {
        shared_ptr<AlarmHub> hub = make_shared<AlarmHub>("Централь");
        shared_ptr<SensorDevice> sensor = make_shared<SensorDevice>("Зона-1");

        hub->sensor = sensor;
        sensor->hub = hub;

        cout << "hub.use_count() = " << hub.use_count()
             << " (очікуємо 1: лише локальний hub)\n";
        cout << "sensor.use_count() = " << sensor.use_count()
             << " (очікуємо 2: локальний + hub->sensor)\n";

        if (auto locked = sensor->hub.lock()) {
            cout << "sensor->hub.lock() OK: " << locked->name << "\n";
        }
    }
    cout << "Після блоку деструктори викликались — витоку немає.\n\n";

    cout << "=== 3b. Цикл shared_ptr + shared_ptr (витік) ===\n\n";
    {
        shared_ptr<BadAlarmHub> hub = make_shared<BadAlarmHub>("BadHub");
        shared_ptr<BadSensorDevice> sensor = make_shared<BadSensorDevice>("BadSensor");

        hub->sensor = sensor;
        sensor->hub = hub;

        cout << "hub.use_count() = " << hub.use_count()
             << " (2: локальний + sensor->hub)\n";
        cout << "sensor.use_count() = " << sensor.use_count()
             << " (2: локальний + hub->sensor)\n";
        cout << "Після блоку use_count лишиться 1+1 — деструктори НЕ викличуться.\n";
    }
    cout << "(Якщо вище не було Destructor — це витік через циклічні shared_ptr)\n\n";
}

void demoList() {
    cout << "=== 4. Двозв'язний список (shared next + weak prev) ===\n\n";

    auto n1 = make_shared<SignalingNode>(5, true, "сирена");
    auto n2 = make_shared<SignalingNode>(8, false, "SMS");
    auto n3 = make_shared<SignalingNode>(10, true, "email");

    n1->next = n2;
    n2->prev = n1;

    n2->next = n3;
    n3->prev = n2;

    cout << "Прямий прохід (next):\n";
    for (auto cur = n1; cur; cur = cur->next) {
        cout << "  ";
        cur->display();
    }

    cout << "Зворотний прохід від n3 (prev.lock()):\n";
    for (shared_ptr<SignalingNode> cur = n3; cur; ) {
        cout << "  ";
        cur->display();
        cur = cur->prev.lock();
    }

    cout << "\nuse_count: n1=" << n1.use_count()
         << ", n2=" << n2.use_count()
         << ", n3=" << n3.use_count() << "\n";
    cout << "Вихід з demoList — вузли знищаться без циклічного витоку.\n\n";
}

int main() {
    cout << "=== Лаб. №17: Розумні вказівники (Сигналізація) ===\n\n";

    demoUniquePtr();
    demoSharedPtr();
    demoWeakPtrCycle();
    demoList();

    cout << "=== Кінець програми ===\n";
    return 0;
}
