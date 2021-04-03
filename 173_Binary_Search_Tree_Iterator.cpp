//
// Created by mincong.he on 2021/3/28.
//
#include "AlgoUtils.h"
#include <vector>

/**
 * Definition for a binary tree node.
 */

using namespace std;


class BSTIterator_1 {
public:
    BSTIterator_1(TreeNode *root) : _index(0), _min(INT_MAX) {
        auto depth = _getTreeNodeDepth(root);
        auto n = pow(2, depth) - 1;
        _has_value = vector<int>(n, 0);
        _tree_value = vector<int>(n, 0);
        _mediatrval(root, 0, n);
    }

    int next() {
        for (int i = _index; i < _has_value.size(); ++i) {
            if (_has_value[i] != 0) {
                _index = i + 1;
                return _tree_value[i];
            }
        }
        return _min;
    }

    bool hasNext() {
        for (int i = _index; i < _has_value.size(); ++i) {
            if (_has_value[i] != 0) return true;
        }
        return false;
    }

private:
    int _getTreeNodeDepth(TreeNode *root) {
        if (!root) return 0;

        int left_depth = _getTreeNodeDepth(root->left);
        int right_depth = _getTreeNodeDepth(root->right);
        return left_depth > right_depth ? left_depth + 1 : right_depth + 1;
    }

    void _mediatrval(TreeNode *root, int pos_start, int pos_end) {
        if (root->val < _min) _min = root->val;
        auto pos = pos_start + (pos_end - pos_start) / 2;
        _has_value[pos] = 1;
        _tree_value[pos] = root->val;

        if (root->left) _mediatrval(root->left, pos_start, pos);
        if (root->right) _mediatrval(root->right, pos, pos_end);
    }

    vector<int> _has_value;
    vector<int> _tree_value;
    int _index;
    int _min;
};

class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        _mediatrval(root);
    }

    int next() {
        auto t = _s.top();
        _s.pop();
        return t;
    }

    bool hasNext() {
        return !_s.empty();
    }

private:
    void _mediatrval(TreeNode *root) {
        if (!root) return;

        if (root->right) _mediatrval(root->right);
        _s.push(root->val);
        if (root->left) _mediatrval(root->left);
    }

    stack<int> _s;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main(int argc, char **argv) {
    auto *r_l = new TreeNode(9);
    auto *r_r = new TreeNode(20);
    auto *r = new TreeNode(15, r_l, r_r);
    auto *l = new TreeNode(3);
    auto *root = new TreeNode(7, l, r);

    auto bSTIterator_1 = BSTIterator_1(root);
    EXPECT_EQ(bSTIterator_1.next(), 3);    // return 3
    EXPECT_EQ(bSTIterator_1.next(), 7);    // return 7
    EXPECT_TRUE(bSTIterator_1.hasNext()); // return True
    EXPECT_EQ(bSTIterator_1.next(), 9);    // return 9
    EXPECT_TRUE(bSTIterator_1.hasNext()); // return True
    EXPECT_EQ(bSTIterator_1.next(), 15);    // return 15
    EXPECT_TRUE(bSTIterator_1.hasNext()); // return True
    EXPECT_EQ(bSTIterator_1.next(), 20);    // return 20
    EXPECT_FALSE(bSTIterator_1.hasNext()); // return False

    auto bSTIterator = BSTIterator(root);
    EXPECT_EQ(bSTIterator.next(), 3);    // return 3
    EXPECT_EQ(bSTIterator.next(), 7);    // return 7
    EXPECT_TRUE(bSTIterator.hasNext()); // return True
    EXPECT_EQ(bSTIterator.next(), 9);    // return 9
    EXPECT_TRUE(bSTIterator.hasNext()); // return True
    EXPECT_EQ(bSTIterator.next(), 15);    // return 15
    EXPECT_TRUE(bSTIterator.hasNext()); // return True
    EXPECT_EQ(bSTIterator.next(), 20);    // return 20
    EXPECT_FALSE(bSTIterator.hasNext()); // return False
    return EXIT_SUCCESS;
}