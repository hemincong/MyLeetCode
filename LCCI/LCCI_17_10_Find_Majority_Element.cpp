#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &nums) {
        int c = -1;
        int count = 0;
        for (auto &n: nums) {
            if (count == 0) c = n;
            if (n == c) {
                count++;
            } else {
                count--;
            }
        }
        count = 0;
        for (auto &n: nums) {
            if (n == c) {
                count++;
            }
        }
        if (count > (nums.size() >> 1)) {
            return c;
        }
        return -1;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> test_case_1{1, 2, 5, 9, 5, 9, 5, 5, 5};
    vector<int> test_case_2{3, 2};
    vector<int> test_case_3{2, 2, 1, 1, 1, 2, 2};
    EXPECT_EQ(s.majorityElement(test_case_1), 5);
    EXPECT_EQ(s.majorityElement(test_case_2), -1);
    EXPECT_EQ(s.majorityElement(test_case_3), 2);
    return EXIT_SUCCESS;
}