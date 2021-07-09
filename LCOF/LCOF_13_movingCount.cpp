//
// Created by mincong.he on 2021/7/3.
//

#include "../AlgoUtils.h"

#include <vector>

using namespace std;


class Solution {
public:
    int movingCount(int m, int n, int k) {
        vector<vector<int>> visited = vector<vector<int>>(m, vector<int>(n, 0));
        return dfs(0, 0, m, n, k, visited);
    }

    int dfs(int i, int j, int m, int n, int k, vector<vector<int>> &visited) {
        if (i < 0 || i >= m || j < 0 || j >= n || (i / 10 + i % 10 + j / 10 + j % 10) > k || visited[i][j] == 1)
            return 0;
        visited[i][j] = 1;
        return 1
               + dfs(i + 1, j, m, n, k, visited)
               + dfs(i, j + 1, m, n, k, visited)
               + dfs(i, j - 1, m, n, k, visited)
               + dfs(i - 1, j, m, n, k, visited);
    }
};

int main(int argc, char **argv) {
    Solution s;
    EXPECT_EQ(s.movingCount(2, 3, 1), 3);
    EXPECT_EQ(s.movingCount(3, 1, 0), 1);
    return EXIT_SUCCESS;
}