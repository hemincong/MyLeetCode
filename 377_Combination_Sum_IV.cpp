//
// Created by mincong.he on 2021/4/24.
//

#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int> &nums, int target) {
        vector<size_t> dp(target + 1, 0);
        int n = nums.size();
        dp[0] = 1;

        for (int i = 0; i <= target; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i >= nums[j]) {
                    dp[i] += dp[i - nums[j]];
                }
            }
        }
        return dp[target];
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> test_case_1{1, 2, 3};
    EXPECT_EQ(s.combinationSum4(test_case_1, 4), 7);
    vector<int> test_case_2{9};
    EXPECT_EQ(s.combinationSum4(test_case_2, 3), 0);
    return EXIT_SUCCESS;
}
