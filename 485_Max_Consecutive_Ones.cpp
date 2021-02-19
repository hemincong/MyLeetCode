//
// Created by mincong.he on 2021/2/15.
//

#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int> &nums) {
        auto n = nums.size();
        if (n < 1) return n;
        int max_count = 0;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                count++;
                if (count > max_count) max_count = count;
            } else {
                count = 0;
            }
        }
        return max_count;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> test_case_1{1, 1, 0, 1, 1, 1};
    EXPECT_EQ(s.findMaxConsecutiveOnes(test_case_1), 3);
    return EXIT_SUCCESS;
}