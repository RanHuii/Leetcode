//
// Created by Harry Huang on 2020-10-24.
//

#include <vector>
#include <queue>
#include <stack>
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
        std::stack<TreeNode*> s1;
        std::stack<TreeNode*> s2;

        std::vector<int> levelVector;
        std::vector<std::vector<int>> result;
        TreeNode* temp;
        int size = -1;
        s1.push(root);
        bool choose = true;
        while(!s1.empty() || !s2.empty())
        {
            levelVector.clear();

            if(choose) {
                size = s1.size();
                for(int i = 0; i < size; ++i)
                {
                    temp = s1.top();
                    s1.pop();
                    if (temp->left)
                        s2.push(temp->left);
                    if (temp->right)
                        s2.push(temp->right);


                    levelVector.push_back(temp->val);
                }
            }
            else {
                size = s2.size();
                for(int i = 0; i < size; ++i)
                {
                    temp = s2.top();
                    s2.pop();
                    if (temp->right)
                        s1.push(temp->right);
                    if (temp->left)
                        s1.push(temp->left);
                    levelVector.push_back(temp->val);
                }
            }

            choose = !choose;
            result.push_back(levelVector);
        }

        return result;
    }
};