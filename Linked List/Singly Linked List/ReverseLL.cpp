#include <iostream>
#include <stack>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    public:
        ListNode* reverseList(ListNode* head) {
            // stack - reversed a linked list in terms of data - brute force-O(2n),
            // SC=O(n)
            // ListNode* temp = head;
            // stack<int> st;
            // while (temp != NULL) {
            //     st.push(temp->val);
            //     temp = temp->next;
            // }
            // temp = head;
            // while (temp != NULL) {
            //     temp->val = st.top();
            //     st.pop();
            //     temp = temp->next;
            // }
            // return head;
    
            // optimal - prev pointer generate iterative approach - O(n)
            // ListNode* prev = NULL;
            // ListNode* temp = head;
            // while (temp != NULL) {
            //     ListNode* front = temp->next;
            //     temp->next = prev;
            //     prev = temp;
            //     temp = front;
            // }
            // return prev;
    
            // recursive approach
            if (head == NULL ||
                head->next == NULL) { // empty list or 1 node in linked list
                return head;
            }
            ListNode* newHead = reverseList(head->next);
            ListNode* front = head->next;
            front->next = head;
            head->next = NULL;
            return newHead;
        }
    };