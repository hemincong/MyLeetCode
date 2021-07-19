#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int maxFrequency(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int max = 1;
        long long total = 0;
        int l = 0;
        for (int r = 1; r < n; ++r) {
            total += (long long) (nums[r] - nums[r - 1]) * (r - l);
            while (l < r && total > k) {
                total -= (nums[r] - nums[l]);
                l++;
            }
            if (max < r - l + 1) max = r - l + 1;
        }
        return max;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> test_case_1{1, 2, 4};
    EXPECT_EQ(s.maxFrequency(test_case_1, 5), 3);
    vector<int> test_case_2{1, 4, 8, 13};
    EXPECT_EQ(s.maxFrequency(test_case_2, 5), 2);
    vector<int> test_case_3{3, 9, 6};
    EXPECT_EQ(s.maxFrequency(test_case_3, 2), 1);
    return EXIT_SUCCESS;
}