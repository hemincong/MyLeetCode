//
// Created by mincong.he on 2019-09-11.
//
/**
 * Definition for singly-linked list.
 */
#include <memory>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        auto less_head = std::make_shared<ListNode>(0);
        auto less_head_p = less_head.get();
        auto larger_head = std::make_shared<ListNode>(0);
        auto larger_head_p = larger_head.get();
        ListNode *tmp = nullptr;

        while (head) {
            tmp = head->next;
            if (head->val < x) {
                less_head_p->next = head;
                less_head_p = less_head_p->next;
            } else {
                larger_head_p->next = head;
                larger_head_p = larger_head_p->next;
            }
            head = tmp;
        }
        less_head_p->next = larger_head->next;
        larger_head_p->next = nullptr;
        return less_head->next;
    }
};

int main() {
    ListNode a(1);
    ListNode b(4);
    ListNode c(3);
    ListNode d(2);
    ListNode e(5);
    ListNode f(2);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;
    Solution solve;
    ListNode *head = solve.partition(&a, 3);
    while (head) {
        printf("%d\n", head->val);
        head = head->next;
    }
    return 0;
}