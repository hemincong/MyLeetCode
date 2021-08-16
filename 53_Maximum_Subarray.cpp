//
// Created by mincong.he on 2020/12/14.
//

#include "AlgoUtils.h"

#include <vector>

using namespace std;

class Solution_1 {
public:
    int maxSubArray(vector<int> &nums) {
        if (nums.size() == 1) return nums.at(0);
        vector<int> curr_max(nums.size(), 0);
        curr_max[0] = nums.at(0);
        int max = curr_max[0];
        for (int i = 1; i < nums.size(); ++i) {
            auto curr = nums.at(i);
            auto curr_total = curr + curr_max.at(i - 1);
            curr_max.at(i) = curr_total > curr ? curr_total : curr;
            if (curr_max.at(i) > max) {
                max = curr_max.at(i);
            }
        }
        return max;
    }
};

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        auto n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
        }
        return *max_element(dp.begin(), dp.end());
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> case_1{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    EXPECT_EQ(s.maxSubArray(case_1), 6);

    vector<int> case_2{1};
    EXPECT_EQ(s.maxSubArray(case_2), 1);

    vector<int> case_3{0};
    EXPECT_EQ(s.maxSubArray(case_3), 0);

    vector<int> case_4{-1};
    EXPECT_EQ(s.maxSubArray(case_4), -1);

    vector<int> case_5{-2147483647};
    EXPECT_EQ(s.maxSubArray(case_5), -2147483647);

    vector<int> case_6{-2, -1};
    EXPECT_EQ(s.maxSubArray(case_6), -1);

    vector<int> case_7{-1, -2};
    EXPECT_EQ(s.maxSubArray(case_7), -1);

    return EXIT_SUCCESS;
}