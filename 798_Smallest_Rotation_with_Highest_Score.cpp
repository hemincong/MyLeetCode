#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int bestRotation(vector<int> &nums) {
        int n = nums.size();
        vector<int> move(n, 0);
        int ret = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] <= i) {
                move[0]++;
                move[(i - nums[i] + 1) % n]--;
                move[(i + 1) % n]++;
            } else {
                move[(i + 1) % n]++;
                move[(n - (nums[i] - i) + 1) % n]--;
            }
        }

        int score = 0;
        int max_s = 0;

        for (int m = 0; m < n; m++) {
            score += move[m];
            if (score > max_s) {
                max_s = score;
                ret = m;
            }
        }

        return ret;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> test_case_1{2, 3, 1, 4, 0};
    EXPECT_EQ(s.bestRotation(test_case_1), 3)
    vector<int> test_case_2{1, 3, 0, 2, 4};
    EXPECT_EQ(s.bestRotation(test_case_2), 0)

    return EXIT_SUCCESS;
}