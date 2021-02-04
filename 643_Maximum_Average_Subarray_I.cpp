//
// Created by mincong.he on 2021/2/4.
//

#include "AlgoUtils.h"
#include <vector>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int> &nums, int k) {
        auto n = nums.size();
        if (n < 1) return n;
        long sum = 0;
        for (int i = 0; i < k; ++i) {
            sum += nums[i];
        }

        auto max = sum;
        for (int i = 0; i < n - k; ++i) {
            sum = sum - nums[i] + nums[i + k];
            if (sum > max) max = sum;
        }
        return 1.0 * max / k;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> test_case_1{1, 12, -5, -6, 50, 3};
    std::cout << s.findMaxAverage(test_case_1, 4) << std::endl << 12.75f << std::endl;
    return EXIT_SUCCESS;
}