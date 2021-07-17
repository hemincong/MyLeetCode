#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int> &arr) {
        auto n = arr.size();
        sort(arr.begin(), arr.end());
        arr[0] = 1;
        for (int i = 1; i < n; ++i) {
            if (arr[i] - arr[i - 1] >= 1) arr[i] = arr[i - 1] + 1;
        }
        return arr[n - 1];
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> test_case_1{2, 2, 1, 2, 1};
    EXPECT_EQ(s.maximumElementAfterDecrementingAndRearranging(test_case_1), 2)
    vector<int> test_case_2{100, 1, 1000};
    EXPECT_EQ(s.maximumElementAfterDecrementingAndRearranging(test_case_2), 3)
    vector<int> test_case_3{1, 2, 3, 4, 5};
    EXPECT_EQ(s.maximumElementAfterDecrementingAndRearranging(test_case_3), 5)
    return EXIT_SUCCESS;
}