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
private:

    void travel(vector<int>& _v, Node* node) {
        if (!node) return;
        _v.push_back(node->val);
        for (const auto& c: node->children) {
            travel(_v, c);
        }
    }
public:
    vector<int> preorder(Node* root) {
        vector<int> _v;
        travel(_v, root);
        return _v;
    }
};