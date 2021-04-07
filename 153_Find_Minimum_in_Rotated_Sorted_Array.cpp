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
        int l = 0;
        int r = nums.size() - 1;

        while (l < r) {
            int mid = l + ((r - l) >> 1);
            if (nums[mid] < nums[r]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return nums[l];
    }
};

class Solution_2 {
public:
    int findMin(vector<int> &nums) {
        if (nums.empty()) return 0;

        int min = nums[0];

        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i + 1] < nums[0]) {
                return nums[i + 1];
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
    auto case_4 = vector<int>{3, 1, 2};
    EXPECT_EQ(s.findMin(case_0), 0);
    EXPECT_EQ(s.findMin(case_1), 1);
    EXPECT_EQ(s.findMin(case_2), 0);
    EXPECT_EQ(s.findMin(case_3), 11);
    EXPECT_EQ(s.findMin(case_4), 1);
    return EXIT_SUCCESS;
}