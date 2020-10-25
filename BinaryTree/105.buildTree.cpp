//
// Created by Harry Huang on 2020-10-22.
//

#include <vector>
#include <unordered_map>
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
    TreeNode* buildTree(std::vector<int>& preorder,std::vector<int>& inorder) {
        if(preorder.empty() || inorder.empty())
            return nullptr;
        for(int i = 0; i < inorder.size(); ++i)
        {
            map[inorder[i]] = i;
        }
        return buildTreeHelper(preorder, 0, preorder.size() -1, inorder, 0, inorder.size());
    }
private:
    std::unordered_map<int, int> map;
    TreeNode* buildTreeHelper(std::vector<int>& preorder, int left1, int right1, std::vector<int>& inorder, int left2, int right2)
    {
        if(left1 > right1 || left2 > right2)
            return nullptr;

        int rootValue = preorder[left1];
        int mid = map[rootValue];

        auto* root = new TreeNode(rootValue);
        root->left = buildTreeHelper(preorder, left1 + 1, left1 + (mid - left2), inorder, left2, mid - 1);
        root->right = buildTreeHelper(preorder, left1 + (mid - left2) + 1, right1, inorder, mid + 1, right2);

        return root;
    }


    // frame for build a tree
    TreeNode* foo(std::vector<int> list)
    {
        if(list.empty())
            return nullptr;

        return  buildTreeHelper(list, 0, list.size() - 1)
    }
    TreeNode* buildHelper(std::vector<int> list, int left, int right)
    {
        if(left > right)
            return nullptr;

        int someValueFromlist = 0;
        int mid = left + (right - left) / 2;
        auto* root = new TreeNode(someValueFromlist);

        // left subtree
        root->left = buildHelper(list, 0, mid - 1);
        //right subtree
        root->right = buildHelper(list,mid + 1, right);

    }
};