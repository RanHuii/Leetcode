//
// Created by Harry Huang on 2020-10-29.
//

#include <string>
#include <queue>
#include <iostream>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    std::string serialize(TreeNode* root) {
        std::string result;
        if(!root)
            return result;
        std::queue<TreeNode*> q;
        TreeNode* temp;
        q.push(root);
        while(!q.empty())
        {
            temp = q.front();
            q.pop();
            if(temp)
                result += std::to_string(temp->val) + ",";
            else
                result += "#,";
            if(temp)
            {
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        return result.substr(0, result.length() - 1);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(std::string data) {
        if(data.empty())
            return nullptr;
        int pos = -1;
        return constructTree(data, pos);

    }
    TreeNode* constructTree(std::string &data, int& pos)
    {
        std::string temp;

        if(pos > data.length())
        {
            return nullptr;
        }
        pos = data.find(',');
        temp = data.substr(0, pos);
        data = data.substr(pos);
        auto* root = new TreeNode(std::stoi(temp));

        root->left = constructTree(data, pos);
        root->right = constructTree(data, pos);

        return root;
    }
};


