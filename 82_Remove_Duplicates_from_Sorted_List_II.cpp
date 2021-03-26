//
// Created by mincong.he on 2021/3/25.
//

/**
 * Definition for singly-linked list.
 */
#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head) return head;

        auto *tmp_head = new ListNode(0, head);
        auto p = tmp_head;
        while (p->next && p->next->next) {
            auto compare_val = p->next->val;
            if (p->next->next->val == compare_val) {
                while (p->next && p->next->val == compare_val) {
                    auto *tmp = p->next;
                    p->next = p->next->next;
                    delete tmp;
                }
            } else {
                p = p->next;
            }
        }

        auto ret = tmp_head->next;
        delete tmp_head;
        return ret;
    }
};

int main(int argc, char **argv) {
    Solution s;

    auto test_case_vector_1 = vector<int>{1, 2, 3, 3, 4, 4, 5};
    auto test_case_list_node_1 = build_list_node(test_case_vector_1);
    auto test_case_ret_1 = vector<int>{1, 2, 5};
    auto ret_1 = s.deleteDuplicates(test_case_list_node_1);
    assertArray(build_vector(ret_1), test_case_ret_1);
    //release_list_node(test_case_list_node_1);

    auto test_case_vector_2 = vector<int>{1, 1, 1, 2, 3};
    auto test_case_ret_2 = vector<int>{2, 3};
    auto test_case_list_node_2 = build_list_node(test_case_vector_2);
    auto ret_2 = s.deleteDuplicates(test_case_list_node_2);
    assertArray(build_vector(ret_2), test_case_ret_2);
    //release_list_node(test_case_list_node_2);

    auto test_case_vector_3 = vector<int>{1, 1};
    auto test_case_ret_3 = vector<int>{};
    auto test_case_list_node_3 = build_list_node(test_case_vector_3);
    auto ret_3 = s.deleteDuplicates(test_case_list_node_3);
    assertArray(build_vector(ret_3), test_case_ret_3);
    return EXIT_SUCCESS;
}
