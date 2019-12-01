//
// Created by mincong.he on 2019/11/24.
//

#include <cstdio>
#include <vector>

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
        std::vector<TreeNode *> p_path;
        std::vector<TreeNode *> p_path_ret;
        bool found_p = false;
        pre_order(root, p, p_path, p_path_ret, found_p);

        std::vector<TreeNode *> q_path;
        std::vector<TreeNode *> q_path_ret;
        bool found_q = false;
        pre_order(root, q, q_path, q_path_ret, found_q);

        if (!found_q || !found_p) return NULL;
        auto q_len = q_path_ret.size();
        auto p_len = p_path_ret.size();
        auto len = q_len < p_len ? q_len : p_len;

        TreeNode *ret = NULL;
        for (int i = 0; i < len; i++) {
            if (q_path_ret[i] == p_path_ret[i]) {
                ret = q_path_ret[i];
            }
        }

        return ret;
    }

private:
    static void pre_order(TreeNode *root,
                          TreeNode *p,
                          std::vector<TreeNode *> &path,
                          std::vector<TreeNode *> &result,
                          bool &found) {
        if (!root || !p) return;

        path.push_back(root);
        if (p == root) {
            found = true;
            result = path;
            return;
        }

        pre_order(root->left, p, path, result, found);
        pre_order(root->right, p, path, result, found);
        path.pop_back();
    }
};


int main() {
    TreeNode a(3);
    TreeNode b(5);
    TreeNode c(1);
    TreeNode d(6);
    TreeNode e(2);
    TreeNode f(0);
    TreeNode x(8);
    TreeNode y(7);
    TreeNode z(4);
    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.left = &f;
    c.right = &x;
    e.left = &y;
    e.right = &z;

    Solution solve;
    TreeNode *result = solve.lowestCommonAncestor(&a, &b, &f);
    printf("lowestCommonAncestor = %d\n", result->val);
    result = solve.lowestCommonAncestor(&a, &d, &z);
    printf("lowestCommonAncestor = %d\n", result->val);
    result = solve.lowestCommonAncestor(&a, &b, &y);
    printf("lowestCommonAncestor = %d\n", result->val);

    return 0;
}


