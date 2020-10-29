//
// Created by Harry Huang on 2020-10-28.
//
#include <limits>
#include <opencl-c.h>

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
    bool isValidBST(TreeNode* root) {
        return traversalHelper(root, nullptr, nullptr);
    }

    bool traversalHelper(TreeNode* root, int* min, int* max)
    {
        if(!root)
            return true;
        if(min && root->val <= *min) return false;
        if(max && root->val >= *max) return false;

        return traversalHelper(root->left, min, &root->val) && traversalHelper(root->right, &root->val, max);
    }
};