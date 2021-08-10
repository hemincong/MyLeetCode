#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int> &nums) {
        int ret = 0;
        auto n = nums.size();
        int sub_slices = 0;
        for (int i = 2; i < n; i++) {
            if (nums[i - 1] - nums[i - 2] == nums[i] - nums[i - 1]) {
                sub_slices++;
                ret += sub_slices;
            } else {
                sub_slices = 0;
            }
        }
        return ret;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> nums_1{1, 2, 3, 4};
    EXPECT_EQ(s.numberOfArithmeticSlices(nums_1), 3);
    vector<int> nums_2{1};
    EXPECT_EQ(s.numberOfArithmeticSlices(nums_2), 0);
    return EXIT_SUCCESS;
}