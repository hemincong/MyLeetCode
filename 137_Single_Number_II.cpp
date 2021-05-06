//
// Created by mincong.he on 2021/4/30.
//

#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0;
        int b = 0;
        for (auto n : nums) {
            b = ~a & (b ^ n);
            a = ~b & (a ^ n);
        }
        return b;
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<int> test_case_1{2, 2, 3, 2};
    EXPECT_EQ(s.singleNumber(test_case_1), 3)
    vector<int> test_case_2{0, 1, 0, 1, 0, 1, 99};
    EXPECT_EQ(s.singleNumber(test_case_2), 99)
}