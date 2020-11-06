//
// Created by Harry Huang on 2020-10-29.
//

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution1 {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        if(!root)
            return 0;
        if(root->left)
        {
            if(isLeaf(root->left))
                sum += root->left->val;
            else
                sum += sumOfLeftLeaves(root->left);
        }
        if(root->right)
        {
            sum += sumOfLeftLeaves(root->right);
        }

        return sum;
    }
    static bool isLeaf(TreeNode* root)
    {
        return !root->left && !root->right;
    }
};

class Solution2 {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return traverseHelper(root, false);
    }

    int traverseHelper(TreeNode* root, bool isLeft)
    {
        if(!root)
            return 0;
        if(!root->left && !root->right && isLeft)
            return root->val;

        return traverseHelper(root->left, true) + traverseHelper(root->right, false);
    }
};