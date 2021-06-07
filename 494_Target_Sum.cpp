//
// Created by mincong.he on 2021/6/7.
//

#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
private:
    void dfs(int *count, const vector<int> &nums, int index, int curr_value, int target) {
        if (index == (nums.size() - 1)) {
            if (curr_value + nums[index] == target)
                (*count)++;
            if (curr_value - nums[index] == target)
                (*count)++;
            return;
        }

        dfs(count, nums, index + 1, curr_value + nums[index], target);
        dfs(count, nums, index + 1, curr_value - nums[index], target);
    }

public:
    int findTargetSumWays(vector<int> &nums, int target) {
        int count = 0;
        dfs(&count, nums, 0, 0, target);
        return count;
    }
};

int main(int argc, char **argv) {
    Solution s;
    //vector<int> test_case_1{1, 1, 1, 1, 1};
    //EXPECT_EQ(s.findTargetSumWays(test_case_1, 3), 5)
    //vector<int> test_case_2{1};
    //EXPECT_EQ(s.findTargetSumWays(test_case_2, 1), 1)
    vector<int> test_case_3{1, 0};
    EXPECT_EQ(s.findTargetSumWays(test_case_3, 1), 2)
    return EXIT_SUCCESS;
}