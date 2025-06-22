#include <iostream>
using namespace std;

// Stack implementation using an array
class stImp {
    int top=-1;
    int st[10];
    public:
    void push(int x) {
        if(top>=10) {
            cout << "Stack overflow" << endl;
            return; // or throw an exception
        }
        top=top+1;
        st[top]=x;
    }
    int top() {
        if(top==-1) {
            cout << "Stack is empty" << endl;
            return -1; // or throw an exception
        }
        return st[top];
    }
    int pop() {
        if(top==-1) {
            cout << "Stack underflow" << endl;
            return -1; // or throw an exception
        } 
        return top=top-1;
    }
    int size() {
        return top+1;
    }
};