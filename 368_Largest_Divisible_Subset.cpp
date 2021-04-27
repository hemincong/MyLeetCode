//
// Created by mincong.he on 2021/4/24.
//

#include <vector>
#include <algorithm>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int> &nums) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> dp(nums.size(), vector<int>());

        for (auto i = 0; i < nums.size(); i++) {
            dp[i].push_back(nums[i]);
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] % nums[j] == 0) {
                    if (dp[i].size() < dp[j].size() + 1) {
                        dp[i] = dp[j];
                        dp[i].push_back(nums[i]);
                    }
                }
            }
        }
        return *max_element(dp.begin(), dp.end(), [](const auto &v1, const auto &v2) {
            return v1.size() < v2.size();
        });
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> test_case_1{1, 2, 3};
    vector<int> ret_1{1, 2};
    assertArray(s.largestDivisibleSubset(test_case_1), ret_1); // [1, 2], [1, 3]

    vector<int> test_case_2{1, 2, 4, 8};
    vector<int> ret_2{1, 2, 4, 8};
    assertArray(s.largestDivisibleSubset(test_case_2), ret_2);
    return EXIT_SUCCESS;
}