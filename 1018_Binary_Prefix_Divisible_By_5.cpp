//
// Created by mincong.he on 2021/1/14.
//

#include "AlgoUtils.h"

#include <vector>

using namespace std;

class Solution_1 {
public:
    vector<bool> prefixesDivBy5(vector<int> &A) {
        vector<bool> res;
        int num = 0;
        for (const auto &temp : A) {
            num = (num * 2 + temp) % 5;
            if (num == 0)
                res.push_back(true);
            else
                res.push_back(false);
        }
        return (res);
    }
};

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int> &A) {
        vector<bool> ret;
        if (A.empty()) return ret;

        int num = 0;
        for (int i : A) {
            num = ((2 * num) + i) % 5;
            if (num == 0) {
                ret.push_back(true);
            } else {
                ret.push_back(false);
            }
        }

        return ret;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> test_case_1{0, 1, 1};
    vector<bool> test_case_1_ret{true, false, false};
    EXPECT_TRUE(assertArray(s.prefixesDivBy5(test_case_1), test_case_1_ret));

    vector<int> test_case_2{1, 1, 1};
    vector<bool> test_case_2_ret{false, false, false};
    EXPECT_TRUE(assertArray(s.prefixesDivBy5(test_case_2), test_case_2_ret));

    vector<int> test_case_3{0, 1, 1, 1, 1, 1};
    vector<bool> test_case_3_ret{true, false, false, false, true, false};
    EXPECT_TRUE(assertArray(s.prefixesDivBy5(test_case_3), test_case_3_ret));

    vector<int> test_case_4{1, 1, 1, 0, 1};
    vector<bool> test_case_4_ret{false, false, false, false, false};
    EXPECT_TRUE(assertArray(s.prefixesDivBy5(test_case_4), test_case_4_ret));

    vector<int> test_case_5{1, 1, 0, 0, 0, 1, 0, 0, 1};
    vector<bool> test_case_5_ret{false, false, false, false, false, false, false, false, false};
    EXPECT_TRUE(assertArray(s.prefixesDivBy5(test_case_5), test_case_5_ret));

    vector<int> test_case_6{1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 0};
    vector<bool> test_case_6_ret{false, false, false, false, false, true, false, false, false, true, false, false, true,
                                 false, false, false, false, true, true};
    EXPECT_TRUE(assertArray(s.prefixesDivBy5(test_case_6), test_case_6_ret));

    vector<int> test_case_7{1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1,
                            0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0,
                            1, 1, 1, 0, 0, 1, 0};
    vector<bool> test_case_7_ret{false, false, true, false, false, false, false, false, false, false, true, true, true,
                                 true, true, true, false, false, false, false, false, false, false, false, false, false,
                                 false, false, false, false, false, false, false, false, false, false, false, false,
                                 false, false, false, false, false, true, false, false, false, true, false, false, true,
                                 false, false, true, true, true, true, true, true, true, false, false, true, false,
                                 false, false, false, true, true};
    EXPECT_TRUE(assertArray(s.prefixesDivBy5(test_case_7), test_case_7_ret));
    return EXIT_SUCCESS;
}