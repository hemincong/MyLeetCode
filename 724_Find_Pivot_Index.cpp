//
// Created by mincong.he on 2021/1/28.
//

#include "AlgoUtils.h"
#include <vector>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int> &nums) {
        long sum = 0;
        for (auto &n : nums) {
            sum += n;
        }
        long sum_2 = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (sum_2 * 2 + nums[i] == sum) return i;
            sum_2 += nums[i];
        }
        return -1;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> nums_1 = {1, 7, 3, 6, 5, 6};
    vector<int> nums_2 = {1, 2, 3};
    vector<int> nums_3 = {-1, -1, -1, -1, -1, 0};
    vector<int> nums_4 = {-1, -1, -1, -1, -1, -1};
    EXPECT_EQ(s.pivotIndex(nums_1), 3);
    EXPECT_EQ(s.pivotIndex(nums_2), -1);
    EXPECT_EQ(s.pivotIndex(nums_3), 2);
    EXPECT_EQ(s.pivotIndex(nums_4), -1);
    return EXIT_SUCCESS;
}