//
// Created by mincong.he on 2020/5/28.
//

#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int> &nums, int target) {
        if (nums.empty()) return -1;

        int offset = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                offset = i + 1;
                break;
            }
        }
        vector<int> tmp(nums.size());
        int tmp_i = 0;
        for (int i = offset; i < nums.size(); i++) {
            tmp[tmp_i++] = nums[i];
        }
        for (int i = 0; i < offset; i++) {
            tmp[i + tmp_i] = nums[i];
        }

        int begin_pos = 0;
        int end_pos = tmp.size() - 1;
        while (begin_pos <= end_pos) {
            int mid = begin_pos + (end_pos - begin_pos) / 2;
            if (tmp[mid] == target) {
                return (mid + offset) % tmp.size();
            } else if (tmp[mid] > target) {
                end_pos = mid - 1;
            } else {
                begin_pos = mid + 1;
            }
        }

        return -1;
    }
};

int main() {
    std::vector<int> nums_1{4, 5, 6, 7, 0, 1, 2};
    std::vector<int> nums_2{};
    std::vector<int> nums_3{1};
    std::vector<int> nums_4{3, 1};
    std::vector<int> nums_5{1, 3};
    Solution solve;
    assert(solve.search(nums_1, 4) == 0);
    assert(solve.search(nums_1, 0) == 4);
    assert(solve.search(nums_1, 2) == 6);
    assert(solve.search(nums_1, 3) == -1);
    assert(solve.search(nums_2, 3) == -1);
    assert(solve.search(nums_3, 1) == 0);
    assert(solve.search(nums_3, 0) == -1);
    assert(solve.search(nums_4, 1) == 1);
    assert(solve.search(nums_5, 3) == 1);
    return EXIT_SUCCESS;
}



