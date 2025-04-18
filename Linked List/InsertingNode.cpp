#include<iostream>
#include<vector>
// #include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Constructor with both data and next node
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor with only data (assuming next is initially null)
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// Function to print the linked list
void printLL(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

// Function to insert a new node at the head of the linked list
Node* insertHead(Node* head, int val) {
    Node* temp=new Node(val,head);
    return temp;
}

Node* insertAtEnd(Node* head, int val) {
    Node* node = new Node(val,nullptr);
    if(head==nullptr) {
        return node;
    }
    Node* temp=head;
    while(temp->next!=NULL) {
        temp=temp->next;
    }
    temp->next=node;
    node=nullptr;
    return head;
}

Node* insertAtKthPosition(Node* head, int el, int k) {
    if(head==NULL) {
        if(k==1) return new Node(el);
        else return head;
    }
    if(k==1) { // when k value is head
        return new Node(el,head);
    }
    int cnt=1;
    Node* temp=head;
    while(temp!=NULL) {
        if(cnt==(k-1)) {
            Node* x = new Node(el);
            x->next=temp->next;
            temp->next=x;
            break;
        }
        else {temp=temp->next;}
    cnt++;
    }
    return head;
}

Node* insertBeforeValue(Node* head, int el, int val) {
    if(head==NULL) {
        return NULL;
    }
    if(head->data==val) { 
        Node* temp=new Node(el,head);
        return temp;
    }
    int cnt=1;
    Node* temp=head;
    while(temp->next!=NULL) {
        if(temp->next->data==val) {
            Node* x = new Node(el);
            x->next=temp->next;
            temp->next=x;
            break;
        }
        else {temp=temp->next;}
    }
    return head;
}

int main() {
    // Sample array and value for insertion
    vector<int> arr = {2, 3, 1, 8};
    int val = 5;

    // Creating a linked list with initial elements from the array
    Node* head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);

    // Inserting a new node at the head of the linked list
    // head = insertHead(head, val);
    //head=insertAtEnd(head,val);
    //head=insertAtKthPosition(head,10,2);
    head=insertBeforeValue(head,10,8);

    // Printing the linked list
    printLL(head);

    return 0;
}