//
// Created by mincong.he on 2021/7/20.
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
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (!A || !B) return false;
        return dfs(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
private:
    bool dfs(TreeNode *A, TreeNode*B) {
        if (!B) return true;
        if (!A) return false;
        return (A->val == B->val) && dfs(A->left, B->left) && dfs(A->right, B->right);
    }
};