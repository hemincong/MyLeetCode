#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int sumOddLengthSubarrays(vector<int> &arr) {
        int n = arr.size();
        int ret = 0;
        for (int i = 0; i < n; ++i) {
            int l = i + 1;
            int r = n - i;
            int l_even = (l + 1) / 2;
            int r_even = (r + 1) / 2;
            int l_odd = l / 2;
            int r_odd = r / 2;
            ret += (l_even * r_even + l_odd * r_odd) * arr[i];
        }
        return ret;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> test_case_1{1, 4, 2, 5, 3};
    EXPECT_EQ(s.sumOddLengthSubarrays(test_case_1), 58)
    vector<int> test_case_2{1, 2};
    EXPECT_EQ(s.sumOddLengthSubarrays(test_case_2), 3)
    vector<int> test_case_3{10, 11, 12};
    EXPECT_EQ(s.sumOddLengthSubarrays(test_case_3), 66)
    return EXIT_SUCCESS;
}