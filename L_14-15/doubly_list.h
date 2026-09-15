#ifndef DOUBLY_LIST_H
#define DOUBLY_LIST_H

#include "list_node.h"

class DoublyList {
private:
    ListNode* head;
    ListNode* tail;
    int count;

public:
    DoublyList();
    ~DoublyList();

    DoublyList(const DoublyList&) = delete;
    DoublyList& operator=(const DoublyList&) = delete;

    bool isEmpty() const;
    int size() const;

    void pushFront(const Signaling& value);
    void pushBack(const Signaling& value);
    bool insertAfter(const Signaling& afterValue, const Signaling& value);

    bool popFront();
    bool popBack();
    bool removeByValue(const Signaling& value);

    void displayForward() const;
    void displayBackward() const;

    void clear();
};

#endif
