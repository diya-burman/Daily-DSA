#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to search a node in BST.
class Solution {

  public:
    int floor(Node* root, int x) {
       int floor=-1;
    while(root) {
        if(root->data==x) {
            floor=root->data;
            return floor;
        } 
        if(root->data<x) {
            floor=root->data;
            root=root->right;
        } else {
            root=root->left;
        }
    }
    return floor;
    }
};