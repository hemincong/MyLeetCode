//
// Created by mincong.he on 2019/10/7.
//

#include <vector>

#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    bool canJump(vector<int> &nums) {
        auto tmp = vector<int>(nums.size(), 0);

        int n_p = nums.size() - 1;
        tmp.back() = 1;

        while (n_p >= 0) {
            auto can_jump = nums.at(n_p);
            for (int i = 0; i <= can_jump; i++) {
                if (tmp.at(n_p + i) == 1) {
                    tmp[n_p] = 1;
                    break;
                }
            }
            n_p--;
        }

        return tmp.at(0) == 1;
    }
};

class Solution_2 {
public:
    bool canJump(vector<int> &nums) {
        if (nums.size() == 1 && nums.at(0) == 0) return true;

        int longest = nums.at(0);
        for (int i = 0; i < nums.size(); ++i) {
            if (longest < i) break;
            auto curr_can_jump = i + nums.at(i);
            longest = curr_can_jump > longest ? curr_can_jump : longest;
        }
        return longest >= nums.size() - 1;
    }
};

int main(int argc, char **argv) {
    std::vector<int> nums_0 = {0};
    std::vector<int> nums_1 = {2, 3, 1, 1, 4};
    std::vector<int> nums_2 = {3, 2, 1, 0, 4};
    std::vector<int> nums_3 = {2, 0, 0};

    Solution solve;
    EXPECT_EQ(solve.canJump(nums_0), true);
    EXPECT_EQ(solve.canJump(nums_1), true);
    EXPECT_EQ(solve.canJump(nums_2), false);
    EXPECT_EQ(solve.canJump(nums_3), true);

    Solution_2 solve_2;
    EXPECT_EQ(solve_2.canJump(nums_0), true);
    EXPECT_EQ(solve_2.canJump(nums_1), true);
    EXPECT_EQ(solve_2.canJump(nums_2), false);
    EXPECT_EQ(solve_2.canJump(nums_3), true);

    return EXIT_SUCCESS;
}