#include <vector>
#include "AlgoUtils.h"
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode *root) {
        vector<vector<int>> ret;
        map<int, vector<pair<TreeNode *, int>>> m;
        travel(root, 0, 0, m);
        for (auto &[col, nodes] : m) {
            auto temp = vector<int>();
            sort(nodes.begin(), nodes.end(), [](const auto &p1, const auto &p2) {
                if (p1.second == p2.second) {
                    return p1.first->val < p2.first->val;
                }
                return p1.second < p2.second;
            });
            for (auto &t : nodes) {
                temp.push_back(t.first->val);
            }
            ret.emplace_back(temp);
        }
        return ret;
    }

    void travel(TreeNode *root, int col, int row, map<int, vector<pair<TreeNode *, int>>> &m) {
        if (root) {
            m[col].push_back(make_pair(root, row));
        }

        if (root->left) {
            travel(root->left, col - 1, row + 1, m);
        }
        if (root->right) {
            travel(root->right, col + 1, row + 1, m);
        }
    }
};

int main(int argc, char **argv) {
    Solution s;
    auto tree1_5 = new TreeNode(15);
    auto tree1_6 = new TreeNode(7);
    auto tree1_2 = new TreeNode(20, tree1_5, tree1_6);
    auto tree1_1 = new TreeNode(9);
    auto tree1_0 = new TreeNode(3, tree1_1, tree1_2);
    printMatrix(s.verticalTraversal(tree1_0));
    // [[9],[3,15],[20],[7]]

    auto tree2_6 = new TreeNode(7);
    auto tree2_5 = new TreeNode(6);
    auto tree2_4 = new TreeNode(5);
    auto tree2_3 = new TreeNode(4);
    auto tree2_2 = new TreeNode(3, tree2_5, tree2_6);
    auto tree2_1 = new TreeNode(2, tree2_3, tree2_4);
    auto tree2_0 = new TreeNode(1, tree2_1, tree2_2);
    printMatrix(s.verticalTraversal(tree2_0));
    // [[4],[2],[1,5,6],[3],[7]]

    auto tree3_6 = new TreeNode(7);
    auto tree3_5 = new TreeNode(5);
    auto tree3_4 = new TreeNode(6);
    auto tree3_3 = new TreeNode(4);
    auto tree3_2 = new TreeNode(3, tree3_5, tree3_6);
    auto tree3_1 = new TreeNode(2, tree3_3, tree3_4);
    auto tree3_0 = new TreeNode(1, tree3_1, tree3_2);
    printMatrix(s.verticalTraversal(tree3_0));
    // [[4],[2],[1,5,6],[3],[7]]


    return EXIT_SUCCESS;
}