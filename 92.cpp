#include <string>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

/*
 * Definition for singly-linked list.
 */

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
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

        ListNode * ret = h->next;
        if (h) delete(h);
        return ret;
    }
};

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

int stringToInteger(string input) {
    return stoi(input);
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
    string line(argv[1]);
    string m_s(argv[2]);
    string n_s(argv[3]);
    //while (getline(cin, line)) {
    ListNode *head = stringToListNode(line);
    int m = stringToInteger(m_s);
    int n = stringToInteger(n_s);

    ListNode *ret = Solution().reverseBetween(head, m, n);

    string out = listNodeToString(ret);
    cout << out << endl;
    //}
    return 0;
}