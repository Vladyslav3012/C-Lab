#ifndef SIGNALING_NODE_H
#define SIGNALING_NODE_H

#include "signaling.h"
#include <memory>

class SignalingNode {
public:
    Signaling data;
    std::shared_ptr<SignalingNode> next;
    std::weak_ptr<SignalingNode> prev;

    SignalingNode(int sensors, bool wireless, const std::string& method);
    ~SignalingNode();

    void display() const;
};

#endif
