//
// Created by mincong.he on 2020/7/22.
//

#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int findMin(vector<int> &nums) {
        if (nums.empty()) return 0;

        int min = nums[0];
        bool rotated = false;

        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i + 1] < nums[0]) {
                if (rotated) return min;

                rotated = true;

                min = nums[i + 1];
            }
        }

        return min;
    }
};

int main(int argc, char **argv) {
    Solution s;
    auto case_0 = vector<int>{};
    auto case_1 = vector<int>{3, 4, 5, 1, 2};
    auto case_2 = vector<int>{4, 5, 6, 7, 0, 1, 2};
    auto case_3 = vector<int>{11, 13, 15, 17};
    EXPECT_EQ(s.findMin(case_0), 0);
    EXPECT_EQ(s.findMin(case_1), 1);
    EXPECT_EQ(s.findMin(case_2), 0);
    EXPECT_EQ(s.findMin(case_3), 11);
    return EXIT_SUCCESS;
}