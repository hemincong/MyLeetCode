#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int triangleNumber(vector<int> &nums) {
        std::sort(nums.begin(), nums.end());

        auto n = nums.size();

        int ret = 0;
        for (int i = n - 1; i > 1; --i) {
            int l = 0;
            int h = i - 1;
            while (l < h) {
                if (nums[l] + nums[h] > nums[i]) {
                    ret += h - l;
                    h--;
                } else {
                    l++;
                }
            }
        }
        return ret;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> test_case_1{2, 2, 3, 4};
    EXPECT_EQ(s.triangleNumber(test_case_1), 3)
    vector<int> test_case_2{4, 2, 3, 4};
    EXPECT_EQ(s.triangleNumber(test_case_2), 4)
    return EXIT_SUCCESS;
}