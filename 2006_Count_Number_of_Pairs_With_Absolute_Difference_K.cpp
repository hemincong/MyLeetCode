//
// Created by mincong.he on 2022/2/9.
//

#include <vector>
#include <map>

#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int countKDifference(vector<int> &nums, int k) {
        map<int, int> num_count;
        for (const auto n: nums) {
            num_count[n]++;
        }
        int pair_count = 0;
        for (const auto n: nums) {
            auto diff_up = n + k;
            pair_count += num_count[diff_up];
            auto diff_down = n - k;
            if (diff_down >= 0) pair_count += num_count[diff_down];
        }
        return pair_count / 2;
    }
};

int main(int argc, char **argv) {
    Solution s;

    std::vector test_case_1{1, 2, 2, 1};
    EXPECT_EQ(s.countKDifference(test_case_1, 1), 4);

    std::vector test_case_2{1, 3};
    EXPECT_EQ(s.countKDifference(test_case_2, 3), 0);

    std::vector test_case_3{3, 2, 1, 5, 4};
    EXPECT_EQ(s.countKDifference(test_case_3, 2), 3);

    std::vector test_case_4{2, 2, 4, 4};
    EXPECT_EQ(s.countKDifference(test_case_4, 2), 4);

    std::vector test_case_5{7, 7, 8, 3, 1, 2, 7, 2, 9, 5};
    EXPECT_EQ(s.countKDifference(test_case_5, 6), 6);
    return EXIT_SUCCESS;
}