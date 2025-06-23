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

class queue {
private:
    Node* start;
    Node* end=nullptr;
    int size=0;

public:
   void push(int x) {
    Node* temp=new Node(x); 
    if(start==nullptr) {
        start = temp;
        end = temp;
    } else {
        end->next = temp;
    }
    size++;
   }

   void pop() {
    if(start==nullptr) {
        cout << "Queue underflow" << endl;
        return;
    }
    Node* temp=start;
    start=start->next;
    delete temp;
    size--;
   }

   void top() {
    if(start==nullptr) {
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "Top element: " << start->data << endl;
   }

   int size() {
    return size;
   }
};