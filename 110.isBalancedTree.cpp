//
// Created by Harry Huang on 2020-10-13.
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

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == nullptr)
        {
            return true;
        }
        return(std::abs(traverse(root->left) - traverse(root->right)) <= 1)
              && isBalanced(root->left) && isBalanced(root->right);

    }
    int traverse(TreeNode* root)
    {
        if(!root)
        {
            return 0;
        }
        else
        {
            return 1 + std::max(traverse(root->left), traverse(root->right));
        }
    }
};