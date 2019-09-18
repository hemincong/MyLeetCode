//
// Created by mincong.he on 2019/9/18.
//

#include <vector>
#include <cstdio>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    auto l1_p = l1;
    auto l2_p = l2;
    auto new_head = make_shared<ListNode>(-1);
    auto curr_ptr = new_head.get();

    while (l1_p && l2_p) {
        if (l1_p->val < l2_p->val) {
            curr_ptr->next = l1_p;
            l1_p = l1_p->next;
        } else {
            curr_ptr->next = l2_p;
            l2_p = l2_p->next;
        }
        curr_ptr = curr_ptr->next;
    }

    if (l1_p) {
        curr_ptr->next = l1_p;
    }

    if (l2_p) {
        curr_ptr->next = l2_p;
    }

    return new_head->next;
}

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty()) {
            return NULL;
        }
        if (lists.size() == 1) {
            return lists[0];
        }

        if (lists.size() == 2) {
            return mergeTwoLists(lists[0], lists[1]);
        }

        int mid_pos = lists.size() / 2;
        vector<ListNode *> front_list;
        vector<ListNode *> back_list;
        for (int i = 0; i < mid_pos; ++i) {
            front_list.push_back(lists[i]);
        }
        for (int i = mid_pos; i < lists.size(); ++i) {
            back_list.push_back(lists[i]);
        }

        auto front_ret = mergeKLists(front_list);
        auto back_ret = mergeKLists(back_list);
        return mergeTwoLists(front_ret, back_ret);
    }
};

int main() {
    //ListNode a(1);
    //ListNode b(4);
    //ListNode c(5);

    //ListNode d(1);
    //ListNode e(3);
    //ListNode f(4);

    //ListNode g(2);
    //ListNode h(6);
    //a.next = &b;
    //b.next = &c;

    //d.next = &e;
    //e.next = &f;

    //g.next = &h;
    //g.next = NULL;

    ListNode a(2);
    //ListNode d(1);
    ListNode g(-1);

    Solution solve;
    std::vector<ListNode *> lists;
    lists.push_back(&a);
    //lists.push_back(&d);
    lists.push_back(NULL);
    lists.push_back(&g);
    ListNode *head = solve.mergeKLists(lists);
    while (head) {
        printf("%d\n", head->val);
        head = head->next;
    }
    return 0;
}