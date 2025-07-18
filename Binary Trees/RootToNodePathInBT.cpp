#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};


class Solution {
  public:
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> res;
        vector<int> curPath;
        dfs(root,curPath,res);
        return res;
    }
  private:
    void dfs(Node* node, vector<int>& path, vector<vector<int>>& res) {
        if(!node) return;
        path.push_back(node->data);
        if(!node->left && !node->right) {
            res.push_back(path);
        } else {
            dfs(node->left,path,res);
            dfs(node->right,path,res);
        }
        path.pop_back();
    }
};