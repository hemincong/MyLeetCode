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
        int mid = l + ((r - l) >> 1);
        while (l < r) {
            mid = l + ((r - l) >> 1);
            if (nums[mid] > nums[r]) {
                l = mid + 1;
            } else if (nums[mid] > nums[l]) {
                r = mid;
            } else {
                r--;
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
                min = nums[i + 1];
                break;
            }
        }

        return min;
    }
};

int main(int argc, char **argv) {
    Solution s;
    Solution_2 s_2;
    auto case_0 = vector<int>{};
    auto case_1 = vector<int>{1, 3, 5};
    auto case_2 = vector<int>{2, 2, 2, 0, 1};
    auto case_3 = vector<int>{2};
    auto case_4 = vector<int>{2, 2, 2, 2, 2};
    auto case_5 = vector<int>{3, 2, 2, 2, 2};
    auto case_6 = vector<int>{2, 2, 2, 2, 0};
    EXPECT_EQ(s.findMin(case_0), 0);
    EXPECT_EQ(s.findMin(case_1), 1);
    EXPECT_EQ(s.findMin(case_2), 0);
    EXPECT_EQ(s.findMin(case_3), 2);
    EXPECT_EQ(s.findMin(case_4), 2);
    EXPECT_EQ(s.findMin(case_5), 2);
    EXPECT_EQ(s.findMin(case_6), 0);
    EXPECT_EQ(s_2.findMin(case_0), 0);
    EXPECT_EQ(s_2.findMin(case_1), 1);
    EXPECT_EQ(s_2.findMin(case_2), 0);
    EXPECT_EQ(s_2.findMin(case_3), 2);
    EXPECT_EQ(s_2.findMin(case_4), 2);
    EXPECT_EQ(s_2.findMin(case_5), 2);
    EXPECT_EQ(s_2.findMin(case_6), 0);
    return EXIT_SUCCESS;
}