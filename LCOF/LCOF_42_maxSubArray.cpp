#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        int max_total = dp[0];
        for (int i = 1; i < n; ++i) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            max_total = max(dp[i], max_total);
        }
        return max_total;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> test_case_1{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    EXPECT_EQ(s.maxSubArray(test_case_1), 6);
    return EXIT_SUCCESS;
}