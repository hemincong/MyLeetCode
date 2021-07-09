//
// Created by mincong.he on 2021/7/4.
//

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
    vector<int> reversePrint(ListNode* head) {
        auto count = 0;
        auto p = head;
        while (p) {
            count++;
            p = p->next;
        }
        vector<int> ret(count, 0);
        p = head;
        for (auto i = ret.rbegin(); i != ret.rend(); i++) {
            *i = p->val;
            p = p->next;
        }
        return ret;
    }
};