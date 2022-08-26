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
    int deepestLeavesSum(TreeNode *root) {
        if (!root) return 0;

        std::queue<std::pair<TreeNode *, int>> q;
        q.push({root, 0});

        int max_level = -1;
        int max_level_sum = 0;

        while (!q.empty()) {
            auto [node, level] = q.front();
            q.pop();
            if (level == max_level) {
                max_level_sum += node->val;
            } else if (level > max_level) {
                max_level = level;
                max_level_sum = node->val;
            }

            if (node->left) {
                q.push({node->left, level + 1});
            }
            if (node->right) {
                q.push({node->right, level + 1});
            }
        }
        return max_level_sum;
    }
};

int main(int argc, char **argv) {
    Solution s;
    return EXIT_SUCCESS;
}