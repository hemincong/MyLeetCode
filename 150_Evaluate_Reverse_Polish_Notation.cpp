//
// Created by mincong.he on 2021/3/20.
//

#include <string>
#include <stack>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> nums;

        for (const auto &t: tokens) {
            const auto first_char = t[0];
            if (first_char == '+'
                || first_char == '-'
                || first_char == '*'
                || first_char == '/') {

                if (first_char == '-' && t.length() > 1) {
                    auto n = std::stoi(t);
                    nums.push(n);
                    continue;
                }

                auto num2 = nums.top();
                nums.pop();
                auto num1 = nums.top();
                nums.pop();
                auto ret_opt = calc(first_char, num1, num2);
                nums.push(ret_opt);
            } else {
                auto n = std::stoi(t);
                nums.push(n);
            }
        }
        auto ret = nums.top();
        return ret;

    }

private:
    static int calc(const char op, int num1, int num2) {
        switch (op) {
            case '+':
                return num1 + num2;
            case '-':
                return num1 - num2;
            case '*':
                return num1 * num2;
            case '/':
                return num1 / num2;
            default:
                return 0;
        }
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<string> test_case_1{"2", "1", "+", "3", "*"};
    EXPECT_EQ(s.evalRPN(test_case_1), 9);

    vector<string> test_case_2{"4", "13", "5", "/", "+"};
    EXPECT_EQ(s.evalRPN(test_case_2), 6);

    vector<string> test_case_3{"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    EXPECT_EQ(s.evalRPN(test_case_3), 22);

    return EXIT_SUCCESS;
}