//
// Created by Harry Huang on 2020-10-18.
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
    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        if(nums.empty())
            return new TreeNode();
        std::queue<TreeNode*> nodeQ;
        int size = nums.size();
        int mid = size / 2;
        auto *head = new TreeNode(nums[mid]);
        nodeQ.push(head);

        TreeNode *current;
        int traverseLeft = mid - 1;
        int traverseRight = mid + 1;
        while(!nodeQ.empty())
        {
            current = nodeQ.front();
            nodeQ.pop();

            if(traverseLeft >= 0)
            {
                current->left = new TreeNode(nums[traverseLeft]);
                nodeQ.push(current->left);
                traverseLeft--;
            }

            if(traverseRight < size)
            {
                current->right = new TreeNode(nums[traverseRight]);
                nodeQ.push(current->right);
                traverseRight++;
            }
        }
        return head;
    }
};