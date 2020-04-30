//
// Created by mincong.he on 2020/4/28.
//

#include <vector>

class Solution {
public:
    static int searchInsert(std::vector<int> &nums, int target) {
        auto begin_pos = 0;
        auto end_pos = nums.size() - 1;
        while (begin_pos <= end_pos) {
            int mid = begin_pos + ((end_pos - begin_pos) / 2);
            if (target == nums[mid]) {
                return mid;
            } else if (target < nums[mid]) {
                if (mid == 0 || target > nums[mid - 1]) {
                    return mid;
                }
                end_pos = mid;
            } else {
                if (mid == nums.size() - 1 || target < nums[mid + 1]) {
                    return mid + 1;
                }
                begin_pos = mid + 1;
            }
        }
        return begin_pos;
    }
};

int main() {
    std::vector<int> nums{1, 3, 5, 6};
    Solution solve;
    assert(solve.searchInsert(nums, 5) == 2);
    assert(solve.searchInsert(nums, 2) == 1);
    assert(solve.searchInsert(nums, 7) == 4);
    assert(solve.searchInsert(nums, 0) == 0);
    return 0;
}