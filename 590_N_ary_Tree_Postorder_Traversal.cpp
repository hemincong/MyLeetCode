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
    vector<int> postorder(Node* root) {
        vector<int> _v;
        traval(_v, root);
        return _v;
    }
private:
    void traval(vector<int>& v, Node* root) {
        if (!root) return;

        for (const auto& p:root->children) {
            traval(v, p);
        }
        v.push_back(root->val);
    }
};

int main(int argc, char **argv) {
    Solution s;
    return EXIT_SUCCESS;
}