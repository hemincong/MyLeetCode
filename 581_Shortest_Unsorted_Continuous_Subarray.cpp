#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int> &nums) {
        int n = nums.size();
        int maxn = INT_MIN, right = -1;
        int minn = INT_MAX, left = -1;
        for (int i = 0; i < n; i++) {
            if (maxn > nums[i]) {
                right = i;
            } else {
                maxn = nums[i];
            }
        }
        for (int i = 0; i < n; i++) {
            if (minn < nums[n - i - 1]) {
                left = n - i - 1;
            } else {
                minn = nums[n - i - 1];
            }
        }
        return right == -1 ? 0 : right - left + 1;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> test_case_0{2, 1};
    EXPECT_EQ(s.findUnsortedSubarray(test_case_0), 2);
    vector<int> test_case_1{2, 6, 4, 8, 10, 9, 15};
    EXPECT_EQ(s.findUnsortedSubarray(test_case_1), 5);
    vector<int> test_case_2{1, 2, 3, 4};
    EXPECT_EQ(s.findUnsortedSubarray(test_case_2), 0);
    vector<int> test_case_3{1};
    EXPECT_EQ(s.findUnsortedSubarray(test_case_3), 0);
    vector<int> test_case_4{1, 3, 2, 2, 2};
    EXPECT_EQ(s.findUnsortedSubarray(test_case_4), 4);
    return EXIT_SUCCESS;
}