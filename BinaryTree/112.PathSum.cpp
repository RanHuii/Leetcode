/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root)
        {
            return false;
        }
        return traverse(0, root, sum);
    }
    bool traverse(int total, TreeNode* root, int &sum)
    {
        if(!root)
            return false;
        else
        {
            total += root->val;
        }
        if(!root->left && !root->right)
        {
            if(total == sum)
                return true;
            else
                return false;
        }
        else
        {
            return traverse(total, root->left, sum) || traverse(total, root->right, sum);
        }
    }
    
};