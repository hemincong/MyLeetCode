//
// Created by mincong.he on 2020/12/21.
//

#include "AlgoUtils.h"

#include <vector>

using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>> &dungeon) {
        if (dungeon.empty()) return 0;
        auto row = dungeon.size();
        auto col = dungeon[0].size();

        if (row == 1 && col == 1) {
            auto need = 1 - dungeon[0][0];
            return need > 1 ? need : 1;
        }
        vector<vector<int>> dp(row, vector<int>(col, 0));
        auto need_s = 1 - dungeon[row - 1][col - 1];
        if (need_s < 1) need_s = 1;
        dp[row - 1][col - 1] = need_s;

        for (int c = col - 2; c >= 0; --c) {
            auto need = dp[row - 1][c + 1] - dungeon[row - 1][c];
            if (need < 1) need = 1;
            dp[row - 1][c] = need;
        }

        for (int r = row - 2; r >= 0; --r) {
            auto need = dp[r + 1][col - 1] - dungeon[r][col - 1];
            if (need < 1) need = 1;
            dp[r][col - 1] = need;
            for (int c = col - 2; c >= 0; --c) {
                auto right = dp[r][c + 1] - dungeon[r][c];
                if (right < 1) right = 1;
                auto bottom = dp[r + 1][c] - dungeon[r][c];
                if (bottom < 1) bottom = 1;
                dp[r][c] = right < bottom ? right : bottom;
            }
        }

        return dp[0][0];
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<vector<int>> test_case_1{{-2, -3,  3},
                                    {-5, -10, 1},
                                    {10, 30,  -5}};
    EXPECT_EQ(s.calculateMinimumHP(test_case_1), 7);

    vector<vector<int>> test_case_2{{-2}};
    EXPECT_EQ(s.calculateMinimumHP(test_case_2), 3);

    vector<vector<int>> test_case_3{{-2},
                                    {-1},
                                    {3}};
    EXPECT_EQ(s.calculateMinimumHP(test_case_3), 4);

    vector<vector<int>> test_case_4{{-2, -1, 3}};
    EXPECT_EQ(s.calculateMinimumHP(test_case_4), 4);

    vector<vector<int>> test_case_5{{100}};
    EXPECT_EQ(s.calculateMinimumHP(test_case_5), 1);

    vector<vector<int>> test_case_6{{-3, 5}};
    EXPECT_EQ(s.calculateMinimumHP(test_case_6), 4);
    return EXIT_SUCCESS;
}