#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int> &nums) {
        auto n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        for (int i = 1; i < n; i++) {
            dp[i] = dp[i - 1] + nums[i];
        }
        return dp;
    }
};

int main(int argc, char **argv) {
    Solution s;
    return EXIT_SUCCESS;
}