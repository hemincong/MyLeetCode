//
// Created by mincong.he on 2019-09-10.
//

#include <string>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *meet = NULL;
        while (slow && fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            // 有可能是头节点
            if (slow == fast) {
                break;
            }
        }
        ListNode *p = head;
        // 有可能是头节点，可能空列表
        if (slow == fast && fast && fast->next) {
            meet = slow;
            while (meet != p) {
                p = p->next;
                meet = meet->next;
            }
            return p;
        }
        return NULL;
    }
};

int main(int argc, char **argv) {
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    ListNode e(5);
    ListNode f(6);
    ListNode g(7);
    a.next = &b;
    a.next = NULL;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;
    f.next = &g;
    //g.next = NULL;
    //g.next = &c;

    ListNode *ret = Solution().detectCycle(&a);
    if (ret) {
        printf("%d\n", ret->val);
    } else {
        printf("NULL\n");

    }
    return 0;
}