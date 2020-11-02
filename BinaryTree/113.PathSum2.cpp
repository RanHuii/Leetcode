//
// Created by Harry Huang on 2020-11-01.
//

#include <vector>
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
using namespace std;

class Solution {

public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(!root)
            return vector<vector<int>>();

        vector<int> path;
        vector<vector<int>> result;
        traverse(root, path, result, sum, 0);

        return result;
    }
    void traverse(TreeNode* root, vector<int> path, vector<vector<int>>& result, int sum, int curr)
    {
        if(!root)
            return;
        curr += root->val;
        path.push_back(root->val);
        if(!root->left && !root->right)
        {
            if(curr == sum)
            {
                result.push_back(path);
            }
        }
        else
        {
            traverse(root->left, path, result, sum, curr);
            traverse(root->right, path, result, sum, curr);
        }
        return;
    }
};