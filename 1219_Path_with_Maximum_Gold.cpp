//
// Created by mincong.he on 2022/2/5.
//

#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int getMaximumGold(vector<vector<int>> &grid) {
        auto m = grid.size();
        auto n = grid[0].size();
        auto max_gold = 0;
        vector<vector<int>> visited(m, vector<int>(n, 0));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) continue;
                auto p_gold = search(grid[i][j], i, j, grid, visited, m, n);
                visited[i][j] = 0;
                if (p_gold > max_gold) {
                    max_gold = p_gold;
                }
            }
        }
        return max_gold;
    }

private:
    int search(int curr_gold,
               int pos_x, int pos_y,
               const vector<vector<int>> &grid,
               vector<vector<int>> &visited,
               int m, int n) {
        int curr_max = curr_gold;
        if (grid[pos_x][pos_y] == 0) return curr_max;
        visited[pos_x][pos_y] = 1;
        for (const auto &d: dirt) {
            auto x = pos_x + d[0];
            auto y = pos_y + d[1];
            if (x >= 0 && x < m && y >= 0 && y < n && visited[x][y] != 1) {
                auto p_gold = search(curr_gold + grid[x][y], x, y, grid, visited, m, n);
                if (p_gold > curr_max) {
                    curr_max = p_gold;
                }
                visited[x][y] = 0;
            }
        }
        return curr_max;
    }

    const vector<vector<int>> dirt = {
            {0,  1},
            {0,  -1},
            {-1, 0},
            {1,  0}
    };
};

int main(int argc, char **argv) {
    Solution s;
    vector<vector<int>> test_case_1{{0, 6, 0},
                                    {5, 8, 7},
                                    {0, 9, 0}};
    EXPECT_EQ(s.getMaximumGold(test_case_1), 24)
    vector<vector<int>> test_case_2{{1, 0, 7},
                                    {2, 0, 6},
                                    {3, 4, 5},
                                    {0, 3, 0},
                                    {9, 0, 20}};
    EXPECT_EQ(s.getMaximumGold(test_case_2), 28)
    vector<vector<int>> test_case_3{{5,  3,  36, 26, 27},
                                    {11, 31, 23, 30, 4},
                                    {5,  7,  21, 38, 10},
                                    {39, 30, 10, 17, 13},
                                    {16, 0,  0,  26, 1},
                                    {25, 0,  10, 0,  0}};
    EXPECT_EQ(s.getMaximumGold(test_case_3), 454)
    return EXIT_SUCCESS;
}