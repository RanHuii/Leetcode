//
// Created by Harry Huang on 2020-10-24.
//

#include <vector>
#include <queue>
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
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        if(!root)
            return std::vector<std::vector<int>>();
        std::queue<TreeNode*> q;
        std::vector<int> levelVector;
        std::vector<std::vector<int>> result;
        TreeNode* temp;
        int size = -1;
        q.push(root);

        while(!q.empty())
        {
            size = q.size();
            levelVector.clear();
            for(int i = 0; i < size; ++i)
            {
                temp = q.front();
                q.pop();
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
                levelVector.push_back(temp->val);
            }
            result.push_back(levelVector);
        }
        return result;
    }
};