#include <algorithm>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{

public:
    int minDepth(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }

        bool isLeafLeft = false;
        bool isLeafRight = false;
        int leftCount = traverse(isLeafLeft, root->left);
        int rightCount = traverse(isLeafRight, root->right);
        if (isLeafLeft && isLeafRight)
            return 1 + min(leftCount, rightCount);
        if (isLeafLeft)
            return 1 + leftCount;
        if (isLeafRight)
            return 1 + rightCount;

        return 1;
    }
    int traverse(bool &isLeaf, TreeNode *node)
    {
        if (!node)
            return 0;
        else if (!node->left && !node->right)
        {
            isLeaf = true;
            return 1;
        }
        else if (!node->left)
            return 1 + traverse(isLeaf, node->right);
        else if (!node->right)
            return 1 + traverse(isLeaf, node->left);

        else
            return 1 + min(traverse(isLeaf, node->left), traverse(isLeaf, node->right));
    }
};