#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int checkRecord(int n) {
        long dp[6] = {0};
        dp[0] = 1;
        dp[1] = 1;
        dp[3] = 1;

        long new_dp[6] = {0};
        // L : 3, 连续, A : 2, 总
        // 0 : A 0, L 0
        // 1 : A 0, L 1
        // 2 : A 0, L 2
        // 3 : A 1, L 0
        // 4 : A 1, L 1
        // 5 : A 1, L 3
        for (int i = 1; i < n; ++i) {
            // + p
            new_dp[0] = dp[0]



            memcpy(dp, new_dp, sizeof(dp));
        }
        long sum = 0L;
        for (long i : dp) {
            sum = (sum + i) % MOD;
        }
        return (int) (sum % MOD);
    }

    int MOD = 1000000007;
};

int main(int argc, char **argv) {
    Solution s;
    EXPECT_EQ(s.checkRecord(2), 8);
    EXPECT_EQ(s.checkRecord(1), 3);
    EXPECT_EQ(s.checkRecord(10101), 183236316);
    return EXIT_SUCCESS;
}