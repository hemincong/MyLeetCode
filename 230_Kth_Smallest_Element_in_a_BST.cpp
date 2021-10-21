#include <vector>
#include "AlgoUtils.h"

using namespace std;

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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode *> s;
        TreeNode *p = root;
        while (p || s.size() > 0) {
            while (p) {
                s.push(p);
                p = p->left;
            }
            p = s.top();
            s.pop();
            --k;
            if (k == 0) break;
            p = p->right;
        }
        return p->val;
    }

};
int main(int argc, char **argv) {
    Solution s;
    TreeNode t_1_4(2);
    TreeNode t_1_2(4);
    TreeNode t_1_1(1, nullptr, &t_1_4);
    TreeNode t_1_0(3, &t_1_1, &t_1_2);
    EXPECT_EQ(s.kthSmallest(&t_1_0, 1), 1);

    TreeNode t_2_7(1);
    TreeNode t_2_4(4);
    TreeNode t_2_3(2, &t_2_7, nullptr);
    TreeNode t_2_2(6);
    TreeNode t_2_1(3, &t_2_3, &t_2_4);
    TreeNode t_2_0(5, &t_2_1, &t_2_2);
    EXPECT_EQ(s.kthSmallest(&t_2_0, 3), 3);
    return EXIT_SUCCESS;
}