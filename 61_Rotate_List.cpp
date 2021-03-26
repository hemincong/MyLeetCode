//
// Created by mincong.he on 2021/3/27.
//

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
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head) return nullptr;
        if (k < 1) return head;
        size_t n = 0;
        auto temp = new ListNode(0, head);
        auto old_tail = temp;
        while (old_tail->next) {
            old_tail = old_tail->next;
            n++;
        }

        auto real_offset = n - k % n;
        // FIXME: temp head leaking
        if (real_offset < 1 || real_offset == n) return head;

        auto new_tail = temp;
        for (int i = 0; i < real_offset; ++i) {
            new_tail = new_tail->next;
        }

        auto new_head = new_tail->next;
        new_tail->next = nullptr;
        old_tail->next = head;
        delete temp;
        return new_head;
    }
};

int main(int argc, char **argv) {
    Solution s;

    auto test_case_vector_1 = vector<int>{1, 2, 3, 4, 5};
    auto test_case_list_node_1 = build_list_node(test_case_vector_1);
    auto test_case_ret_1 = vector<int>{4, 5, 1, 2, 3};
    auto ret_1 = s.rotateRight(test_case_list_node_1, 2);
    assertArray(build_vector(ret_1), test_case_ret_1);
    release_list_node(ret_1);

    auto test_case_vector_2 = vector<int>{0, 1, 2};
    auto test_case_ret_2 = vector<int>{2, 0, 1};
    auto test_case_list_node_2 = build_list_node(test_case_vector_2);
    auto ret_2 = s.rotateRight(test_case_list_node_2, 4);
    assertArray(build_vector(ret_2), test_case_ret_2);
    release_list_node(ret_2);

    auto test_case_vector_3 = vector<int>{1};
    auto test_case_ret_3 = vector<int>{1};
    auto test_case_list_node_3 = build_list_node(test_case_vector_3);
    auto ret_3 = s.rotateRight(test_case_list_node_3, 0);
    assertArray(build_vector(ret_3), test_case_ret_3);
    release_list_node(ret_3);

    auto test_case_vector_4 = vector<int>{1, 2};
    auto test_case_ret_4 = vector<int>{2, 1};
    auto test_case_list_node_4 = build_list_node(test_case_vector_4);
    auto ret_4 = s.rotateRight(test_case_list_node_4, 1);
    assertArray(build_vector(ret_4), test_case_ret_4);
    release_list_node(ret_4);

    auto test_case_vector_5 = vector<int>{1};
    auto test_case_ret_5 = vector<int>{1};
    auto test_case_list_node_5 = build_list_node(test_case_vector_5);
    auto ret_5 = s.rotateRight(test_case_list_node_5, 1);
    assertArray(build_vector(ret_5), test_case_ret_5);
    release_list_node(ret_5);

    return EXIT_SUCCESS;
}
