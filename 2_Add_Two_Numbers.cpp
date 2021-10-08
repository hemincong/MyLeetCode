#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *root = new ListNode(0);
        ListNode *p = root;
        int n = 0;
        while (l1 && l2) {
            int rem = (l1->val + l2->val + n) % 10;
            p->next = new ListNode(rem);
            n = (l1->val + l2->val + n) / 10;
            l1 = l1->next;
            l2 = l2->next;
            p = p->next;
        }
        while (l1) {
            int rem = (l1->val + n) % 10;
            p->next = new ListNode(rem);
            n = (l1->val + n) / 10;
            l1 = l1->next;
            p = p->next;
        }
        while (l2) {
            int rem = (l2->val + n) % 10;
            p->next = new ListNode(rem);
            n = (l2->val + n) / 10;
            l2 = l2->next;
            p = p->next;
        }
        if (n) {
            p->next = new ListNode(n);
        }
        return root->next;
    }
};

int main(int argc, char **argv) {
    Solution s;
    auto node_1 = build_list_node({2, 4, 3});
    auto node_2 = build_list_node({5, 6, 4});
    auto ret_1 = s.addTwoNumbers(node_1, node_2);
    print_list_node(ret_1);
    release_list_node(node_1);
    release_list_node(node_2);
    release_list_node(ret_1);

    auto node_3 = build_list_node({0});
    auto node_4 = build_list_node({0});
    auto ret_2 = s.addTwoNumbers(node_3, node_4);
    print_list_node(ret_2);
    release_list_node(node_3);
    release_list_node(node_4);
    release_list_node(ret_2);

    auto node_5 = build_list_node({9, 9, 9, 9, 9, 9, 9});
    auto node_6 = build_list_node({9, 9, 9, 9});
    auto ret_3 = s.addTwoNumbers(node_5, node_6);
    print_list_node(ret_3);
    release_list_node(node_5);
    release_list_node(node_6);
    release_list_node(ret_3);
    return EXIT_SUCCESS;
}