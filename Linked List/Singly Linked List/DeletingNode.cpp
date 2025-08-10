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

Node* deleteHead(Node* head) {
    if(head==NULL) {
        return NULL;
    }
    Node* temp=head;
    head=head->next;
    delete temp;
    return head;
}

Node* deleteAtEnd(Node* head) {
    if(head==NULL || head->next==NULL) {
        return NULL;
    }
    Node* temp=head;
    while(temp->next->next!=NULL) {
        temp=temp->next;
    }
    free(temp->next);
    temp->next=NULL;
    return head;
}

Node* deleteAtKPosition(Node* head, int k) {
    if(head==NULL) {
        return head;
    }
    if(k==1) {
        Node* temp=head;
        head=head->next;
        free(temp);
        return head;
    }
//     int cnt=0;
//     Node* temp=head;     
//     while(temp->next!=NULL) {
//         cnt++;
//         if(cnt==k-1) {
//             temp->next=temp->next->next;
//             free(temp->next);
//             break;
//         } else {
//             temp=temp->next;
//         }
//         return head;
//     }
// }
    int cnt=0;
    Node* temp=head;
    Node* prev=NULL;
    while(temp!=NULL) {
        cnt++;
        if(cnt==k) {
            prev->next=prev->next->next;
            free(temp);
            break;
        } else {
            prev=temp;
            temp=temp->next;
        }
    }
    return head;
}

Node* deleteEl(Node* head, int el) {
    if(head==NULL) {
        return head;
    }
    if(head->data==el) {
        Node* temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    Node* temp=head;
    Node* prev=NULL;
    while(temp!=NULL) {
        if(temp->data==el) {
            prev->next=prev->next->next;
            free(temp);
            break;
        } else {
            prev=temp;
            temp=temp->next;
        }
    }
    return head;
}


int main() {
    // Sample array and value for insertion
    vector<int> arr = {1, 8, 7, 3};
    int val = 5;

    // Creating a linked list with initial elements from the array
    Node* head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);

    // Deleting a new node in a Linked List
    //head = deleteHead(head);
    ///head=deleteAtEnd(head);
    //head=deleteAtKPosition(head,2);
    head=deleteEl(head,1);
    
    // Printing the linked list
    printLL(head);

    return 0;
}