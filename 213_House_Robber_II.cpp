//
// Created by mincong.he on 2021/4/15.
//
#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int rob(vector<int> &nums) {
        if (nums.empty()) return 0;
        auto n = nums.size();
        if (n == 1) return nums[0];
        vector<int> dp(n, 0);

        // 选第一个
        dp[0] = nums[0];
        dp[1] = dp[0];
        for (int i = 2; i < n - 1; ++i) {
            auto tmp = dp[i - 2] + nums[i];
            dp[i] = dp[i - 1] > tmp ? dp[i - 1] : tmp;
        }
        int max_dp_1 = dp[n - 2];

        // 不选第一个
        dp[0] = 0;
        dp[1] = nums[1];
        for (int i = 2; i < n; ++i) {
            auto tmp = dp[i - 2] + nums[i];
            dp[i] = dp[i - 1] > tmp ? dp[i - 1] : tmp;
        }
        int max_dp_2 = dp[n - 1];

        return max_dp_1 > max_dp_2 ? max_dp_1 : max_dp_2;
    }
};


int main(int argc, char **argv) {
    Solution s;
    vector<int> test_case_1{2, 3, 2};
    EXPECT_EQ(s.rob(test_case_1), 3);
    vector<int> test_case_2{1, 2, 3, 1};
    EXPECT_EQ(s.rob(test_case_2), 4);

    return EXIT_SUCCESS;
}