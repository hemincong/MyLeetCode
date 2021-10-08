//
// Created by mincong.he on 2021/9/24.
//

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node *flatten(Node *head) {
        if (!head) return nullptr;
        dfs(head);
        auto n = _nodes.size();
        for (int i = 0; i < n; ++i) {
            if (i > 0) _nodes[i]->prev = _nodes[i - 1];
            if (i < n - 1)_nodes[i]->next = _nodes[i + 1];
            _nodes[i]->child = nullptr;
        }
        _nodes[n - 1] = nullptr;
        return _nodes[0];
    }

private:
    vector<Node *> _nodes;

    void dfs(Node *n) {
        if (n) _nodes.push_back(n);
        if (n->child) dfs(n->child);
        if (n->next) dfs(n->next);
    }
};