//
// Created by mincong.he on 2020/12/20.
//

#include "AlgoUtils.h"

#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        vector<int> dp(nums.size(), 1);
        dp[0] = 1;
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (nums[i] > nums[j] && dp[j] >= dp[i]) {
                    dp[i] = dp[j] + 1;
                }
            }
        }

        return *std::max_element(dp.begin(), dp.end());
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> test_case_1{10, 9, 2, 5, 3, 7, 101, 18};
    EXPECT_EQ(s.lengthOfLIS(test_case_1), 4);
    vector<int> test_case_2{0, 1, 0, 3, 2, 3};
    EXPECT_EQ(s.lengthOfLIS(test_case_2), 4);
    vector<int> test_case_3{7, 7, 7, 7, 7, 7, 7};
    EXPECT_EQ(s.lengthOfLIS(test_case_3), 1);
    vector<int> test_case_4{1, 3, 6, 7, 9, 4, 10, 5, 6};
    EXPECT_EQ(s.lengthOfLIS(test_case_4), 6);

    return EXIT_SUCCESS;
}