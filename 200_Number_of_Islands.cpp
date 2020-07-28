//
// Created by mincong.he on 2020/7/27.
//

#include <vector>
#include <queue>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        if (grid.empty()) return 0;
        int ret = 0;
        vector<vector<int>> mark(grid.size(), vector<int>(grid[0].size(), 0));

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (mark[i][j] == 0 && grid[i][j] == '1') {
                    BFS(mark, grid, i, j);
                    ret++;
                }
            }
        }

        return ret;
    }

private:
    static const int constexpr dx[4] = {-1, 1, 0, 0};
    static const int constexpr dy[4] = {0, 0, -1, 1};

    void DFS(vector<vector<int>> &mark, const vector<vector<char>> &grid, int x, int y) {
        mark[x][y] = 1;
        for (int i = 0; i < 4; i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if (new_x < 0 || new_x >= grid.size() || new_y < 0 || new_y >= grid[0].size()) continue;
            if (mark[new_x][new_y] == 0 && grid[new_x][new_y] == '1') {
                DFS(mark, grid, new_x, new_y);
            }
        }
    }

    void BFS(vector<vector<int>> &mark, const vector<vector<char>> &grid, int x, int y) {
        mark[x][y] = 1;
        queue<pair<int, int>> pos_queue;
        pos_queue.push(make_pair(x, y));
        while (!pos_queue.empty()) {
            int x_top = pos_queue.front().first;
            int y_top = pos_queue.front().second;
            pos_queue.pop();
            for (int i = 0; i < 4; i++) {
                int new_x = x_top + dx[i];
                int new_y = y_top + dy[i];
                if (new_x < 0 || new_x >= grid.size() || new_y < 0 || new_y >= grid[0].size()) continue;
                if (mark[new_x][new_y] == 0 && grid[new_x][new_y] == '1') {
                    pos_queue.push(std::make_pair(new_x, new_y));
                    mark[new_x][new_y] = 1;
                }
            }
        }
    }
};

int main(int argc, char **argv) {
    vector<vector<char>> grid_1{
            {'1', '1', '1', '1', '0'},
            {'1', '1', '0', '1', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '0', '0', '0'}
    };
    vector<vector<char>> grid_2{
            {'1', '1', '0', '0', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '1', '0', '0'},
            {'0', '0', '0', '1', '1'}
    };

    Solution s;
    EXPECT_EQ(s.numIslands(grid_1), 1);
    EXPECT_EQ(s.numIslands(grid_2), 3);
    return EXIT_SUCCESS;
}