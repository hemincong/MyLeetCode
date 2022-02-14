//
// Created by mincong.he on 2022/2/14.
//
#include <vector>

#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int> &nums) {
        auto n = nums.size();
        int l = 0;
        int r = n - 1;
        while (l < r) {
            auto mid = l + ((r - l) > 1);
            if ((mid & 1) == 1) {
                mid--;
            }
            if (nums[mid] == nums[mid + 1]) {
                l = mid + 2;
            } else {
                r = mid;
            }
        }
        return nums[l];

    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> nums_1{1, 1, 2, 3, 3, 4, 4, 8, 8};
    EXPECT_EQ(s.singleNonDuplicate(nums_1), 2);
    vector<int> nums_2{3, 3, 7, 7, 10, 11, 11};
    EXPECT_EQ(s.singleNonDuplicate(nums_2), 10);
    return EXIT_SUCCESS;
}