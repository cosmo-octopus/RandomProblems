/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int find_diameter(struct TreeNode* root, int *diameter)
{
    if (!root)
        return (0);
    int left = find_diameter(root->left, diameter);
    int right = find_diameter(root->right, diameter);
    
    *diameter = MAX(*diameter, left + right);

    return 1 + MAX(left, right);
}

int diameterOfBinaryTree(struct TreeNode* root)
{
    int diameter = 0;
    find_diameter(root, &diameter);
    return (diameter);
}