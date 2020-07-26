//
// Created by mincong.he on 2020/7/26.
//

#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int splitArray(vector<int> &nums, int m) {
        long min = 0;
        long max = 0;
        for (const auto &n : nums) {
            if (n > min) {
                min = n;
            }
            max += n;
        }

        long curr = min + (max - min) / 2;
        while (min < max) {
            long sub_total = 0;
            auto curr_m = 1;
            for (long num : nums) {
                sub_total += num;
                if (sub_total > curr) {
                    sub_total = num;
                    curr_m++;
                }
            }

            if (curr_m > m) min = curr + 1;
            if (curr_m <= m) max = curr;

            curr = min + (max - min) / 2;
        }
        return min;
    }
};

int main(int argc, char **argv) {
    Solution s;
    auto case_empty = std::vector<int>{};
    EXPECT_EQ(s.splitArray(case_empty, 2), 0);
    auto case_1 = std::vector<int>{7, 2, 5, 10, 8};
    EXPECT_EQ(s.splitArray(case_1, 2), 18);
    auto case_2 = std::vector<int>{1, 2147483647};
    EXPECT_EQ(s.splitArray(case_2, 2), 2147483647);
    return EXIT_SUCCESS;
}