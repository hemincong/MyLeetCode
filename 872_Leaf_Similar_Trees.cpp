//
// Created by mincong.he on 2021/5/10.
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
    bool leafSimilar(TreeNode *root1, TreeNode *root2) {
        travel(root1_leaf, root1);
        travel(root2_leaf, root2);
        return root1_leaf == root2_leaf;
    }

private:
    void travel(vector<int> &leaf, TreeNode *root) {
        if (!root) return;

        if (!root->left && !root->right) {
            leaf.push_back(root->val);
        }

        if (root->left) {
            travel(leaf, root->left);
        }
        if (root->right) {
            travel(leaf, root->right);
        }
    }

    vector<int> root1_leaf;
    vector<int> root2_leaf;
};