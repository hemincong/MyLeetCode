//
// Created by mincong.he on 2022/1/29.
//

#include <vector>
#include <queue>
#include "AlgoUtils.h"

using namespace std;


class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>> &isWater) {
        auto m = isWater.size();
        auto n = isWater[0].size();
        vector<vector<int>> visited(m, vector<int>(n, -1));
        queue<pair<int, int>> q;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isWater[i][j] != 0) {
                    visited[i][j] = 0;
                    q.emplace(make_pair(i, j));
                }
            }
        }

        while (!q.empty()) {
            auto &pos = q.front();
            for (auto d: dirs) {
                int x = pos.first + d[0];
                int y = pos.second + d[1];
                if (x >= 0 && x < m && y >= 0 && y < n && visited[x][y] == -1) {
                    visited[x][y] = visited[pos.first][pos.second] + 1;
                    q.emplace(make_pair(x, y));
                }
            }
            q.pop();
        }

        return visited;
    }

    int dirs[4][2] = {
            {0,  -1},
            {1,  0},
            {0,  1},
            {-1, 0},
    };
};

int main(int argc, char **argv) {
    Solution s;
    std::vector<std::vector<int>> w1{{0, 0, 1},
                                     {1, 0, 0},
                                     {0, 0, 0}};
    printMatrix(s.highestPeak(w1));
    std::vector<std::vector<int>> w2{{0, 1},
                                     {0, 0}};
    printMatrix(s.highestPeak(w2));
    return EXIT_SUCCESS;
}