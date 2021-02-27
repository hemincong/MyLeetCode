//
// Created by mincong.he on 2021/2/28.
//

#include "AlgoUtils.h"
#include <vector>

using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int> &A) {
        bool is_greater = false;
        bool is_less = false;
        for (int i = 0; i < A.size() - 1; ++i) {
            if (A[i] > A[i + 1]) is_greater = true;
            if (A[i] < A[i + 1]) is_less = true;

            if (is_greater && is_less) return false;
        }
        return true;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> test_case_1{1, 2, 2, 3};
    EXPECT_TRUE(s.isMonotonic(test_case_1));

    vector<int> test_case_2{6, 5, 4, 4};
    EXPECT_TRUE(s.isMonotonic(test_case_2));

    vector<int> test_case_3{1, 3, 2};
    EXPECT_FALSE(s.isMonotonic(test_case_3));

    vector<int> test_case_4{1, 2, 4, 5};
    EXPECT_TRUE(s.isMonotonic(test_case_4));

    vector<int> test_case_5{1, 1, 1};
    EXPECT_TRUE(s.isMonotonic(test_case_5));

    return EXIT_SUCCESS;
}