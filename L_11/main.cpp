#include <iostream>
#include "microphone.h"
#include "speaker.h"
#include "device_friend.h"

using namespace std;

int main() {
    cout << "=== Лаб. №11: Дружні класи (Звуковий пристрій) ===\n\n";

    DeviceFriend helper;

    cout << "1. Створення об'єктів:\n";
    Microphone mic1;
    Microphone mic2;
    Speaker sp1;
    Speaker sp2;

    cout << "\n2. Введення даних через дружній клас:\n";
    helper.inputMicrophone(mic1, "Shure SM58", 5, 4500, false, "кардіоїдна");
    helper.inputMicrophone(mic2, "Rode Wireless", 2, 12000, true, "омні");
    helper.inputSpeaker(sp1, "JBL Flip", 20, 3500, 8, 4);
    helper.inputSpeaker(sp2, "Yamaha HS8", 120, 18000, 20, 8);

    cout << "\n3. Вивід через дружній клас (доступ до private):\n";
    helper.printMicrophone(mic1);
    helper.printMicrophone(mic2);
    helper.printSpeaker(sp1);
    helper.printSpeaker(sp2);

    cout << "\n4. Вивід базової частини через friend:\n";
    helper.printBase(mic1);
    helper.printBase(sp1);

    cout << "\n5. Каталог (vector структур catalog_item_t):\n";
    helper.addToCatalog(mic1);
    helper.addToCatalog(mic2);
    helper.addToCatalog(sp1);
    helper.addToCatalog(sp2);
    helper.displayCatalog();

    cout << "\n6. Валідація некоректних даних:\n";
    helper.inputMicrophone(mic1, "Shure SM58", 5, 4500, false, "");
    helper.inputSpeaker(sp1, "JBL Flip", 20, 3500, 8, 100);
    cout << "Після спроби некоректної зміни:\n";
    helper.printMicrophone(mic1);
    helper.printSpeaker(sp1);

    cout << "\n7. Результат обчислення:\n";
    cout << "Кількість записів у каталозі: " << helper.count() << endl;
    cout << "Загальна вартість: " << helper.totalPrice() << " грн\n";
    cout << "Максимальна ціна: " << helper.maxPrice() << " грн\n";

    cout << "\n=== Кінець програми ===\n";
    return 0;
}
