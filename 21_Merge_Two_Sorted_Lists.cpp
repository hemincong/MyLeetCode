//
// Created by mincong.he on 2019/9/18.
//

#include <cstdio>
#include <memory>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        auto l1_p = l1;
        auto l2_p = l2;
        auto new_head = make_shared<ListNode>(-1);
        auto curr_ptr = new_head.get();

        while (l1_p && l2_p) {
            if (l1_p->val < l2_p->val) {
                curr_ptr->next = l1_p;
                curr_ptr = curr_ptr->next;
                l1_p = l1_p->next;
            } else {
                curr_ptr->next = l2_p;
                curr_ptr = curr_ptr->next;
                l2_p = l2_p->next;
            }
        }

        if (l1_p) {
            curr_ptr->next = l1_p;
        }

        if (l2_p) {
            curr_ptr->next = l2_p;
        }

        return new_head->next;
    }
};

int main() {
    ListNode a(1);
    ListNode b(2);
    ListNode c(4);
    ListNode d(1);
    ListNode e(3);
    ListNode f(4);
    a.next = &b;
    b.next = &c;

    d.next = &e;
    e.next = &f;

    Solution solve;
    ListNode *head = solve.mergeTwoLists(&a, &d);
    //ListNode *head = solve.mergeTwoLists(NULL, NULL);
    //ListNode *head = solve.mergeTwoLists(&a, NULL);
    //ListNode *head = solve.mergeTwoLists(NULL, &d);
    while (head) {
        printf("%d\n", head->val);
        head = head->next;
    }
    return 0;
}