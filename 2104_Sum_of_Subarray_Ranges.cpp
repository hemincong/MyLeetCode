//
// Created by mincong.he on 2022/3/4.
//

#include "AlgoUtils.h"
#include <vector>

using namespace std;


class Solution {
public:
    long long subArrayRanges(vector<int> &nums) {
        int n = nums.size();
        long long ret = 0;
        for (int i = 0; i < n; ++i) {
            int min_n = nums[i];
            int max_n = nums[i];
            for (int j = i + 1 ; j < n; ++j) {
                min_n = min(min_n, nums[j]);
                max_n = max(max_n, nums[j]);
                ret += (max_n - min_n);
            }
        }
        return ret;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> test_case_1{1, 2, 3};
    EXPECT_EQ(s.subArrayRanges(test_case_1), 4);

    vector<int> test_case_2{1, 3, 3};
    EXPECT_EQ(s.subArrayRanges(test_case_2), 4);

    vector<int> test_case_3{4, -2, -3, 4, 1};
    EXPECT_EQ(s.subArrayRanges(test_case_3), 59);

    return EXIT_SUCCESS;
}