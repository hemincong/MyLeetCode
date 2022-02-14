//
// Created by mincong.he on 2022/2/13.
//

#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int numEnclaves(vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> _visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            // 第一列
            dfs(grid, i, 0, m, n, _visited);
            // 最后一列
            dfs(grid, i, n - 1, m, n, _visited);
        }
        for (int i = 1; i < n - 1; ++i) {
            // 第一行
            dfs(grid, 0, i, m, n, _visited);
            // 最后一行
            dfs(grid, m - 1, i, m, n, _visited);
        }

        int envlaves = 0;
        for (int i = 1; i < m - 1; ++i) {
            for (int j = 1; j < n - 1; ++j) {
                if (grid[i][j] == 1 && !_visited[i][j]) {
                    envlaves++;
                }
            }
        }
        return envlaves;
    }

    void dfs(const vector<vector<int>> &grid, int x, int y, int m, int n, vector<vector<bool>> &visited) {
        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0 || visited[x][y]) {
            return;
        }
        visited[x][y] = true;
        for (auto &d: dirs) {
            dfs(grid, x + d[0], y + d[1], m, n, visited);
        }
    }

private:
    vector<vector<int>> dirs = {
            {-1, 0},
            {1, 0},
            {0, -1},
            {0, 1},
    };
};


int main(int argc, char **argv) {
    Solution s;
//    vector<vector<int>> grid_1{{0, 0, 0, 0},
//                               {1, 0, 1, 0},
//                               {0, 1, 1, 0},
//                               {0, 0, 0, 0}};
//    EXPECT_EQ(s.numEnclaves(grid_1), 3);
//    vector<vector<int>> grid_2{{0, 1, 1, 0},
//                               {0, 0, 1, 0},
//                               {0, 0, 1, 0},
//                               {0, 0, 0, 0}};
//    EXPECT_EQ(s.numEnclaves(grid_2), 0);
    vector<vector<int>> grid_3{{0},
                               {1},
                               {1},
                               {0},
                               {0}};
    EXPECT_EQ(s.numEnclaves(grid_3), 0);
    return EXIT_SUCCESS;
}