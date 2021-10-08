//
// Created by mincong.he on 2021/9/26.
//
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; ++i) {
            int min_count = INT_MAX;
            for (int j = 1; j * j <= i; j++) {
                min_count = min(min_count, dp[i - j * j]);
            }
            dp[i] = min_count + 1;
        }
        return dp[n];
    }
};
