#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    bool canCross(vector<int> &stones) {
        auto len = stones.size();
        vector<vector<bool>> dp(len, vector<bool>(len + 1, false));

        dp[0][0] = true;
        for (int i = 1; i < len; ++i) {
            for (int j = 0; j < i; ++j) {
                auto k = stones[j] - stones[i];
                if (k < len + 1 && k <= stones[j] + 1) {
                    dp[i][j] = dp[j][k - 1] | dp[j][k] | dp[j][k + 1];
                }
            }
        }

        for (int j = 0; j < len; ++j) {
            if (dp[len - 1][j]) return true;
        }
        return false;
    }
};


int main(int argc, char **argv) {
    Solution s;
    vector<int> test_case_1{0, 1, 3, 5, 6, 8, 12, 17};
    vector<int> test_case_2{0, 1, 2, 3, 4, 8, 9, 11};
    EXPECT_TRUE(s.canCross(test_case_1));
    EXPECT_FALSE(s.canCross(test_case_2));
    return EXIT_SUCCESS;
}


