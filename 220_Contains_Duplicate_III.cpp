//
// Created by mincong.he on 2021/4/17.
//

#include <vector>
#include <set>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
        set<long> s;
        for (int i = 0; i < nums.size(); ++i) {
            // 找到下界
            auto itr_low = s.lower_bound((long) nums[i] - t);
            // 下界存在，并且下界比上界小，就是存在
            if (itr_low != s.end() && *itr_low <= (long) nums[i] + t) return true;
            s.insert(nums[i]);
            // 滑动窗口
            if (i >= k) {
                s.erase(nums[i - k]);
            }
        }
        return false;
    }
};

int main(int argc, char **argv) {
    Solution s;
    std::vector<int> test_case_1{1, 2, 3, 1};
    EXPECT_TRUE(s.containsNearbyAlmostDuplicate(test_case_1, 3, 0));

    std::vector<int> test_case_2{1, 0, 1, 1};
    EXPECT_TRUE(s.containsNearbyAlmostDuplicate(test_case_2, 1, 2));

    std::vector<int> test_case_3{1, 5, 9, 1, 5, 9};
    EXPECT_FALSE(s.containsNearbyAlmostDuplicate(test_case_3, 2, 3));

    std::vector<int> test_case_4{2147483640, 2147483641};
    EXPECT_TRUE(s.containsNearbyAlmostDuplicate(test_case_4, 1, 100));

    return EXIT_SUCCESS;
}