#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int minPairSum(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        auto n = nums.size();
        int max_sum = INT_MIN;
        for (int i = 0; i < n; ++i) {
            auto temp_sum = nums[i] + nums[n - i - 1];
            if (max_sum < temp_sum) max_sum = temp_sum;
        }
        return max_sum;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> nums_1{3, 5, 2, 3};
    EXPECT_EQ(s.minPairSum(nums_1), 7);
    vector<int> nums_2{3, 5, 4, 2, 4, 6};
    EXPECT_EQ(s.minPairSum(nums_2), 8);
    return EXIT_SUCCESS;
}