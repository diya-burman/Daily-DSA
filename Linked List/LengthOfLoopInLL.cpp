#include<iostream>
#include<unordered_map>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// brute force
// Function to calculate length of loop if present
// int lengthOfLoop(Node* head) {
//     int timer = 1;
//     unordered_map<Node*, int> mp;
//     Node* temp = head;
//     while (temp != NULL) {
//         if (mp.find(temp) != mp.end()) {
//             int val = mp[temp];
//             return timer - val;
//         } else {
//             mp[temp] = timer;
//             temp = temp->next;
//             timer++;
//         }
//     }
//     return 0;
// }

// optimal approach
int lengthOfLoop(Node* head) {
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL) {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) {
            int cnt=1;
            fast=fast->next;
            while(fast!=slow) {
                cnt++;
                fast=fast->next;
            }
            return cnt;
        }
    }
    return 0;
}

int main() {
    Node* head = new Node(1);
    Node* temp = head;

    Node* loopStart = nullptr;

    for (int i = 2; i <= 9; i++) {
        temp->next = new Node(i);
        temp = temp->next;

        // Save pointer to node with value 3
        if (i == 3) {
            loopStart = temp;
        }
    }

    // Create the loop: point last node to node with value 3
    temp->next = loopStart;

    int loopLength = lengthOfLoop(head);

    if (loopLength > 0)
        cout << "Length of loop: " << loopLength << endl;
    else
        cout << "No loop detected." << endl;

    return 0;
}
