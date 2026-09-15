#include "list_node.h"

ListNode::ListNode()
    : data(), prev(nullptr), next(nullptr) {}

ListNode::ListNode(const Signaling& value)
    : data(value), prev(nullptr), next(nullptr) {}

ListNode::~ListNode() {}
