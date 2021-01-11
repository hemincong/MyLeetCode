//
// Created by mincong.he on 2021/1/11.
//

#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int> &nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            auto mid = left + ((right - left) >> 1);
            if (nums[mid] > nums[mid + 1]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> test_case_1{1, 2, 3, 1};
    EXPECT_EQ(s.findPeakElement(test_case_1), 2);
    vector<int> test_case_2{1, 2, 1, 3, 5, 6, 4};
    EXPECT_EQ(s.findPeakElement(test_case_2), 5);
    return EXIT_SUCCESS;
}