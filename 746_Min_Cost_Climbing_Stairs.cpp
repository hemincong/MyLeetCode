#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int> &cost) {
        auto n = cost.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 0;
        for (int i = 2; i <= n; ++i) {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        return dp[n];
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> test_case_1{10, 15, 20};
    EXPECT_EQ(s.minCostClimbingStairs(test_case_1), 15);
    vector<int> test_case_2{1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    EXPECT_EQ(s.minCostClimbingStairs(test_case_2), 6);
    return EXIT_SUCCESS;
}