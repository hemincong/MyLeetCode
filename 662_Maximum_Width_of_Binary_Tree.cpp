//
// Created by mincong.he on 2022/8/27.
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
typedef map<int, pair<unsigned int, unsigned int>> level_rec;

class Solution {
public:
    int widthOfBinaryTree(TreeNode *root) {
        level_rec rec;
        get_tree_left_and_right(root, 0, 0, rec);
        int max_width = 0;
        for (auto &[level, l_r_p]: rec) {
            auto [l, r] = l_r_p;
            auto w = r - l + 1;
            if (w > max_width) max_width = w;
        }
        return max_width;
    }

    void get_tree_left_and_right(TreeNode *root, unsigned int level, unsigned int index, level_rec &rec) {
        if (rec.find(level) == rec.end()) {
            rec[level] = {index, index};
        }
        auto &[l, r] = rec[level];
        if (l > index) {
            l = index;
        }
        if (r < index) {
            r = index;
        }

        if (root->left) {
            get_tree_left_and_right(root->left, level + 1, index * 2, rec);
        }
        if (root->right) {
            get_tree_left_and_right(root->right, level + 1, index * 2 + 1, rec);
        }
    }
};