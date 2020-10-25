//
// Created by Harry Huang on 2020-10-10.
//

#ifndef TESTPROGRAM_BINARYTREE_H
#define TESTPROGRAM_BINARYTREE_H


#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class BinaryTree {
public:
    int maxDepth(TreeNode* root)
    {
        if(!root)
        {
            return 0;
        }
        else
        {
            return std::max(helper(1, root->left), helper(1, root->right));
        }
    }
    int helper(int depth, TreeNode* node)
    {
        if(node != nullptr)
        {
            depth++;
            return std::max(helper(depth, node->left), helper(depth, node->right));
        }
        else
        {
            return depth;
        }
    }

};


#endif //TESTPROGRAM_BINARYTREE_H
