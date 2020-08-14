//
// Created by mincong.he on 2020/8/14.
//

#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s.empty()) return true;

        std::stack<char> p;

        for (const auto &c: s) {
            if (c == '(' || c == '{' || c == '[') {
                p.push(c);
                continue;
            }

            if (p.empty()) return false;

            auto temp_c = p.top();
            p.pop();
            if (temp_c == '(' && c == ')' ||
                temp_c == '[' && c == ']' ||
                temp_c == '{' && c == '}') {
                continue;
            } else {
                return false;
            }
        }
        return p.empty();
    }
};

int main(int argc, char **argv) {
    Solution s;
    assert(s.isValid("()"));
    assert(s.isValid("()[]{}"));
    assert(!s.isValid("(]"));
    assert(!s.isValid("("));
    assert(!s.isValid("]"));
    assert(s.isValid(""));

    return EXIT_SUCCESS;
}