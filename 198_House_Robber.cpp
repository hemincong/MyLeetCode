//
// Created by mincong.he on 2020/12/9.
//

#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int rob(vector<int> &nums) {
        auto n_size = nums.size();
        if (n_size == 0) return 0;
        if (n_size == 1) return nums[0];

        auto temp = vector<int>(nums.size(), 0);
        temp[0] = nums[0];
        temp[1] = nums[0] > nums[1] ? nums[0] : nums[1];
        for (int i = 2; i < n_size; ++i) {
            auto r_1 = temp[i - 1];
            auto r_2 = temp[i - 2] + nums[i];
            temp[i] = r_1 > r_2 ? r_1 : r_2;
        }
        return temp[n_size - 1];
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> test_case_1{1, 2, 3, 1};
    EXPECT_EQ(s.rob(test_case_1), 4);

    vector<int> test_case_2{2, 7, 9, 3, 1};
    EXPECT_EQ(s.rob(test_case_2), 12);

    vector<int> test_case_3{2};
    EXPECT_EQ(s.rob(test_case_3), 2);

    vector<int> test_case_4{1, 2};
    EXPECT_EQ(s.rob(test_case_4), 2);

    vector<int> test_case_5{2, 1, 1, 2};
    EXPECT_EQ(s.rob(test_case_5), 4);
}