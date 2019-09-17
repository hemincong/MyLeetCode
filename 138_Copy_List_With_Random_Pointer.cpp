//
// Created by mincong.he on 2019-09-12.
//

// Definition for a Node.
#include <cstdio>
#include <map>

using namespace std;

class Node {
public:
    int val{};
    Node *next{};
    Node *random{};

    Node() = default;

    explicit Node(int _val) :
            val(_val),
            next(nullptr),
            random(nullptr) {
    }

    Node(int _val, Node *_next, Node *_random) :
            val(_val),
            next(_next),
            random(_random) {
    }
};

class Solution {
public:
    Node *copyRandomList(Node *head) {
        if (!head) return nullptr;

        Node *new_head = nullptr;
        Node *pre = nullptr;
        map<Node *, Node *> random_map;
        map<Node *, Node *> new_node_old_node_map;
        while (head) {
            auto new_node = new Node();
            new_node->random = NULL;
            new_node->next = NULL;
            if (!new_head) {
                new_head = new_node;
            }
            new_node->val = head->val;
            new_node->next = head->next;
            if (pre) {
                pre->next = new_node;
            }
            if (head->random) {
                random_map[new_node] = head->random;
            }
            new_node_old_node_map[head] = new_node;
            pre = new_node;

            head = head->next;
        }

        for (auto &n : random_map) {
            const auto new_node_p = new_node_old_node_map.find(n.second);
            if (new_node_p != new_node_old_node_map.end()) {
                n.first->random = new_node_p->second;
            }
        }

        return new_head;
    }
};

int main() {
    // {"$id":"1","next":null,"random":null,"val":-1}
    Node a(-1);
    a.next = NULL;
    a.random = NULL;
//{"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}}
    //Node a(1);
    //Node b(2);
    //Node c(3);
    //Node d(4);
    //Node e(5);
    //a.next = &b;
    //b.next = &c;
    //c.next = &d;
    //d.next = &e;
    //a.random = &c;
    //b.random = &d;
    //c.random = &c;
    //e.random = &d;
    Solution solve;
    Node *old_head = &a;
    while (old_head) {
        printf("label = %d ", old_head->val);
        if (old_head->random) {
            printf("rand = %d\n", old_head->random->val);
        } else {
            printf("rand = NULL\n");
        }
        old_head = old_head->next;
    }

    printf("============================\n");

    Node *head = solve.copyRandomList(&a);
    while (head) {
        printf("label = %d ", head->val);
        if (head->random) {
            printf("rand = %d\n", head->random->val);
        } else {
            printf("rand = NULL\n");
        }
        head = head->next;
    }
    return 0;
}