//
// Created by mincong.he on 2020/7/28.
//

#include <cstdlib>
#include "AlgoUtils.h"

/**
 * Definition for a binary tree node.
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}

    TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
};

class Solution {
public:
    int maxDepth(TreeNode *root) {
        if (!root) return 0;

        int left_depth = 0;
        int right_depth = 0;

        if (root->left) left_depth = maxDepth(root->left);
        if (root->right) right_depth = maxDepth(root->right);

        if (left_depth > right_depth) {
            return left_depth + 1;
        }

        return right_depth + 1;
    }
};

int main(int argc, char **argv) {
    TreeNode d(15);
    TreeNode e(7);
    TreeNode c(20, &d, &e);
    TreeNode b(9);
    TreeNode a(3, &b, &c);
    Solution s;
    EXPECT_EQ(s.maxDepth(&a), 3);
    return EXIT_SUCCESS;
}