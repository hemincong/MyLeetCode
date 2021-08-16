#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int search(vector<int> &nums, int target) {
        auto n = nums.size();
        int left = 0;
        int right = n;
        while (left <= right) {
            auto mid = left + ((right - left) >> 1);
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> nums_1{-1, 0, 3, 5, 9, 12};
    EXPECT_EQ(s.search(nums_1, 9), 4);
    EXPECT_EQ(s.search(nums_1, 2), -1);
    return EXIT_SUCCESS;
}