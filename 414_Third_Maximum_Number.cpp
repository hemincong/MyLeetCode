#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int thirdMax(vector<int> &nums) {
        long a = LONG_MIN;
        long b = LONG_MIN;
        long c = LONG_MIN;

        auto n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return nums[0] > nums[1] ? nums[0] : nums[1];
        for (int i = 0; i < n; ++i) {
            if (nums[i] > a) {
                c = b;
                b = a;
                a = nums[i];
            } else if (nums[i] > b && nums[i] != a) {
                c = b;
                b = nums[i];
            } else if (nums[i] >= c && nums[i] != b && nums[i] != a) {
                c = nums[i];
            }
        }
        if (c == LONG_MIN) return a; else return c;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> test_case_1{2, 2, 3, 1};
    EXPECT_EQ(s.thirdMax(test_case_1), 1);
    vector<int> test_case_2{1, 1, 2};
    EXPECT_EQ(s.thirdMax(test_case_2), 2);
    vector<int> test_case_3{1, 2, 2, 5, 3, 5};
    EXPECT_EQ(s.thirdMax(test_case_3), 2);
    vector<int> test_case_4{1, 2, -2147483648};
    EXPECT_EQ(s.thirdMax(test_case_4), -2147483648);
    vector<int> test_case_5{1, 2};
    EXPECT_EQ(s.thirdMax(test_case_5), 2);
    return EXIT_SUCCESS;
}