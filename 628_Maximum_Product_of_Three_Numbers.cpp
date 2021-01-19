//
// Created by mincong.he on 2021/1/20.
//
#include "AlgoUtils.h"

#include <vector>

using namespace std;

class Solution {
public:
    int maximumProduct(vector<int> &nums) {
        sort(nums.begin(), nums.end());

        auto n = nums.size();
        auto first_1 = nums[0];
        auto first_2 = nums[1];
        auto last_1 = nums[n - 1];
        auto last_2 = nums[n - 2];
        auto last_3 = nums[n - 3];

        return std::max(last_1 * last_2 * last_3, first_1 * first_2 * last_1);
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> test_case_1{1, 2, 3};
    vector<int> test_case_2{1, 2, 3, 4};
    vector<int> test_case_3{-1, -2, -3};
    EXPECT_EQ(s.maximumProduct(test_case_1), 6);
    EXPECT_EQ(s.maximumProduct(test_case_2), 24);
    EXPECT_EQ(s.maximumProduct(test_case_3), -6);

    return EXIT_SUCCESS;
}