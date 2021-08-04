//
// Created by mincong.he on 2021/7/25.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> levelOrder(TreeNode *root) {
        vector<int> ret;
        if (!root) return ret;
        queue < TreeNode * > q;
        q.push(root);
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            ret.push_back(t->val);
            if (t->left) q.push(t->left);
            if (t->right) q.push(t->right);
        }
        return ret;
    }
};