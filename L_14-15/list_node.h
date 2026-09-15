#ifndef LIST_NODE_H
#define LIST_NODE_H

#include "signaling.h"

class ListNode {
public:
    Signaling data;
    ListNode* prev;
    ListNode* next;

    ListNode();
    explicit ListNode(const Signaling& value);
    ~ListNode();
};

#endif
