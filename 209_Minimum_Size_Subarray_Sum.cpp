//
// Created by mincong.he on 2020/6/2.
//

#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int> &nums) {
        if (nums.empty()) return 0;
        int min_len = nums.size() + 1;
        int left_index = 0;
        int right_index = 0;
        int curr_sum = 0;

        // slide window
        while (right_index < nums.size()) {
            while (curr_sum < s && right_index < nums.size()) {
                curr_sum += nums[right_index];
                right_index++;
            }
            while (curr_sum >= s && left_index < right_index) {
                curr_sum -= nums[left_index];
                if (min_len > (right_index - left_index)) {
                    min_len = right_index - left_index;
                }
                left_index++;
            }
        }

        if (min_len < nums.size() + 1) return min_len;
        return 0;
    }
};

int main(int argc, char **argv) {
    vector<int> test_empty{};
    vector<int> test_case_1{2, 3, 1, 2, 4, 3};
    vector<int> test_case_2{2, 3, 1, 1, 1, 1};
    Solution solution;
    assert(solution.minSubArrayLen(7, test_case_1) == 2);
    assert(solution.minSubArrayLen(5, test_empty) == 0);
    assert(solution.minSubArrayLen(5, test_case_2) == 2);
    return EXIT_SUCCESS;
}