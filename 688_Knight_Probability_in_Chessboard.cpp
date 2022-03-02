//
// Created by mincong.he on 2022/2/17.
//

#include <vector>
#include <iostream>

class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        std::vector<std::vector<std::vector<double>>> dp(k + 1, std::vector<std::vector<double>>(n,
                                                                                                 std::vector<double>(n,
                                                                                                                     0)));
        for (int step = 0; step <= k; ++step) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (step == 0) {
                        dp[step][i][j] = 1;
                    } else {
                        for (auto &d: dirs) {
                            int new_i = i + d[0];
                            int new_j = j + d[1];
                            if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < n) {
                                dp[step][i][j] += dp[step - 1][new_i][new_j] / 8;
                            }
                        }
                    }

                }
            }
        }
        return dp[k][row][column];

    }

private:
    std::vector<std::vector<int>> dirs = {{-2, -1},
                                          {-2, 1},
                                          {2,  -1},
                                          {2,  1},
                                          {-1, -2},
                                          {-1, 2},
                                          {1,  -2},
                                          {1,  2}};
};

int main(int argc, char **argv) {
    Solution s;
    std::cout << s.knightProbability(3, 2, 0, 0) << std::endl; // 0.0625
    std::cout << s.knightProbability(1, 0, 0, 0) << std::endl; // 1
    return EXIT_SUCCESS;
}