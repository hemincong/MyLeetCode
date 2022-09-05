//
// Created by mincong.he on 2022/9/2.
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
    int longestUnivaluePath(TreeNode* root) {
        int longest_level = 0;
        get_same_value_path(root, longest_level);
        return longest_level;
    }

    int get_same_value_path(TreeNode* node, int& longest_level) {
        if (node == nullptr) return 0;
        int left_num = get_same_value_path(node->left, longest_level);
        int right_num = get_same_value_path(node->right, longest_level);

        int lp = 0; int rp = 0;

        if (node->left && node->val == node->left->val) {
            lp = left_num + 1;
        }
        // if not same, lp and rp are 0
        if (node->right && node->val == node->right->val) {
            rp = right_num + 1;
        }

        longest_level = max(longest_level, lp + rp);

        return max(lp, rp);
    }
};