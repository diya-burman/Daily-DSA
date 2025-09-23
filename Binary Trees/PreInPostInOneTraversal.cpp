#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Following is Binary Tree Node structure:
class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

vector<vector<int>> getTreeTraversal(TreeNode *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
        return ans;

    stack<pair<TreeNode *, int>> st;
    st.push({root, 1});
    vector<int> pre, in, post;

    while (!st.empty())
    {
        auto it = st.top();
        st.pop();

        // Preorder
        if (it.second == 1)
        {
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);

            if (it.first->left != NULL)
            {
                st.push({it.first->left, 1});
            }
        }
        // Inorder
        else if (it.second == 2)
        {
            in.push_back(it.first->data);
            it.second++;
            st.push(it);

            if (it.first->right != NULL)
            {
                st.push({it.first->right, 1});
            }
        }
        // Postorder
        else
        {
            post.push_back(it.first->data);
        }
    }

    ans.push_back(in);
    ans.push_back(pre);
    ans.push_back(post);
    return ans;
}
