//
// Created by mincong.he on 2020/12/21.
//
#include "AlgoUtils.h"

#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>> &grid) {
        if (grid.empty()) return 0;
        auto row = grid.size();
        auto col = grid[0].size();
        if (row == 1 && col == 1) return grid[0][0];

        vector<vector<int>> dp(row, vector<int>(col, 0));
        dp[0][0] = grid[0][0];
        // 第一行
        for (int i = 1; i < col; ++i) {
            dp[0][i] = grid[0][i] + dp[0][i - 1];
        }
        for (int i = 1; i < row; ++i) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
            for (int j = 1; j < col; ++j) {
                auto top = dp[i - 1][j];
                auto left = dp[i][j - 1];
                dp[i][j] = (top < left ? top : left) + grid[i][j];
            }
        }

        return dp[row - 1][col - 1];
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<vector<int>> test_case_1{{1, 3, 1},
                                    {1, 5, 1},
                                    {4, 2, 1}};
    EXPECT_EQ(s.minPathSum(test_case_1), 7);

    vector<vector<int>> test_case_2{{1, 2, 3},
                                    {4, 5, 6}};
    EXPECT_EQ(s.minPathSum(test_case_2), 12);

    vector<vector<int>> test_case_3{{1, 2},
                                    {1, 1}};
    EXPECT_EQ(s.minPathSum(test_case_3), 3);
    return EXIT_SUCCESS;
}