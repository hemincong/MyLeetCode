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
    bool findTarget(TreeNode* root, int k) {
        set<int> s;
        travel(s, root);
        //if (s.size() < 2) return false;

        for (const auto n: s ) {
            if ((k - n) != n && s.find(k - n) != s.end() ) return true;
        }
        return false;

    }
    void travel(set<int>& s, TreeNode *node) {
        if (node) s.insert(node->val);

        if (node->left) travel(s, node->left);
        if (node->right) travel(s, node->right);

        return;
    }
};

int main(int argc, char **argv) {
    Solution s;
    return EXIT_SUCCESS;
}