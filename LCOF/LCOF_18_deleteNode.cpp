#include <vector>
#include "AlgoUtils.h"

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteNode(ListNode *head, int val) {
        ListNode *temp = new ListNode();
        ListNode *p = head;
        ListNode *pre = temp;
        while (p) {
            if (p->val != val) {
                pre->next = p;
                pre = pre->next;
            } else {
                pre->next = nullptr;
            }
            p = p->next;
        }
        return temp->next;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> test_case_1{4, 5, 1, 9};
    vector<int> ret_1{4, 1, 9}; // 5
    vector<int> ret_2{4, 5, 9}; // 1
    vector<int> test_case_2{-3, 5, -99};
    vector<int> ret_3{-3, 5}; // -99
    assertArray(build_vector(s.deleteNode(build_list_node(test_case_1), 5)), ret_1);
    assertArray(build_vector(s.deleteNode(build_list_node(test_case_1), 1)), ret_2);
    assertArray(build_vector(s.deleteNode(build_list_node(test_case_2), -99)), ret_3);
    return EXIT_SUCCESS;
}