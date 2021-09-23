//
// Created by mincong.he on 2021/9/22.
//
#include <vector>
#include "AlgoUtils.h"

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<ListNode *> splitListToParts(ListNode *head, int k) {
        vector<ListNode *> ret;
        ListNode *p = head;
        size_t length = 0;
        while (p) {
            length++;
            p = p->next;
        }
        int m = length / k;
        int n = length % k;
        p = head;
        ListNode *pre = nullptr;

        int curr_count = 0;
        while (p) {
            ret.push_back(p);

            while (p && curr_count < m) {
                pre = p;
                p = p->next;
                curr_count++;
            }
            curr_count = 0;
            if (p && n > 0) {
                pre = p;
                p = p->next;
                n--;
            }
            pre->next = nullptr;
            k--;
        }
        while (k > 0) {
            ret.push_back(nullptr);
            k--;
        }
        return ret;
    }
};

void p_list_node_vector(const vector<ListNode *> &r) {
    for (auto h: r) {
        auto p = h;
        std::cout << "[ ";
        while (p) {
            std::cout << p->val << " ";
            p = p->next;
        }
        std::cout << "]" << std::endl;
    }
    std::cout << std::endl;
}

int main(int argc, char **argv) {
    Solution s;
    vector<int> test_case_1{1, 2, 3};
    auto test_case_1_h = build_list_node(test_case_1);
    auto ret_1 = s.splitListToParts(test_case_1_h, 5);
    p_list_node_vector(ret_1);
    release_list_node(test_case_1_h);

    vector<int> test_case_2{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto test_case_2_h = build_list_node(test_case_2);
    auto ret_2 = s.splitListToParts(test_case_2_h, 3);
    p_list_node_vector(ret_2);
    release_list_node(test_case_2_h);

    vector<int> test_case_3{1, 2, 3, 4};
    auto test_case_3_h = build_list_node(test_case_3);
    auto ret_3 = s.splitListToParts(test_case_3_h, 5);
    p_list_node_vector(ret_3);
    release_list_node(test_case_3_h);

    return EXIT_SUCCESS;
}