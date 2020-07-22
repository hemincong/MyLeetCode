//
// Created by mincong.he on 2020/7/21.
//
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        if (n > 0) {
            return generate(1, n);
        } else {
            return vector<TreeNode *>();
        }
    }

    vector<TreeNode *> generate(int left, int right) {
        vector<TreeNode *> ans;
        if (left > right) {
            ans.push_back(nullptr);
            return ans;
        }
        for (int i = left; i <= right; i++) {
            auto left_nodes = generate(left, i - 1);
            auto right_nodes = generate(i + 1, right);
            for (auto *left_node : left_nodes) {
                for (auto *right_node : right_nodes) {
                    ans.emplace_back(new TreeNode(i, left_node, right_node));
                }
            }
        }
        return ans;
    }
};

void printBinaryTree(TreeNode *t) {
    if (!t) {
        printf("null,");
        return;
    };

    printf("%d,", t->val);

    if (t->right || t->left) {
        printBinaryTree(t->left);
        printBinaryTree(t->right);
    }
}

int main(int argc, char **argv) {
    Solution s;
    auto ret_1 = s.generateTrees(3);
    printf("[\n");
    for (const auto t:ret_1) {
        printf("[");
        printBinaryTree(t);
        printf("],\n");
    }
    printf("],\n");

    return EXIT_SUCCESS;
}