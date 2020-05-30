//
// Created by mincong.he on 2020/5/30.
//

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        auto ret = vector<int>{-1, -1};
        if (nums.empty()) return ret;

        int begin_pos = 0;
        int end_pos = nums.size() - 1;

        int target_pos = -1;
        while (begin_pos <= end_pos) {
            int mid = begin_pos + (end_pos - begin_pos) / 2;
            if (nums[mid] == target) {
                target_pos = mid;
                break;
            } else if (nums[mid] > target) {
                end_pos = mid - 1;
            } else {
                begin_pos = mid + 1;
            }
        }

        if (target_pos == -1) return ret;
        auto lower_bound = target_pos;
        auto higher_bound = target_pos;
        for (int i = target_pos; i >= 0 && i < nums.size(); i--) {
            if (nums[i] == target) {
                lower_bound = i;
            }
        }
        for (int i = target_pos; i >= 0 && i < nums.size(); i++) {
            if (nums[i] == target) {
                higher_bound = i;
            }
        }

        ret = vector<int>{lower_bound, higher_bound};

        return ret;
    }
};

int main(int argc, char **argv) {
    Solution solution;
    vector<int> nums_empty{};
    vector<int> nums_1{5, 7, 7, 8, 8, 10};
    vector<int> nums_2{1};
    vector<int> nums_3{2, 2};

    auto ret = solution.searchRange(nums_empty, 6);
    assert(ret[0] == -1 && ret[1] == -1);

    ret = solution.searchRange(nums_1, 8);
    assert(ret[0] == 3 && ret[1] == 4);

    ret = solution.searchRange(nums_1, 10);
    assert(ret[0] == 5 && ret[1] == 5);

    ret = solution.searchRange(nums_1, 6);
    assert(ret[0] == -1 && ret[1] == -1);

    ret = solution.searchRange(nums_1, 5);
    assert(ret[0] == 0 && ret[1] == 0);

    ret = solution.searchRange(nums_2, 0);
    assert(ret[0] == -1 && ret[1] == -1);

    ret = solution.searchRange(nums_3, 2);
    assert(ret[0] == 0 && ret[1] == 1);

    return EXIT_SUCCESS;
}