//
// Created by mincong.he on 2021/4/7.
//

#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    bool search(vector<int> &nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r) {
            auto mid = l + ((r - l) >> 1);
            if (nums[mid] == target) return true;
            if (nums[mid] < nums[r]) {
                // 后半部正序
                if (nums[l] <= target && target < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else if (nums[l] < nums[mid]) {
                // 前半部正序
                if (nums[l] < target && target < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                // 消除重复
                while (l <= r && nums[l] == nums[mid]) l++;
                while (l <= r && nums[r] == nums[mid]) r--;
            }
        }
        return false;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> test_case_1{2, 5, 6, 0, 0, 1, 2};
    EXPECT_TRUE(s.search(test_case_1, 0));
    vector<int> test_case_2{2, 5, 6, 0, 0, 1, 2};
    EXPECT_FALSE(s.search(test_case_2, 3));
    vector<int> test_case_3{1, 3};
    EXPECT_TRUE(s.search(test_case_3, 3));
    vector<int> test_case_4{1, 0, 1, 1, 1};
    EXPECT_TRUE(s.search(test_case_4, 0));
    return EXIT_SUCCESS;
}