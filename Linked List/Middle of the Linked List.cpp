#include <iostream>
#include <vector>
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
        ListNode* middleNode(ListNode* head) {
            // brute-force-O(n+n/2) SC-O(1) 
            // ListNode* temp = head;
            // int cnt = 0;
            // while (temp != NULL) {
            //     cnt++;
            //     temp = temp->next;
            // }
            // int middleNode = (cnt / 2) + 1;
            // temp = head;
            // while (temp != NULL) {
            //     middleNode = middleNode - 1;
            //     if (middleNode == 0) {
            //         break;
            //     } else {
            //         temp = temp->next;
            //     }
            // }
            // return temp;
    
            // optimal - tortoise and Hare O(n)
            ListNode* slow = head;
            ListNode* fast = head;
    
            while (fast != nullptr && fast->next != nullptr) {
                slow = slow->next;
                fast = fast->next->next;
            }
            return slow;
        }
};