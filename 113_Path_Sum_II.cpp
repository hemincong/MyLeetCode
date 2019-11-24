//
// Created by mincong.he on 2019/11/24.
//

#include <vector>

using namespace std;

//   Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode *root, int sum) {
        std::vector<std::vector<int>> ret;
        std::vector<int> path_t;
        travel(root, ret, path_t, 0, sum);
        return ret;
    }

private:

    static void
    travel(TreeNode *t, std::vector<std::vector<int>> &ret, std::vector<int> path_t, int curr_sum, int sum) {
        if (!t) return;

        path_t.push_back(t->val);
        curr_sum += t->val;

        if (t->left == nullptr && t->right == nullptr) {
            if (curr_sum == sum) {
                ret.push_back(path_t);
            }
        } else {
            if (t->left) travel(t->left, ret, path_t, curr_sum, sum);
            if (t->right) travel(t->right, ret, path_t, curr_sum, sum);
        }
    }

};

int main() {
    TreeNode a(5);
    TreeNode b(4);
    TreeNode c(8);
    TreeNode d(11);
    TreeNode e(13);
    TreeNode f(4);
    TreeNode g(7);
    TreeNode h(2);
    TreeNode x(5);
    TreeNode y(1);
    a.left = &b;
    a.right = &c;
    b.left = &d;
    c.left = &e;
    c.right = &f;
    d.left = &g;
    d.right = &h;
    f.left = &x;
    f.right = &y;
    Solution solve;
    std::vector<std::vector<int> > result = solve.pathSum(&a, 22);
    for (auto &i : result) {
        for (int j : i) {
            printf("[%d]", j);
        }
        printf("\n");
    }
    auto t_2 = TreeNode(0);
    std::vector<std::vector<int> > ret1 = solve.pathSum(&t_2, 1);
    for (auto &i : ret1) {
        for (int j : i) {
            printf("[%d]", j);
        }
        printf("\n");
    }
    std::vector<std::vector<int> > ret2 = solve.pathSum(nullptr, 1);
    for (auto &i : ret2) {
        for (int j : i) {
            printf("[%d]", j);
        }
        printf("\n");
    }
    return 0;
}