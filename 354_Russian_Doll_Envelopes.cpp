//
// Created by mincong.he on 2021/3/4.
//

#include <vector>
#include <iostream>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<vector<int>> &envelopes) {
        std::sort(envelopes.begin(), envelopes.end(), [](const auto &v1, const auto &v2) {
            if (v1[0] < v2[0]) return true;
            if (v1[0] > v2[0]) return false;
            if (v1[1] > v2[1]) return true;
            return false;
        });
        return lengthOfLIS(envelopes);
    }

private:
    static int lengthOfLIS(const vector<vector<int>> &martix) {
        vector<int> dp(martix.size(), 1);
        int max = 1;
        for (int i = 1; i < martix.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (martix[i][1] > martix[j][1]) {
                    dp[i] = dp[i] > dp[j] + 1 ? dp[i] : dp[j] + 1;
                }
            }
            max = max > dp[i] ? max : dp[i];
        }
        return max;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<vector<int>> test_case_1{{5, 4},
                                    {6, 4},
                                    {6, 7},
                                    {2, 3}};
    EXPECT_EQ(s.maxEnvelopes(test_case_1), 3);
    return EXIT_SUCCESS;
}