//
// Created by mincong.he on 2021/1/12.
//

#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int maxProduct(vector<int> &nums) {
        auto min = nums[0];
        auto max = nums[0];
        auto ret = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int _max = max;
            int _min = min;
            int n = nums[i];

            auto tmp_max = _max * n > n ? _max * n : n;
            max = tmp_max > _min * n ? tmp_max : _min * n;

            auto tmp_min = _min * n < n ? _min * n : n;
            min = tmp_min < _max * n ? tmp_min : _max * n;

            ret = max > ret ? max : ret;
        }

        return ret;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> test_case_1{2, 3, -2, 4};
    EXPECT_EQ(s.maxProduct(test_case_1), 6);
    vector<int> test_case_2{-2, 0, -1};
    EXPECT_EQ(s.maxProduct(test_case_2), 0);
    return EXIT_SUCCESS;
}