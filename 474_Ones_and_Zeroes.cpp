//
// Created by mincong.he on 2021/6/6.
//

#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    static pair<int, int> get_zero_one_count(const string &str) {
        pair<int, int> ret{0, 0};
        for (auto &c : str) {
            if (c == '0') ret.first++;
            if (c == '1') ret.second++;
        }
        return ret;
    }

    int findMaxForm(vector<string> &strs, int m, int n) {
        int len = strs.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < len; i++) {
            auto &&zero_one_count = get_zero_one_count(strs[i]);
            int zeros = zero_one_count.first;
            int ones = zero_one_count.second;
            for (int z = m; z >= zeros; --z) {
                for (int o = n; o >= ones; --o) {
                    dp[z][o] = std::max(dp[z][o], dp[z - zeros][o - ones] + 1);
                }
            }
        }
        return dp[m][n];
    }
};


int main(int argc, char **argv) {
    Solution s;
    vector<string> strs_1{"10", "0001", "111001", "1", "0"};
    EXPECT_EQ(s.findMaxForm(strs_1, 5, 3), 4);
    vector<string> strs_2{"10", "0", "1"};
    EXPECT_EQ(s.findMaxForm(strs_2, 1, 1), 2);
    return EXIT_SUCCESS;
}