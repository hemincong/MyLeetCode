#include <string>
#include <vector>
#include "AlgoUtils.h"

using namespace std;

/*
 * Definition for singly-linked list.
 */

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (!head || head->next == NULL || n <= m || m < 0 || n < 0) return head;

        ListNode *p, *tmp, *pre_head, *tail, *h = new ListNode(-1);
        // 制造一个前置, 防止首元素就可以循环
        h->next = head;
        pre_head = h;
        p = h;
        for (int i = 0; i < m && p; ++i) {
            pre_head = p;
            p = p->next;
        }
        tail = p;
        for (int i = 0; i < n - m + 1 && p; i++) {
            tmp = p->next;
            p->next = pre_head->next;
            pre_head->next = p;
            p = tmp;
        }
        tail->next = p;

        ListNode *ret = h->next;
        if (h) delete (h);
        return ret;
    }
};


ListNode *build_list_node(const vector<int> &input) {
    if (input.empty()) return nullptr;

    auto *root = new ListNode(input[0]);
    auto *p = root;
    for (int i = 1; i < input.size(); ++i) {
        auto *tmp = new ListNode(input[i]);
        p->next = tmp;
        p = p->next;
    }
    return root;
}

vector<int> build_vector(const ListNode *root) {
    vector<int> ret;

    auto p = root;
    while (p) {
        ret.push_back(p->val);
        p = p->next;
    }
    return ret;
}

void release_list_node(ListNode *root) {
    auto p = root;
    while (p) {
        auto tmp = p->next;
        delete p;
        p = tmp;
    }
}


int main(int argc, char **argv) {
    Solution s;
    vector<int> test_case_1{1, 2, 3, 4, 5};
    vector<int> ret_1{1, 4, 3, 2, 5};
    ListNode *test_case_1_root = build_list_node(test_case_1);
    assertArray(build_vector(s.reverseBetween(test_case_1_root, 2, 4)), ret_1);
    release_list_node(test_case_1_root);

    vector<int> test_case_2{5};
    vector<int> ret_2{5};
    ListNode *test_case_2_root = build_list_node(test_case_2);
    assertArray(build_vector(s.reverseBetween(test_case_2_root, 1, 1)), ret_2);
    release_list_node(test_case_2_root);

    return EXIT_SUCCESS;
}