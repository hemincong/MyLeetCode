//
// Created by mincong.he on 2022/2/27.
//

#include <string>
#include <vector>
#include "AlgoUtils.h"
#include <sstream>

using namespace std;

class Solution {
public:
    string optimalDivision(vector<int> &nums) {
        int n = nums.size();
        stringstream ss;
        ss << nums[0];
        if (n > 1) ss << "/";
        if (n > 2) ss << "(";
        for (int i = 1; i < n - 1; ++i) {
            ss << nums[i] << "/";
        }
        if (n > 1) ss << nums[n - 1];
        if (n > 2) ss << ")";
        return ss.str();
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> test_case_1{1000, 100, 10, 2};
    EXPECT_EQ(s.optimalDivision(test_case_1), string("1000/(100/10/2)"));

    vector<int> test_case_2{2, 3, 4};
    EXPECT_EQ(s.optimalDivision(test_case_2), string("2/(3/4)"));

    vector<int> test_case_3{2};
    EXPECT_EQ(s.optimalDivision(test_case_3), string("2"));


}