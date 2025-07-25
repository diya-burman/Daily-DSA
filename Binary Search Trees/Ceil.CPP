#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

int findCeil(Node *root, int input)
{
    int ceil = -1;
    while (root)
    {
        if (root->data == input)
        {
            ceil = root->data;
            return ceil;
        }
        if (root->data < input)
        {
            root = root->right;
        }
        else
        {
            ceil = root->data;
            root = root->left;
        }
    }
    return ceil;
}