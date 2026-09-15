#include <iostream>
#include "signaling.h"
#include "doubly_list.h"

using namespace std;

int main() {
    cout << "=== Лаб. №14-15: Двозв'язний список (Сигналізація) ===\n\n";

    DoublyList list;

    cout << "1. Перевірка порожнього списку:\n";
    cout << "isEmpty() = " << (list.isEmpty() ? "так" : "ні") << "\n";
    cout << "size() = " << list.size() << "\n\n";

    cout << "2. Додавання елементів:\n";
    Signaling a(8, true, "сирена");
    Signaling b(12, false, "SMS");
    Signaling c(5, true, "додаток");
    Signaling d(20, true, "email");
    Signaling e(3, false, "дзвінок");

    list.pushBack(a);
    list.pushBack(b);
    list.pushFront(c);
    list.pushBack(d);
    cout << "\n";

    cout << "3. Вставка після елемента:\n";
    list.insertAfter(a, e);
    cout << "\n";

    cout << "4. Прямий вивід:\n";
    list.displayForward();
    cout << "Кількість елементів: " << list.size() << "\n\n";

    cout << "5. Зворотний вивід:\n";
    list.displayBackward();
    cout << "\n";

    cout << "6. Видалення з початку:\n";
    list.popFront();
    list.displayForward();
    cout << "\n";

    cout << "7. Видалення з кінця:\n";
    list.popBack();
    list.displayForward();
    cout << "\n";

    cout << "8. Видалення за значенням:\n";
    list.removeByValue(b);
    list.displayForward();
    cout << "\n";

    cout << "9. Спроба видалити неіснуючий елемент:\n";
    Signaling missing(99, false, "немає");
    list.removeByValue(missing);
    cout << "\n";

    cout << "10. Фінальний стан:\n";
    cout << "isEmpty() = " << (list.isEmpty() ? "так" : "ні") << "\n";
    cout << "size() = " << list.size() << "\n";
    list.displayForward();
    list.displayBackward();

    return 0;
}
