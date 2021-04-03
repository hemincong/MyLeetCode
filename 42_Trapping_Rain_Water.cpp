//
// Created by mincong.he on 2021/4/2.
//

#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int trap(vector<int> &height) {
        if (height.empty()) return 0;
        int max_height = *std::max_element(height.begin(), height.end());
        int n = height.size();

        vector<int> level_width(max_height + 1, 0);

        for (int i = 1; i <= max_height; ++i) {
            int left_bound = 0;
            while (left_bound < n && height[left_bound] < i) {
                left_bound++;
            }

            int right_bound = n - 1;
            while (right_bound >= left_bound && height[right_bound] < i) {
                right_bound--;
            }

            level_width[i] = right_bound - left_bound + 1;
        }

        int sum_1 = 0;
        for (int i : level_width) {
            sum_1 += i;
        }

        int sum_2 = 0;
        for (int i : height) {
            sum_2 += i;
        }

        return sum_1 - sum_2;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> test_case_1{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    EXPECT_EQ(s.trap(test_case_1), 6);
    return EXIT_SUCCESS;
}