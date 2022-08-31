//
// Created by mincong.he on 2022/8/31.
//
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isValidBST(TreeNode *root) {
        return isValidNode(root, LLONG_MIN, LLONG_MAX);
    }

    bool isValidNode(TreeNode *node, long long min, long long max) {
        if (node == nullptr) return true;
        if (node->val >= max) return false;
        if (node->val <= min) return false;
        bool left_ret = true;
        bool right_ret = true;
        if (node->left) left_ret = isValidNode(node->left, min, node->val);
        if (node->right) right_ret = isValidNode(node->right, node->val, max);

        return left_ret && right_ret;
    }
};