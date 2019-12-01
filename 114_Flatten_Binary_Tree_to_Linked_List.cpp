//
// Created by mincong.he on 2019/12/1.
//

#include <cstdio>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void flatten(TreeNode *root) {
        if (!root) return;
        std::vector<TreeNode *> ret;

        pre_order(root, ret);

        for (int i = 0; i < ret.size() - 1; i++) {
            ret.at(i)->right = ret.at(i + 1);
            ret.at(i)->left = NULL;
        }
    }

private:
    static void pre_order(TreeNode *root, std::vector<TreeNode *> &ret) {
        if (!root) return;

        ret.push_back(root);
        pre_order(root->left, ret);
        pre_order(root->right, ret);
    }
};

class Solution2 {
public:
    void flatten(TreeNode *root) {
        if (!root) return;
        std::vector<TreeNode *> ret;

        TreeNode *left = NULL;
        pre_order(root, &left);
    }

private:
    static void pre_order(TreeNode *root, TreeNode **last) {
        if (!root) return;

        if (!root->left && !root->right) {
            *last = root;
            return;
        }

        TreeNode *left_tmp = root->left;
        TreeNode *right_tmp = root->right;
        TreeNode *left_last = nullptr;
        TreeNode *right_last = nullptr;
        if (left_tmp) {
            pre_order(left_tmp, &left_last);
            root->left = nullptr;
            root->right = left_tmp;
            *last = left_last;
        }
        if (right_tmp) {
            pre_order(right_tmp, &right_last);
            if (left_last) {
                left_last->right = right_tmp;
            }
            *last = right_last;
        }
    }
};


int main(int argc, char **argv) {
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(3);
    TreeNode d(4);
    TreeNode e(5);
    a.left = &b;
    b.left = &c;
    b.right = &d;
    c.left = &e;
    //TreeNode a(1);
    //TreeNode b(2);
    //TreeNode c(3);
    //a.left = &b;
    //b.left = &c;
    Solution2 solve;
    solve.flatten(&a);
    TreeNode *head = &a;
    while (head) {
        if (head->left) {
            printf("ERROR\n");
        }
        printf("[%d]", head->val);
        head = head->right;
    }
    printf("\n");
    return 0;
};