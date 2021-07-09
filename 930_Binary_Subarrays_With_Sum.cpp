#include <vector>
#include <unordered_map>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int> &nums, int goal) {
        int sum = 0;
        int ret = 0;
        unordered_map<int, int> cnt;
        for (auto &n: nums) {
            cnt[sum]++;
            sum += n;
            ret += cnt[sum - goal];
        }
        return ret;
    }
};

class Solution_2 {
public:
    int numSubarraysWithSum(vector<int> &nums, int goal) {
        auto n = nums.size();
        int left_1 = 0;
        int left_2 = 0;
        int right = 0;
        int ret = 0;
        int sum_1 = 0;
        int sum_2 = 0;
        while (right < n) {
            sum_1 += nums[right];

            while (left_1 <= right && sum_1 > goal) {
                sum_1 -= nums[left_1];
                left_1++;
            }

            sum_2 += nums[right];
            while (left_2 <= right && sum_2 >= goal) {
                sum_2 -= nums[left_2];
                left_2++;
            }
            ret += (left_2 - left_1);
            right++;
        }
        return ret;
    }
};

int main(int argc, char **argv) {
    Solution s;
    Solution_2 s_2;
    vector<int> test_case_1{1, 0, 1, 0, 1};
    EXPECT_EQ(s.numSubarraysWithSum(test_case_1, 2), 4);
    EXPECT_EQ(s_2.numSubarraysWithSum(test_case_1, 2), 4);
    vector<int> test_case_2{0, 0, 0, 0, 0};
    EXPECT_EQ(s.numSubarraysWithSum(test_case_2, 0), 15);
    EXPECT_EQ(s_2.numSubarraysWithSum(test_case_2, 0), 15);
    return EXIT_SUCCESS;
}