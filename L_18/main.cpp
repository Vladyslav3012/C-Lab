#include <iostream>
#include <string>
#include "signaling.h"
#include "max_utils.h"
#include "repository.h"
#include "pair_box.h"

using namespace std;

int main() {
    cout << "=== Лаб. №18: Шаблони (Сигналізація) ===\n\n";

    cout << "1. Шаблон функції max_value:\n";
    cout << "  max int: " << max_value(10, 25) << "\n";
    cout << "  max double: " << max_value(3.14, 2.71) << "\n";
    cout << "  max string: "
         << max_value(string("сирена"), string("додаток")) << "\n";

    Signaling a(8, true, "сирена");
    Signaling b(12, false, "SMS");
    cout << "  max Signaling (за кількістю датчиків): "
         << max_value(a, b) << "\n";

    cout << "  max const char* (повна спеціалізація функції): "
         << max_value<const char*>("email", "дзвінок") << "\n\n";

    cout << "2. Шаблон функції print_value + спеціалізація bool:\n";
    cout << "  int: ";
    print_value(42);
    cout << "  bool: ";
    print_value(true);
    cout << "\n";

    cout << "3. Шаблон класу Repository (загальний):\n";
    Repository<int> sensors(8);
    Repository<double> level(3.5);
    Repository<Signaling> alarm(Signaling(5, true, "додаток"));
    sensors.print();
    level.print();
    alarm.print();
    cout << "\n";

    cout << "4. Часткова спеціалізація Repository<T*>:\n";
    int count = 20;
    Repository<int*> ptrRepo(&count);
    ptrRepo.print();
    cout << "\n";

    cout << "5. Повна спеціалізація Repository<bool>:\n";
    Repository<bool> wireless(true);
    Repository<bool> noWireless(false);
    wireless.print();
    noWireless.print();
    cout << "\n";

    cout << "6. Шаблон класу PairBox (загальний):\n";
    PairBox<int, double> p1(12, 3.14);
    p1.print_pair();
    PairBox<string, bool> p2("C++ templates", true);
    p2.print_pair();
    PairBox<int, Signaling> p3(8, Signaling(8, true, "сирена"));
    p3.print_pair();
    cout << "\n";

    cout << "7. Часткова спеціалізація PairBox<T, T>:\n";
    PairBox<int, int> sameInts(5, 12);
    sameInts.print_pair();
    PairBox<Signaling, Signaling> sameAlarms(
        Signaling(4, false, "SMS"),
        Signaling(9, true, "email"));
    sameAlarms.print_pair();
    cout << "\n";

    cout << "8. Повна спеціалізація PairBox<bool, string>:\n";
    PairBox<bool, string> fields(true, "сирена");
    fields.print_pair();

    cout << "\n=== Кінець програми ===\n";
    return 0;
}
