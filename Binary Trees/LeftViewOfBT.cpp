#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};


class Solution
{
public:
    void recursion(Node *root, int level, vector<int> &res)
    {
        if (root == NULL)
            return;
        if (level == res.size())
            res.push_back(root->data);
        recursion(root->left, level + 1, res);
        recursion(root->right, level + 1, res);
    }

    vector<int> leftView(Node *root)
    {
        vector<int> res;
        recursion(root, 0, res);
        return res;
    }
};