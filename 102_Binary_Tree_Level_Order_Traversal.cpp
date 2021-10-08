#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> ret;
        if (!root) return ret;
        queue<pair<TreeNode *, int>> q;
        q.push(make_pair(root, 0));
        int curr_level = 0;
        vector<int> level_vec;
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            if (t.second > curr_level) {
                ret.push_back(level_vec);
                level_vec.clear();
                curr_level = t.second;
            }
            level_vec.push_back(t.first->val);

            if (t.first->left) q.push(make_pair(t.first->left, t.second + 1));
            if (t.first->right) q.push(make_pair(t.first->right, t.second + 1));
        }
        if (!level_vec.empty()) {
            ret.push_back(level_vec);
        }
        return ret;
    }
};

int main(int argc, char **argv) {
    Solution s;
    //[3,9,20,null,null,15,7]
    TreeNode tree_node_6(7);
    TreeNode tree_node_5(15);
    TreeNode tree_node_2(20, &tree_node_5, &tree_node_6);
    TreeNode tree_node_1(9);
    TreeNode tree_node_0(3, &tree_node_1, &tree_node_2);
    printMatrix(s.levelOrder(&tree_node_0));

    return EXIT_SUCCESS;
}