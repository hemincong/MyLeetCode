#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));
        // 0: 卖
        dp[0][0] = 0;
        // 1: 买
        dp[0][1] = -prices[0];
        for (int i = 1; i < n; ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }

        return dp[n - 1][0];
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> test_case_1{7, 1, 5, 3, 6, 4};
    vector<int> test_case_2{1, 2, 3, 4, 5};
    vector<int> test_case_3{7, 6, 4, 3, 1};
    EXPECT_EQ(s.maxProfit(test_case_1), 7);
    EXPECT_EQ(s.maxProfit(test_case_2), 4);
    EXPECT_EQ(s.maxProfit(test_case_3), 0);
    return EXIT_SUCCESS;
}