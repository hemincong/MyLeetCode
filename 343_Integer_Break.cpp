#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 0);
        for (int i = 2; i <= n; ++i) {
            auto curr_max = 0;
            for (int j = 1; j < i; ++j) {
                curr_max = max(curr_max, max(dp[i - j] * j, (i - j) * j));
            }
            dp[i] = curr_max;
        }
        return dp[n];
    }
};

int main(int argc, char **argv) {
    Solution s;
    EXPECT_EQ(s.integerBreak(2), 1);
    EXPECT_EQ(s.integerBreak(10), 36);
    //EXPECT_EQ(s.integerBreak(120), 2136675824);
    return EXIT_SUCCESS;
}