//
// Created by mincong.he on 2019/12/2.
//

#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode *root) {
        vector<int> ret;
        if (!root) return ret;

        std::queue<std::pair<TreeNode *, int>> q_all;
        q_all.push(std::make_pair(root, 0));
        int curr_level = 0;
        int last = root->val;

        while (!q_all.empty()) {
            auto q_top = q_all.front();
            q_all.pop();
            if (q_top.first->left) {
                q_all.push(std::make_pair(q_top.first->left, q_top.second + 1));
            }
            if (q_top.first->right) {
                q_all.push(std::make_pair(q_top.first->right, q_top.second + 1));
            }

            if (q_top.second != curr_level) {
                curr_level++;
                ret.push_back(last);
            }
            last = q_top.first->val;
        }
        ret.push_back(last);
        return ret;
    }
};

int main(int argc, char **argv) {
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(5);
    TreeNode d(3);
    TreeNode e(4);
    TreeNode f(6);
    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.right = &f;
    Solution solve;
    std::vector<int> result = solve.rightSideView(&a);
    for (int i : result) {
        printf("[%d]\n", i);
    }
    return EXIT_SUCCESS;
}