//
// Created by Harry Huang on 2020-10-17.
//

#include <vector>
#include <queue>
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
    std::vector<std::vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root)
            return std::vector<std::vector<int>>();

        std::vector<std::vector<int>> result;
        std::vector<int> level;
        TreeNode* current;
        std::queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            level.clear();

            for(int i = 0; i < n; ++i)
            {
                current = q.front();
                q.pop();
                level.push_back(current->val);
                if(current->left)
                    q.push(current->left);
                if(current->right)
                    q.push(current->right);
            }
            result.push_back(level);
        }
        return std::vector<std::vector<int>>(result.rbegin(), result.rend());
    }
};