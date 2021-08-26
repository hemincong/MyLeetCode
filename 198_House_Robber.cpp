//
// Created by mincong.he on 2020/12/9.
//

#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int rob(vector<int> &nums) {
        auto n_size = nums.size();
        if (n_size == 0) return 0;
        if (n_size == 1) return nums[0];

        vector<int> dp(n_size, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[1], nums[0]);
        for (int i = 2; i < n_size; ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[n_size - 1];
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> test_case_0{0};
    EXPECT_EQ(s.rob(test_case_0), 0);

    vector<int> test_case_1{1, 2, 3, 1};
    EXPECT_EQ(s.rob(test_case_1), 4);

    vector<int> test_case_2{2, 7, 9, 3, 1};
    EXPECT_EQ(s.rob(test_case_2), 12);

    vector<int> test_case_3{2};
    EXPECT_EQ(s.rob(test_case_3), 2);

    vector<int> test_case_4{1, 2};
    EXPECT_EQ(s.rob(test_case_4), 2);

    vector<int> test_case_5{2, 1, 1, 2};
    EXPECT_EQ(s.rob(test_case_5), 4);
}