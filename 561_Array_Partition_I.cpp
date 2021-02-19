//
// Created by mincong.he on 2021/2/16.
//

#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int> &nums) {
        std::sort(nums.begin(), nums.end(), std::greater<int>());
        int sum = 0;
        auto n = nums.size();
        for (int i = 0; i < n / 2; ++i) {
            sum += nums[2 * i + 1];
        }
        return sum;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> test_case_1{1, 4, 3, 2};
    EXPECT_EQ(s.arrayPairSum(test_case_1), 4)

    vector<int> test_case_2{6, 2, 6, 5, 1, 2};
    EXPECT_EQ(s.arrayPairSum(test_case_2), 9)

    return EXIT_SUCCESS;
}