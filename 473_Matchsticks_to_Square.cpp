//
// Created by mincong.he on 2020/11/30.
//

#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    bool makesquare(vector<int> &nums) {
        int sum = 0;
        for (const auto &n :nums) {
            sum += n;
        }
        if (sum % 4 != 0 || nums.empty()) return false;

        std::sort(nums.rbegin(), nums.rend());
        int side[4] = {0};
        return bfs(0, nums, sum / 4, side);
    }

private:
    bool bfs(int i, const vector<int> &nums, int target, int side[]) {
        if (i >= nums.size()
            && side[0] == target
            && side[1] == target
            && side[2] == target
            && side[3] == target) {
            return true;
        }

        auto n = nums[i];
        for (int j = 0; j < 4; ++j) {
            if (side[j] + n > target) continue;
            side[j] += n;
            if (bfs(i + 1, nums, target, side)) return true;
            side[j] -= n;
        }
        return false;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> case_1{1, 1, 2, 2, 2};
    EXPECT_TRUE(s.makesquare(case_1))
    vector<int> case_2{1, 2, 2, 2};
    EXPECT_TRUE(s.makesquare(case_2) == false)
    vector<int> case_3{3, 3, 3, 3, 4};
    EXPECT_TRUE(s.makesquare(case_3) == false)
    vector<int> case_4{6035753, 3826635, 922363, 6104805, 1189018, 6365253, 364948, 2725801, 5577769, 7857734, 2860709,
                       9554210, 4883540, 8712121, 3545089};
    EXPECT_TRUE(s.makesquare(case_4) == false)
}
