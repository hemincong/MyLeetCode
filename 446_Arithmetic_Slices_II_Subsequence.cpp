#include <vector>
#include <unordered_map>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int> &nums) {
        int ret = 0;
        int n = nums.size();
        vector<unordered_map<long long, int>> f(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                long long d = (long long) nums[i] - (long long) nums[j];
                int pre_count = 0;
                if (f[j].find(d) == f[j].end()) {
                    f[j][d] = 0;
                } else {
                    pre_count = f[j][d];
                }
                ret += pre_count;
                f[i][d] += pre_count + 1;
            }
        }
        return ret;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> nums_1 = {2, 4, 6, 8, 10};
    EXPECT_EQ(s.numberOfArithmeticSlices(nums_1), 7);
    vector<int> nums_2 = {7, 7, 7, 7, 7};
    EXPECT_EQ(s.numberOfArithmeticSlices(nums_2), 16);
    return EXIT_SUCCESS;
}