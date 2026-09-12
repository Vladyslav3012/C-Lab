#include <iostream>
#include "microphone.h"
#include "speaker.h"
#include "device_catalog.h"

using namespace std;

void showByRef(SoundDevice& device) {
    cout << "Через посилання на базовий клас: ";
    device.display();
}

int main() {
    cout << "=== Лаб. №9-10: Звуковий пристрій -> Мікрофон, Динамік ===\n\n";

    cout << "1. Створення об'єктів:\n";
    Microphone mic1("Shure SM58", 5, 4500, false, "кардіоїдна");
    Microphone mic2("Rode Wireless", 2, 12000, true, "омні");
    Speaker sp1("JBL Flip", 20, 3500, 8, 4);
    Speaker sp2("Yamaha HS8", 120, 18000, 20, 8);

    cout << "\n2. Віртуальний виклик через посилання:\n";
    showByRef(mic1);
    showByRef(sp1);

    cout << "\n3. Каталог (vector вказівників, поліморфізм):\n";
    DeviceCatalog catalog;
    catalog.add(&mic1);
    catalog.add(&mic2);
    catalog.add(&sp1);
    catalog.add(&sp2);

    cout << "Вхідні дані / усі пристрої:\n";
    catalog.displayAll();

    cout << "\n4. Зміна полів і валідація:\n";
    mic1.setPower(10);
    mic1.setPattern("");
    sp1.setImpedance(100);
    sp1.setDiameter(10);
    catalog.displayAll();

    cout << "\n5. Результат обчислення:\n";
    cout << "Кількість пристроїв: " << catalog.count() << endl;
    cout << "Загальна вартість: " << catalog.totalPrice() << " грн\n";

    cout << "\n=== Кінець програми ===\n";
    return 0;
}
