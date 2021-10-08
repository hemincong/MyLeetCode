#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        if (obstacleGrid[0][0] == 1) return 0;
        auto m = obstacleGrid.size();
        auto n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;

        for (int i = 1; i < m; ++i) {
            if (obstacleGrid[i][0] == 1) break;
            dp[i][0] = dp[i - 1][0];
        }
        for (int i = 1; i < n; ++i) {
            if (obstacleGrid[0][i] == 1) break;
            dp[0][i] = dp[0][i - 1];
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) continue;
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<vector<int>> test_case_1{{0, 0, 0},
                                    {0, 1, 0},
                                    {0, 0, 0}};
    EXPECT_EQ(s.uniquePathsWithObstacles(test_case_1), 2);

    vector<vector<int>> test_case_2{{0, 1},
                                    {0, 0}};
    EXPECT_EQ(s.uniquePathsWithObstacles(test_case_2), 1);

    vector<vector<int>> test_case_3{{0, 0},
                                    {0, 1}};
    EXPECT_EQ(s.uniquePathsWithObstacles(test_case_3), 0);

    vector<vector<int>> test_case_4{{1}};
    EXPECT_EQ(s.uniquePathsWithObstacles(test_case_4), 0);

    vector<vector<int>> test_case_5{{1, 0},
                                    {0, 0}};
    EXPECT_EQ(s.uniquePathsWithObstacles(test_case_5), 0);

    vector<vector<int>> test_case_6{{0, 1}};
    EXPECT_EQ(s.uniquePathsWithObstacles(test_case_6), 0);

    vector<vector<int>> test_case_7{{0, 0},
                                    {1, 0}};
    EXPECT_EQ(s.uniquePathsWithObstacles(test_case_7), 1);
    return EXIT_SUCCESS;
}