//
// Created by mincong.he on 2021/1/24.
//

#include <cstdlib>

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (!root || p == root || q == root) return root;
        auto left_root = lowestCommonAncestor(root->left, p, q);
        auto right_root = lowestCommonAncestor(root->right, p, q);
        if (left_root && right_root) return root;

        if (left_root)
            return left_root;

        return right_root;
    }
};
