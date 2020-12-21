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

class Solution_2 {
public:
    int lengthOfLIS(vector<int> &nums) {
        if (nums.empty()) return 0;

        std::vector<int> s;
        s.push_back(nums[0]);
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > s.back()) {
                s.push_back(nums[i]);
            } else {
                auto index = binary_search(s, nums[i]);
                s[index] = nums[i];
            }
        }
        return s.size();
    }

private:
    static int binary_search(const std::vector<int> &nums, int target) {
        int index = -1;
        int left = 0;
        int right = nums.size() - 1;
        while (index == -1) {
            int mid = left + ((right - left) >> 1);
            if (target == nums[mid]) return mid;
            if (target > nums[mid]) {
                if (mid == nums.size() - 1 || target < nums[mid + 1]) index = mid + 1;
                left = mid + 1;
            } else {
                if (mid == 0 || target > nums[mid - 1]) index = mid;
                right = mid - 1;
            }
        }
        return index;
    }
};

int main(int argc, char **argv) {
    Solution s;
    Solution_2 s_2;
    vector<int> test_case_1{10, 9, 2, 5, 3, 7, 101, 18};
    EXPECT_EQ(s.lengthOfLIS(test_case_1), 4);
    EXPECT_EQ(s_2.lengthOfLIS(test_case_1), 4);
    vector<int> test_case_2{0, 1, 0, 3, 2, 3};
    EXPECT_EQ(s.lengthOfLIS(test_case_2), 4);
    EXPECT_EQ(s_2.lengthOfLIS(test_case_2), 4);
    vector<int> test_case_3{7, 7, 7, 7, 7, 7, 7};
    EXPECT_EQ(s.lengthOfLIS(test_case_3), 1);
    EXPECT_EQ(s_2.lengthOfLIS(test_case_3), 1);
    vector<int> test_case_4{1, 3, 6, 7, 9, 4, 10, 5, 6};
    EXPECT_EQ(s.lengthOfLIS(test_case_4), 6);
    EXPECT_EQ(s_2.lengthOfLIS(test_case_4), 6);
    vector<int> test_case_5{3, 5, 6, 2, 5, 4, 19, 5, 6, 7, 12};
    EXPECT_EQ(s.lengthOfLIS(test_case_5), 6);
    EXPECT_EQ(s_2.lengthOfLIS(test_case_5), 6);

    return EXIT_SUCCESS;
}