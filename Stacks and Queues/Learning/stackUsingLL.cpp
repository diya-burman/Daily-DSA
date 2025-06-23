#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class llImp {
private:
    Node* top = nullptr;
    int size = 0;

public:
    void push(int x) {
        Node* temp = new Node(x);
        temp->next = top;
        top = temp;
        size++;
    }

    void pop() {
        if (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
            size--;
        }
    }

    int peek() {  // Renamed to peek() to avoid conflict with member `top`
        if (top != nullptr) {
            return top->data;
        }
        return -1; // Or throw exception
    }

    int getSize() {  // Renamed to avoid conflict with member `size`
        return size;
    }
};

