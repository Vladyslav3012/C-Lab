#include <iostream>
#include <utility>
#include "signaling.h"

using namespace std;

void takeByValue(Signaling obj) {
    cout << "  всередині takeByValue: ";
    obj.display();
}

Signaling returnByValue(Signaling obj) {
    cout << "  всередині returnByValue: ";
    obj.display();
    cout << "  повернення obj з функції...\n";
    return obj;
}

int main() {
    cout << "=== Лаб. №16: Копіювання та переміщення (Сигналізація) ===\n\n";

    cout << "1. Конструктор з параметром:\n";
    Signaling a(8, true, "сирена");
    a.display();
    cout << "\n";

    cout << "1a. Введення одного об'єкта з клавіатури (Signaling::inputFromKeyboard):\n";
    Signaling fromKeyboard = Signaling::inputFromKeyboard();
    cout << "  введено: ";
    fromKeyboard.display();
    cout << "\n";

    cout << "2. Конструктор копіювання (Signaling b = a):\n";
    Signaling b = a;
    cout << "  a: ";
    a.display();
    cout << "  b: ";
    b.display();
    cout << "\n";

    cout << "3. Оператор присвоювання копіюванням (c = a):\n";
    Signaling c(3, false, "SMS");
    c = a;
    cout << "  c: ";
    c.display();
    cout << "\n";

    cout << "4. Передача у функцію за значенням (копіювання):\n";
    takeByValue(a);
    cout << "  після виклику a: ";
    a.display();
    cout << "\n";

    cout << "5. Конструктор переміщення (Signaling d = std::move(b)):\n";
    Signaling d = std::move(b);
    cout << "  d: ";
    d.display();
    cout << "  b (після move): ";
    b.display();
    cout << "\n";

    cout << "6. Оператор присвоювання переміщенням (c = std::move(d)):\n";
    c = std::move(d);
    cout << "  c: ";
    c.display();
    cout << "  d (після move): ";
    d.display();
    cout << "\n";

    cout << "7. Передача у функцію через std::move:\n";
    takeByValue(std::move(a));
    cout << "  a (після move у функцію): ";
    a.display();
    cout << "\n";

    cout << "8. Повернення з функції (move з параметра):\n";
    Signaling e = returnByValue(Signaling(4, true, "email"));
    cout << "  e: ";
    e.display();
    cout << "\n";

    cout << "9. Завершення main (деструктори):\n";
    return 0;
}
