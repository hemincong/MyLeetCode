//
// Created by mincong.he on 2019/9/19.
//

#include <stack>
#include <iostream>
#include "AlgoUtils.h"

using namespace std;

class Solution {
    enum STATUS {
        STATUS_BEGIN,
        STATUS_NUM,
        STATUS_OPT,
    };

public:

    Solution() :
            _status(STATUS_BEGIN),
            _num_curr(0),
            _need_more_num(false) {

    }

    void clear() {
        _status = STATUS_BEGIN;
        _num_curr = 0;
        while (!_num_s.empty()) _num_s.pop();
        while (!_opt_s.empty()) _opt_s.pop();
        _need_more_num = false;
    }

    int calculate(std::string s) {
        _status = STATUS_BEGIN;
        auto s_len = s.length();
        int i = 0;
        _num_curr = 0;
        while (i < s_len) {
            auto c_curr = s[i];
            if (c_curr == ' ') {
                i++;
                continue;
            }

            switch (_status) {
                case STATUS_BEGIN:
                    if (c_curr >= '0' && c_curr <= '9') {
                        _num_curr = c_curr - '0';
                        _status = STATUS_NUM;
                    } else {
                        _status = STATUS_OPT;
                    }
                    break;
                case STATUS_NUM:
                    if (c_curr >= '0' && c_curr <= '9') {
                        _num_curr = _num_curr * 10 + (c_curr - '0');
                    } else {
                        _num_s.push(_num_curr);
                        _num_curr = 0;
                        _status = STATUS_OPT;

                        if (_need_more_num) {
                            compute();
                        }

                        if (c_curr == '(') {
                            _need_more_num = false;
                        } else if (c_curr == ')') {
                            compute();
                        } else {
                            _opt_s.push(c_curr);
                            _need_more_num = true;
                        }
                    }
                    break;
                case STATUS_OPT:
                    // 连续的)
                    if (c_curr == ')') {
                        compute();
                        // 必定跟操作符
                    } else if (c_curr == '(') {
                        _need_more_num = false;
                        _status = STATUS_NUM;
                    } else if (c_curr == '+' || c_curr == '-') {
                        _need_more_num = true;
                        _opt_s.push(c_curr);
                    } else if (c_curr >= '0' && c_curr <= '9') {
                        _num_curr = _num_curr * 10 + (c_curr - '0');
                        _status = STATUS_NUM;
                    }
                    break;
            }
            ++i;

            std::cout << "num: " << _num_s << std::endl;
            std::cout << "opt: " << _opt_s << std::endl;
            std::cout << "c_curr: " << c_curr << std::endl;
            std::cout << std::endl;
        }
        // 以数字结尾, 补最后一个数字
        if (s_len > 0 && _status == STATUS_NUM) {
            _num_s.push(_num_curr);
            compute();
        }
        if (_num_curr == 0 && _num_s.empty()) return 0;
        return _num_s.top();
    }

private:

    void compute() {
        if (_num_s.size() < 2) return;

        auto num2 = _num_s.top();
        _num_s.pop();
        auto num1 = _num_s.top();
        _num_s.pop();
        auto opt = _opt_s.top();
        _opt_s.pop();

        auto ret = 0;
        switch (opt) {
            case '+':
                ret = num1 + num2;
                break;
            case '-':
                ret = num1 - num2;
                break;
            default:
                break;
        }
        _num_s.push(ret);
    }

    STATUS _status;
    int _num_curr{};
    stack<int> _num_s;
    stack<char> _opt_s;
    bool _need_more_num{};
};

int main(int argc, char **argv) {
    Solution solution;
    auto ret = solution.calculate(
            "1-(3+5-2+(3+19-(3-1-4+(9-4-(4-(1+(3)-2)-5)+8-(3-5)-1)-4)-5)-4+3-9)-4-(3+2-5)-10"); // -15
    assert(ret == -15);
    solution.clear();
    ret = solution.calculate("1+1"); // 2
    assert(ret == 2);
    solution.clear();
    ret = solution.calculate("(1+1)"); // 2
    assert(ret == 2);
    solution.clear();
    ret = solution.calculate("  2-1 + 2 "); // 3
    assert(ret == 3);
    solution.clear();
    ret = solution.calculate("(1+(4+5+2)-3)+(6+8)"); // 23
    assert(ret == 23);
    solution.clear();
    return EXIT_SUCCESS;
}
