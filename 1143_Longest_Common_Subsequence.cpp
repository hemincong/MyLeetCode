//
// Created by mincong.he on 2021/4/3.
//

#include <vector>
#include <string>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if (text1.empty() || text2.empty()) return 0;
        auto len_1 = text1.size();
        auto len_2 = text2.size();

        vector<vector<int>> dp(len_1 + 1, vector<int>(len_2 + 1, 0));
        for (int i = 1; i <= len_1; ++i) {
            auto c = text1.at(i - 1);
            for (int j = 1; j <= len_2; ++j) {
                if (c == text2.at(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1];
                }
            }
        }
        return dp[len_1][len_2];
    }
};

int main(int argc, char **argv) {
    Solution s;
    EXPECT_EQ(s.longestCommonSubsequence("abcde", "ace"), 3);
    EXPECT_EQ(s.longestCommonSubsequence("abc", "abc"), 3);
    EXPECT_EQ(s.longestCommonSubsequence("abc", "def"), 0);
    EXPECT_EQ(s.longestCommonSubsequence("bsbininm", "jmjkbkjkv"), 1);
    return EXIT_SUCCESS;
}