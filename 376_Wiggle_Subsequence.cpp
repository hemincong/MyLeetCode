//
// Created by mincong.he on 2019/10/5.
//

#include <vector>

using namespace std;

enum number_status {
    status_begin,
    status_greater_than_zero,
    status_less_than_zero,
};

class Solution {
public:
    int wiggleMaxLength(vector<int> &nums) {
        if (nums.size() < 2) {
            return nums.size();
        }
        number_status s = status_begin;
        int longest = 1;
        for (int i = 1; i < nums.size(); i++) {
            switch (s) {
                case status_begin:
                    if (nums[i - 1] < nums[i]) {
                        s = status_greater_than_zero;
                        longest++;
                    } else if (nums[i - 1] > nums[i]) {
                        s = status_less_than_zero;
                        longest++;
                    }
                    break;
                case status_greater_than_zero:
                    if (nums[i - 1] > nums[i]) {
                        s = status_less_than_zero;
                        longest++;
                    }
                    break;
                case status_less_than_zero:
                    if (nums[i - 1] < nums[i]) {
                        s = status_greater_than_zero;
                        longest++;
                    }
                    break;
            }
        }
        return longest;
    }
};

int main(int argc, char **argv) {
    std::vector<int> nums_1 = {1, 7, 4, 9, 2, 5}; // 6
    std::vector<int> nums_2 = {1, 17, 5, 10, 13, 15, 10, 5, 16, 8}; // 7
    std::vector<int> nums_3 = {1, 2, 3, 4, 5, 6, 7, 8, 9}; // 2
    std::vector<int> nums_4 = {0, 0}; // 1
    std::vector<int> nums_5 = {0, 0, 0}; // 1
    std::vector<int> nums_6 = {1, 0, 0}; // 2

    Solution solve;
    auto ret_1 = solve.wiggleMaxLength(nums_1);
    assert(ret_1 == 6);

    auto ret_2 = solve.wiggleMaxLength(nums_2);
    assert(ret_2 == 7);

    auto ret_3 = solve.wiggleMaxLength(nums_3);
    assert(ret_3 == 2);

    auto ret_4 = solve.wiggleMaxLength(nums_4);
    assert(ret_4 == 1);

    auto ret_5 = solve.wiggleMaxLength(nums_5);
    assert(ret_5 == 1);

    auto ret_6 = solve.wiggleMaxLength(nums_6);
    assert(ret_6 == 2);

    return EXIT_SUCCESS;
}
