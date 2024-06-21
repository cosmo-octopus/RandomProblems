#include <iostream>
#include <vector>

/**
 * Definition for a binary tree node.
 **/
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
    void inorder(TreeNode* root, std::vector<int>& vec) {
        if (!root)
            return ;
        
        if (root->left)
            inorder(root->left, vec);

        vec.push_back(root->val);

        if (root->right)
            inorder(root->right, vec);
    }
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> res;
        inorder(root, res);
        return res;
    }
};