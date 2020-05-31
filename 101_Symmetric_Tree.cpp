//
// Created by mincong.he on 2020/5/31.
//

#include <cstdio>
#include <cstdlib>
#include <cassert>

/*
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
    bool isSymmetric(TreeNode *root) {
        return isMirror(root, root);
    }

private:
    bool isMirror(TreeNode *left, TreeNode *right) {
        if (!left && !right) return true;

        if (!left || !right) return false;

        if (left->val == right->val) {
            return isMirror(left->left, right->right) && isMirror(left->right, right->left);
        }

        return false;
    }
};

int main(int argc, char **argv) {
    TreeNode node_root(1);
    TreeNode node_L1_0(2);
    TreeNode node_L1_1(2);
    TreeNode node_L2_0(3);
    TreeNode node_L2_1(4);
    TreeNode node_L2_2(4);
    TreeNode node_L2_3(3);
    node_root.left = &node_L1_0;
    node_root.right = &node_L1_1;
    node_L1_0.left = &node_L2_0;
    node_L1_0.right = &node_L2_1;
    node_L1_1.left = &node_L2_2;
    node_L1_1.right = &node_L2_3;

    Solution solution;
    auto ret = solution.isSymmetric(&node_root);
    assert(ret);

    return EXIT_SUCCESS;
}