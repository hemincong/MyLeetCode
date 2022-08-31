//
// Created by mincong.he on 2022/8/30.
//

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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        TreeNode * ret = nullptr;
        if (val > root->val) {
            ret = new TreeNode(val, root, nullptr);
            return ret;
        }
        ret = root;
        buildTree(root, val);
        return ret;
    }
    void buildTree(TreeNode* t, int val) {
        if (t->right == nullptr) {
            t->right = new TreeNode(val);
        } else if (t->right->val < val) {
            auto temp = t->right;
            t->right = new TreeNode(val, temp, nullptr);
        } else {
            buildTree(t->right, val);
        }
    }
};