//
// Created by mincong.he on 2021/5/13.
//

#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int numWays(int steps, int arrLen) {
        int max_col = min(arrLen - 1, steps / 2);
        vector<int> dp(max_col + 1);
        dp[0] = 1;
        for (int i = 1; i <= steps; i++) {
            vector<int> dp_next(max_col + 1);
            for (int j = 0; j <= max_col; j++) {
                dp_next[j] = dp[j];
                if (j - 1 >= 0) dp_next[j] = (dp_next[j] + dp[j - 1]) % MODULO;
                if (j + 1 <= max_col) dp_next[j] = (dp_next[j] + dp[j + 1]) % MODULO;
            }
            dp = dp_next;
        }
        return dp[0];
    }

private:
    static const int MODULO = 1e9 + 7;
};

int main(int argc, char **argv) {
    Solution s;
    EXPECT_EQ(s.numWays(3, 2), 4);
    EXPECT_EQ(s.numWays(2, 4), 2);
    EXPECT_EQ(s.numWays(4, 2), 8);
    EXPECT_EQ(s.numWays(438, 315977), 483475137);
    return EXIT_SUCCESS;
}