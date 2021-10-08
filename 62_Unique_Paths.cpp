//
// Created by mincong.he on 2021/9/26.
//

#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;
        for (int i = 1; i < m; ++i) {
            dp[i][0] = 1;
        }
        for (int i = 1; i < n; ++i) {
            dp[0][i] = 1;
            for (int j = 1; j < m; ++j) {
                dp[j][i] = dp[j - 1][i] + dp[j][i - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main(int argc, char **argv) {
    Solution s;
    EXPECT_EQ(s.uniquePaths(3, 7), 28);
    EXPECT_EQ(s.uniquePaths(7, 3), 28);
    EXPECT_EQ(s.uniquePaths(3, 3), 6);
    return EXIT_SUCCESS;
}