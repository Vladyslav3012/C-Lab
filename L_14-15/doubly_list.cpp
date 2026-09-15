#include "doubly_list.h"
#include <iostream>

using namespace std;

DoublyList::DoublyList()
    : head(nullptr), tail(nullptr), count(0) {}

DoublyList::~DoublyList() {
    clear();
}

bool DoublyList::isEmpty() const {
    return head == nullptr;
}

int DoublyList::size() const {
    return count;
}

void DoublyList::pushFront(const Signaling& value) {
    ListNode* node = new ListNode(value);
    if (isEmpty()) {
        head = tail = node;
    } else {
        node->next = head;
        head->prev = node;
        head = node;
    }
    ++count;
    cout << "Додано на початок: " << value << "\n";
}

void DoublyList::pushBack(const Signaling& value) {
    ListNode* node = new ListNode(value);
    if (isEmpty()) {
        head = tail = node;
    } else {
        node->prev = tail;
        tail->next = node;
        tail = node;
    }
    ++count;
    cout << "Додано в кінець: " << value << "\n";
}

bool DoublyList::insertAfter(const Signaling& afterValue, const Signaling& value) {
    ListNode* current = head;
    while (current != nullptr) {
        if (current->data.equals(afterValue)) {
            ListNode* node = new ListNode(value);
            node->prev = current;
            node->next = current->next;
            if (current->next != nullptr) {
                current->next->prev = node;
            } else {
                tail = node;
            }
            current->next = node;
            ++count;
            cout << "Вставлено після [" << afterValue << "]: " << value << "\n";
            return true;
        }
        current = current->next;
    }
    cout << "Елемент для вставки після нього не знайдено.\n";
    return false;
}

bool DoublyList::popFront() {
    if (isEmpty()) {
        cout << "Список порожній — неможливо видалити з початку.\n";
        return false;
    }
    ListNode* temp = head;
    cout << "Видалено з початку: " << temp->data << "\n";
    if (head == tail) {
        head = tail = nullptr;
    } else {
        head = head->next;
        head->prev = nullptr;
    }
    delete temp;
    --count;
    return true;
}

bool DoublyList::popBack() {
    if (isEmpty()) {
        cout << "Список порожній — неможливо видалити з кінця.\n";
        return false;
    }
    ListNode* temp = tail;
    cout << "Видалено з кінця: " << temp->data << "\n";
    if (head == tail) {
        head = tail = nullptr;
    } else {
        tail = tail->prev;
        tail->next = nullptr;
    }
    delete temp;
    --count;
    return true;
}

bool DoublyList::removeByValue(const Signaling& value) {
    ListNode* current = head;
    while (current != nullptr) {
        if (current->data.equals(value)) {
            cout << "Видалено за значенням: " << current->data << "\n";
            if (current->prev != nullptr) {
                current->prev->next = current->next;
            } else {
                head = current->next;
            }
            if (current->next != nullptr) {
                current->next->prev = current->prev;
            } else {
                tail = current->prev;
            }
            delete current;
            --count;
            return true;
        }
        current = current->next;
    }
    cout << "Елемент для видалення не знайдено.\n";
    return false;
}

void DoublyList::displayForward() const {
    if (isEmpty()) {
        cout << "Список порожній.\n";
        return;
    }
    cout << "Прямий вивід (head -> tail):\n";
    ListNode* current = head;
    int i = 1;
    while (current != nullptr) {
        cout << "  " << i << ") " << current->data << "\n";
        current = current->next;
        ++i;
    }
}

void DoublyList::displayBackward() const {
    if (isEmpty()) {
        cout << "Список порожній.\n";
        return;
    }
    cout << "Зворотний вивід (tail -> head):\n";
    ListNode* current = tail;
    int i = count;
    while (current != nullptr) {
        cout << "  " << i << ") " << current->data << "\n";
        current = current->prev;
        --i;
    }
}

void DoublyList::clear() {
    ListNode* current = head;
    while (current != nullptr) {
        ListNode* next = current->next;
        delete current;
        current = next;
    }
    head = tail = nullptr;
    count = 0;
}
