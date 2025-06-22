#include <iostream>
using namespace std;

// Queue implementation using an array
class MyQueue {
    int size = 10;
    int arr[10]; // array for queue
    int start = -1;
    int end = -1;
    int currSize = 0;

public:
    int push(int x) {
        if (currSize == size) {
            cout << "Queue overflow" << endl;
            return -1;
        }
        if (currSize == 0) {
            start = 0;
            end = 0;
        } else {
            end = (end + 1) % size;
        }
        arr[end] = x;
        currSize++;
        return 0;
    }

    int pop() {
        if (currSize == 0) {
            cout << "Queue underflow" << endl;
            return -1;
        }
        int poppedValue = arr[start];
        if (currSize == 1) {
            start = -1;
            end = -1;
        } else {
            start = (start + 1) % size;
        }
        currSize--;
        return poppedValue;
    }

    int top() {
        if (currSize == 0) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[start];
    }

    int length() {
        return currSize;
    }
};

int main() {
    MyQueue q;
    q.push(10);
    q.push(20);
    q.push(30);
    cout << "Front: " << q.top() << endl; // should print 10
    cout << "Popped: " << q.pop() << endl; // should print 10
    cout << "Front: " << q.top() << endl; // should print 20
    return 0;
}
