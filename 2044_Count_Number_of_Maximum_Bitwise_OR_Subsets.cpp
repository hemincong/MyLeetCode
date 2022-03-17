#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int countMaxOrSubsets(vector<int> &nums) {
        int max_value = INT_MIN;
        int count = 0;
        auto n = nums.size();
        int total_state = 1 << n;
        for (int i = 0; i < total_state; ++i) {
            int cur = 0;
            for (int j = 0; j < n; ++j) {
                if ((i >> j) & 1 == 1) {
                    cur |= nums[j];
                }
            }
            if (max_value < cur) {
                count = 1;
                max_value = cur;
            } else if (max_value == cur) {
                count++;

            }
        }
        return count;
    }
};

int main(int argc, char **argv) {
    Solution s;
    return EXIT_SUCCESS;
}