#include <vector>
#include <unordered_map>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        for (int i = 0; i < inorder.size(); ++i) {
            _map[inorder[i]] = i;
        }
        return my_build_tree(preorder, inorder,
                             0, preorder.size() - 1,
                             0, inorder.size() - 1);
    }

private:

    TreeNode *
    my_build_tree(vector<int> &preorder, vector<int> &inorder,
                  int preorder_left, int preorder_right,
                  int inorder_left, int inorder_right) {
        if (preorder_left > preorder_right) return nullptr;
        auto *root = new TreeNode(preorder[preorder_left]);

        int inorder_root = _map[preorder[preorder_left]];
        int left_size = inorder_root - inorder_left;
        root->left = my_build_tree(preorder, inorder,
                                   preorder_left + 1, preorder_left + left_size,
                                   inorder_left, inorder_root - 1);
        root->right = my_build_tree(preorder, inorder,
                                    preorder_left + left_size + 1, preorder_right,
                                    inorder_root + 1, inorder_right);
        return root;
    }

    unordered_map<int, int> _map;

};

int main(int argc, char **argv) {
    Solution s;
    vector<int> preorder_1{3, 9, 20, 15, 7};
    vector<int> inorder_1 = {9, 3, 15, 20, 7};
    auto t_1 = s.buildTree(preorder_1, inorder_1);

    vector<int> preorder_2{-1};
    vector<int> inorder_2 = {-1};
    auto t_2 = s.buildTree(preorder_2, inorder_2);
    return EXIT_SUCCESS;
}