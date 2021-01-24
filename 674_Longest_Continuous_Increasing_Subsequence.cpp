//
// Created by mincong.he on 2021/1/24.
//

#include "AlgoUtils.h"
#include <vector>

using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int> &nums) {
        if (nums.empty()) return 0;

        int curr_len = 1;
        int max = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] < nums[i + 1]) {
                curr_len++;
            } else {
                if (max < curr_len) max = curr_len;
                curr_len = 1;
            }
        }
        if (max < curr_len) max = curr_len;
        return max;
    }
};

int main(int argc, char **argv) {
    Solution s;
    std::vector<int> test_case_1{1, 3, 5, 4, 7};
    std::vector<int> test_case_2{2, 2, 2, 2, 2};
    std::vector<int> test_case_3;
    std::vector<int> test_case_4{1};
    std::vector<int> test_case_5{1, 3, 5, 7};

    EXPECT_EQ(s.findLengthOfLCIS(test_case_1), 3);
    EXPECT_EQ(s.findLengthOfLCIS(test_case_2), 1);
    EXPECT_EQ(s.findLengthOfLCIS(test_case_3), 0);
    EXPECT_EQ(s.findLengthOfLCIS(test_case_4), 1);
    EXPECT_EQ(s.findLengthOfLCIS(test_case_5), 4);
    return EXIT_SUCCESS;
}