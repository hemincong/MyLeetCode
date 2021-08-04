#include <vector>
#include <unordered_map>
#include "AlgoUtils.h"
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k) {

        unordered_map<TreeNode *, vector<TreeNode *>> p_map;
        build_no_order_map(root, p_map);

        unordered_set<TreeNode *> visited;
        vector<int> ret;
        search(p_map, target, k, visited, ret);
        return ret;
    }

private:
    void build_no_order_map(TreeNode *root, unordered_map<TreeNode *, vector<TreeNode *>> &map) {
        if (!root) return;
        if (root->left) {
            map[root].push_back(root->left);
            map[root->left].push_back(root);
            build_no_order_map(root->left, map);
        }
        if (root->right) {
            map[root].push_back(root->right);
            map[root->right].push_back(root);
            build_no_order_map(root->right, map);
        }
    }

    void search(const unordered_map<TreeNode *, vector<TreeNode *>> &map, TreeNode *target, int k,
                unordered_set<TreeNode *> &visited, vector<int> &ret) {
        if (k == 0) {
            ret.push_back(target->val);
            return;
        }
        visited.insert(target);
        auto t = map.find(target);
        if (t == map.end()) return;
        for (auto *p : t->second) {
            if (visited.find(p) == visited.end()) {
                search(map, p, k - 1, visited, ret);
            }
        }
    }
};

int main(int argc, char **argv) {
    Solution s;

    auto *node_4_3 = new TreeNode(7);
    auto *node_4_4 = new TreeNode(4);
    auto *node_3_1 = new TreeNode(6);
    auto *node_3_2 = new TreeNode(2, node_4_3, node_4_4);
    auto *node_3_3 = new TreeNode(0);
    auto *node_3_4 = new TreeNode(8);
    auto *node_2_1 = new TreeNode(5, node_3_1, node_3_2);
    auto *node_2_2 = new TreeNode(1, node_3_3, node_3_4);
    auto *root_1 = new TreeNode(3, node_2_1, node_2_2);
    vector<int> ret_1{7, 4, 1};
    assertArray(s.distanceK(root_1, node_2_1, 2), ret_1);

    auto *root_2 = new TreeNode(0);
    vector<int> ret_2{};
    assertArray(s.distanceK(root_2, root_2, 3), ret_2);
    return EXIT_SUCCESS;
}