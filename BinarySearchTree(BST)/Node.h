#ifndef NODE_H
#define NODE_H

class Node {
public:
    int data;
    Node *left, *right;

    Node(int v) {
        data = v;
        left = right = nullptr;
    }
};

#endif
