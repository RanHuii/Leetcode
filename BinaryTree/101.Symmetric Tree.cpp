//
// Created by Harry Huang on 2020-10-11.
//

#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution{
public:
    bool isSymmetric(TreeNode* root){
        if(root == nullptr)
        {
            return true;
        }
        return traverse(root->left, root->right);
    }
    bool traverse(TreeNode* left, TreeNode* right)
    {
        if(!left && !right) return true;
        if(!left || !right) return false;
        if(left->val != right->val) return false;
        return traverse(left->left, right->right) && traverse(left->right, right->left);
    }


};