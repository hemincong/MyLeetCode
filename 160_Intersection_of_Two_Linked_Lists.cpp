//
// Created by mincong.he on 2019-09-06.
//
/**
 * Definition for singly-linked list.
 **/

#include <string>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

int get_list_len(const ListNode *l) {
    auto p = l;
    int count = 0;
    while (p) {
        count++;
        p = p->next;
    }
    return count;
}

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto a_len = get_list_len(headA);
        auto b_len = get_list_len(headB);

        if (a_len == 0 || b_len == 0) return NULL;
        ListNode *p_b = NULL;
        ListNode *p_a = NULL;
        ListNode *p_tmp_1 = NULL;
        ListNode *p_tmp_2 = NULL;
        // 尾端对齐
        if (a_len > b_len) {
            p_tmp_1 = headA;
            for (int i = 0; i < a_len - b_len; i++) {
                p_tmp_1 = p_tmp_1->next;
            }
            p_tmp_2 = headB;
        } else {
            p_tmp_1 = headA;
            p_tmp_2 = headB;
            for (int i = 0; i < b_len - a_len; i++) {
                p_tmp_2 = p_tmp_2->next;
            }
        }

        // 找到从能对齐的开始找到共同开始的地方
        while (p_tmp_1 != p_tmp_2 && p_tmp_1 && p_tmp_2) {
            p_tmp_1 = p_tmp_1->next;
            p_tmp_2 = p_tmp_2->next;
        }
        if (p_tmp_1 == p_tmp_2) {
            return p_tmp_1;
        }
        return NULL;
    }
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p_a = headA;
        ListNode *p_b = headB;
        int len_a = 0;
        int len_b = 0;
        while (p_a) {
            len_a++;
            p_a = p_a->next;
        }
        while (p_b) {
            len_b++;
            p_b = p_b->next;
        }
        p_a = headA;
        p_b = headB;
        int delta = abs(len_b - len_a);
        while (len_b > len_a && delta > 0) {
            p_b = p_b->next;
            delta--;
        }
        while (len_b < len_a && delta > 0) {
            p_a = p_a->next;
            delta--;
        }
        while (p_a && p_b) {
            if (p_a == p_b) return p_a;
            p_a = p_a->next;
            p_b = p_b->next;
        }
        return NULL;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

ListNode *stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);


    // Now convert that list into linked list
    ListNode *dummyRoot = new ListNode(0);
    ListNode *ptr = dummyRoot;

    for (int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

string listNodeToString(ListNode *node) {
    if (node == nullptr) {
        return "[]";
    }

    string result;
    while (node) {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main(int argc, char **argv) {
    ListNode a1(1);
    ListNode a2(2);
    ListNode b1(3);
    ListNode b2(4);
    ListNode b3(5);
    ListNode c1(6);
    ListNode c2(7);
    ListNode c3(8);
    a1.next = &a2;
    a2.next = &c1;
    c1.next = &c2;
    c2.next = &c3;
    b1.next = &b2;
    b2.next = &b3;
    b3.next = &c1;

    ListNode *ret = Solution().getIntersectionNode(&a1, &b1);

    string out = listNodeToString(ret);
    cout << out << endl;
    return 0;
}