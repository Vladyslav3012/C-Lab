#include "signaling_node.h"
#include <iostream>

using namespace std;

SignalingNode::SignalingNode(int sensors, bool wireless, const string& method)
    : data(sensors, wireless, method) {
    cout << "[SignalingNode] Constructor\n";
}

SignalingNode::~SignalingNode() {
    cout << "[SignalingNode] Destructor\n";
}

void SignalingNode::display() const {
    data.display();
}
