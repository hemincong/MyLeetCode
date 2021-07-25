#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int missingNumber(vector<int> &nums) {
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r) {
            auto mid = l + ((r - l) >> 1);
            if (nums[mid] == mid) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return l;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> test_case_1{0, 1, 3};
    vector<int> test_case_2{0, 1, 2, 3, 4, 5, 6, 7, 9};
    vector<int> test_case_3{0};
    vector<int> test_case_4{1, 2};
    vector<int> test_case_5{0, 2, 3};
    EXPECT_EQ(s.missingNumber(test_case_1), 2);
    EXPECT_EQ(s.missingNumber(test_case_2), 8);
    EXPECT_EQ(s.missingNumber(test_case_3), 1);
    EXPECT_EQ(s.missingNumber(test_case_4), 0);
    EXPECT_EQ(s.missingNumber(test_case_5), 1);
    return EXIT_SUCCESS;
}