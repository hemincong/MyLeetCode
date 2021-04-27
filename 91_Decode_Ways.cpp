//
// Created by mincong.he on 2021/4/21.
//

#include <string>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        auto n = s.size();
        if (s.empty() || (n == 1 && s[0] == '0')) return 0;
        if (n == 1) return 1;

        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < s.size(); ++i) {
            // 0
            if (s[i] == '0') {
                dp[i + 1] = 0;
            } else {
                // 先加一下上次的值
                dp[i + 1] = dp[i];
            }
            if (i > 0 && (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6'))) {
                // 青蛙爬树，10-26就是两种情况
                dp[i + 1] += dp[i - 1];
            }
        }
        return dp[n];
    }
};

int main(int argc, char **argv) {
    Solution s;
    EXPECT_EQ(s.numDecodings("12"), 2);
    EXPECT_EQ(s.numDecodings("226"), 3);
    EXPECT_EQ(s.numDecodings("0"), 0);
    EXPECT_EQ(s.numDecodings("06"), 0);
    return EXIT_SUCCESS;
}