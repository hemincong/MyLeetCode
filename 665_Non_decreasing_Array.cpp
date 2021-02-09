//
// Created by mincong.he on 2021/2/7.
//

#include "AlgoUtils.h"
#include <vector>

using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int> &nums) {
        auto n = nums.size();
        int count = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] > nums[i + 1]) {
                count++;
                if (count > 1) return false;
                if (i > 0 && nums[i + 1] < nums[i - 1]) nums[i + 1] = nums[i];
            }
        }
        return true;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> test_case_1{4, 2, 3};
    EXPECT_TRUE(s.checkPossibility(test_case_1));

    vector<int> test_case_2{4, 2, 1};
    EXPECT_FALSE(s.checkPossibility(test_case_2));
    return EXIT_SUCCESS;
}