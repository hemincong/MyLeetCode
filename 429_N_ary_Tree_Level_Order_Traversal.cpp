#include <vector>
#include "AlgoUtils.h"

using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ret;
        if (!root) return ret;
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            vector<int> level;
            auto level_size = q.size();
            for (int i = 0; i < level_size; ++i) {
                auto t = q.front();
                q.pop();

                level.push_back(t->val);
                for (auto *n : t->children) {
                    q.push(n);
                }
            }
            ret.emplace_back(std::move(level));
        }
        return ret;

    }
};

int main(int argc, char **argv) {
    Solution s;
    return EXIT_SUCCESS;
}