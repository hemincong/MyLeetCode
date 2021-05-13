//
// Created by mincong.he on 2021/5/13.
//

#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int numWays(int steps, int arrLen) {
        int max_col = min(arrLen - 1, steps);
        vector<vector<int>> dp(steps + 1, vector<int>(max_col + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= steps; i++) {
            for (int j = 0; j <= max_col; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j - 1 >= 0) dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MODULO;
                if (j + 1 <= arrLen) dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MODULO;
            }
        }
        return dp[steps][0];
    }

private:
    static const int MODULO = 1e9 + 7;
};

int main(int argc, char **argv) {
    Solution s;
    EXPECT_EQ(s.numWays(3, 2), 4);
    EXPECT_EQ(s.numWays(2, 4), 2);
    EXPECT_EQ(s.numWays(4, 2), 8);
    return EXIT_SUCCESS;
}