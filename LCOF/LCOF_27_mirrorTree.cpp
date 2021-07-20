//
// Created by mincong.he on 2021/7/20.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if (!root) return NULL;
        TreeNode * temp = root->left;
        root->left = root->right;
        root->right = temp;
        if (root->right) mirrorTree(root->right);
        if (root->left) mirrorTree(root->left);
        return root;
    }
};