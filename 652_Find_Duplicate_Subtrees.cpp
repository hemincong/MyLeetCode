#include <vector>
#include <string>
#include <unordered_map>

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
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
        std::unordered_map<std::string, int> visited;
        vector<TreeNode *> ret;
        std::string s;
        dfs(root, visited, ret);
        return ret;
    }

    std::string dfs(TreeNode *n,
                    std::unordered_map<std::string, int> &s,
                    std::vector<TreeNode *> &ret) {
        if (!n) {
            return "#";
        }

        auto left_path = dfs(n->left, s, ret);
        auto right_path = dfs(n->right, s, ret);

        auto whole_path = to_string(n->val) + " " + left_path + " " + right_path;
        std::cout << whole_path << std::endl;
        if (s[whole_path] == 1) {
            ret.push_back(n);
        }
        s[whole_path]++;
        return whole_path;
    }
};

int main(int argc, char **argv) {
    Solution s;
    //[1,2,3,4,null,2,4,null,null,4]
    auto *node_9 = new TreeNode(4);
    auto *node_6 = new TreeNode(4);
    auto *node_5 = new TreeNode(2, node_9, nullptr);
    auto *node_3 = new TreeNode(4);
    auto *node_2 = new TreeNode(3, node_5, node_6);
    auto *node_1 = new TreeNode(2, node_3, nullptr);
    auto *node_0 = new TreeNode(1, node_1, node_2);
    auto ret = s.findDuplicateSubtrees(node_0);
    EXPECT_EQ(ret.size(), 2)


    Solution s_2;
    // [0,0,0,0,null,null,0,null,null,null,0]
    auto *n_10 = new TreeNode(0);
    auto *n_6 = new TreeNode(0, nullptr, n_10);
    auto *n_3 = new TreeNode(0);
    auto *n_2 = new TreeNode(0, nullptr, n_6);
    auto *n_1 = new TreeNode(0, n_3, nullptr);
    auto *n_0 = new TreeNode(0, n_1, n_2);
    auto ret_1 = s_2.findDuplicateSubtrees(n_0);
    EXPECT_EQ(ret_1.size(), 1)

    return EXIT_SUCCESS;
}