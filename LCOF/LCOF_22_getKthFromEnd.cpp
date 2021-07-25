//
// Created by mincong.he on 2021/7/20.
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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        int count = 0;
        ListNode * head_p = head;
        ListNode * tail_p = head;
        while (count < k && tail_p) {
            tail_p = tail_p->next;
            count++;
        }
        if (count < k) return NULL;
        while (tail_p) {
            tail_p = tail_p->next;
            head_p = head_p->next;
        }
        return head_p;
    }
};