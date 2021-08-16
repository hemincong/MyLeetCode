#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<long>>> dp(maxMove + 1, vector<vector<long>>(m, vector<long>(n, 0)));
        for (int k = 1; k <= maxMove; ++k) {
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    long up = 1;
                    if (i > 0) up = dp[k - 1][i - 1][j];
                    long down = 1;
                    if (i < m - 1) down = dp[k - 1][i + 1][j];
                    long left = 1;
                    if (j > 0) left = dp[k - 1][i][j - 1];
                    long right = 1;
                    if (j < n - 1) right = dp[k - 1][i][j + 1];
                    dp[k][i][j] = (up + down + left + right) % 1000000007;
                }
            }
        }
        return dp[maxMove][startRow][startColumn];
    }
};

int main(int argc, char **argv) {
    Solution s;
    EXPECT_EQ(s.findPaths(2, 2, 2, 0, 0), 6)
    EXPECT_EQ(s.findPaths(1, 3, 3, 0, 1), 12)
    return EXIT_SUCCESS;
}