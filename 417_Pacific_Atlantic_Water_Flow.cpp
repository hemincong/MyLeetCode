#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
        vector<vector<int>> ret;
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> pacific(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            bfs(heights, pacific, m, n, i, 0);
        }
        for (int j = 0; j < n; ++j) {
            bfs(heights, pacific, m, n, 0, j);
        }

        vector<vector<int>> atlantic(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            bfs(heights, atlantic, m, n, i, n - 1);
        }
        for (int j = 0; j < n; ++j) {
            bfs(heights, atlantic, m, n, m - 1, j);
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (pacific[i][j] == 1 && atlantic[i][j] == 1) {
                    ret.push_back({i, j});
                }
            }
        }

        return ret;
    }

private:
    void bfs(const vector<vector<int>> &height, vector<vector<int>> &visited, int m, int n, int x, int y) {
        visited[x][y] = 1;

        for (const auto &[dx, dy]: dest) {
            auto new_x = x + dx;
            auto new_y = y + dy;
            if (new_x >= 0 && new_x < m && new_y >= 0 && new_y < n
                && visited[new_x][new_y] == 0
                && height[new_x][new_y] >= height[x][y]) {
                bfs(height, visited, m, n, new_x, new_y);
            }
        }
    }

    vector<pair<int, int>> dest{
            {0,  1},
            {0,  -1},
            {1,  0},
            {-1, 0},
    };

};

int main(int argc, char **argv) {
    Solution s;
    vector<vector<int>> heights_1{{1, 2, 2, 3, 5},
                                  {3, 2, 3, 4, 4},
                                  {2, 4, 5, 3, 1},
                                  {6, 7, 1, 4, 5},
                                  {5, 1, 1, 2, 4}};
    printMatrix(s.pacificAtlantic(heights_1)); // {{0,4},{1,3},{1,4},{2,2},{3,0},{3,1},{4,0}};

    std::cout << std::endl;
    vector<vector<int>> heights_2{{2, 1},
                                  {1, 2}};
    printMatrix(s.pacificAtlantic(heights_2)); //[[0,0],[0,1],[1,0],[1,1]]


    return EXIT_SUCCESS;
}