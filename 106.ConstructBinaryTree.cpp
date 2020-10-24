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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.empty() || postorder.empty())
            return nullptr;
        
        for(int i = 0; i < inorder.size(); ++i)
        {
            map[inorder[i]] = i;
        }
        
        return buildTreeHelper(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
    
    TreeNode* buildTreeHelper(vector<int>& inorder, int left1, int right1, vector<int>& postorder, int left2, int right2)
    {
        if(left1 > right1 || left2 > right2)
            return nullptr;
        
        int rootVal = postorder[right2];
        int mid = map[rootVal];
        
        
        TreeNode* root = new TreeNode(rootVal);
        root->left = buildTreeHelper(inorder, left1, mid - 1, postorder, left2, left2 + mid - left1 - 1);
        root->right = buildTreeHelper(inorder, mid + 1, right1, postorder, left2 + mid -left1, right2 -1);
        
        return root;
    }
private:
    unordered_map<int, int> map;
};