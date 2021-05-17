//
// Created by mincong.he on 2021/5/17.
//
#include "AlgoUtils.h"

class Solution {
public:
    bool isCousins(TreeNode *root, int x, int y) {
        int x_depth = value_depth(root, 0, x, x, y);
        int y_depth = value_depth(root, 0, y, x, y);
        if (x_depth != -1 && y_depth != -1 && x_depth == y_depth) return true;
        return false;
    }

    int value_depth(TreeNode *root, int depth, int value, int x, int y) {
        if (root == nullptr) return -1;
        if (root->val == value) return depth;
        int left_depth = -1;
        int right_depth = -1;
        if (root->left) {
            left_depth = value_depth(root->left, depth + 1, value, x, y);
        }
        if (root->right) {
            right_depth = value_depth(root->right, depth + 1, value, x, y);
        }
        if (root->left && root->right &&
            ((root->left->val == x && root->right->val == y) || root->left->val == y && root->right->val == x)) {
            return -1;
        }
        if (left_depth != -1) return left_depth;
        if (right_depth != -1) return right_depth;
        return -1;
    }
};

int main(int argc, char **argv) {
    auto l_r = new TreeNode(4);
    auto l = new TreeNode(2, nullptr, l_r);
    auto r = new TreeNode(3, nullptr, nullptr);
    auto root = new TreeNode(1, l, r);
    Solution s;
    EXPECT_FALSE(s.isCousins(root, 2, 3));
    // TODO: release
    return EXIT_SUCCESS;
}
