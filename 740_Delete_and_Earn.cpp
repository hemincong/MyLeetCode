//
// Created by mincong.he on 2021/5/5.
//

#include <vector>
#include <map>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int> &nums) {
        std::map<int, int> count_map;
        auto max_value = *max_element(nums.begin(), nums.end());
        for (const auto n : nums) {
            count_map[n] += n;
        }
        std::vector<int> dp(max_value + 1, 0);
        dp[0] = 0;
        dp[1] = count_map[1];
        for (int i = 2; i <= max_value; ++i) {
            dp[i] = std::max(count_map[i] + dp[i - 2], dp[i - 1]);
        }

        return dp[dp.size() - 1];
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> test_case_1{3, 4, 2};
    EXPECT_EQ(s.deleteAndEarn(test_case_1), 6);

    vector<int> test_case_2{2, 2, 3, 3, 3, 4};
    EXPECT_EQ(s.deleteAndEarn(test_case_2), 9);

    vector<int> test_case_3{3, 1};
    EXPECT_EQ(s.deleteAndEarn(test_case_3), 4);

    return EXIT_SUCCESS;
}
