#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int search(vector<int> &nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        while (l < r) {
            int mid = l + ((r - l) >> 1);
            // 等于都会继续找下去，r会继续收缩，所以会找到第左边第一个，后面就不用两边扩展
            // 如果是等于马上break，后面就要两边数
            if (nums[mid] >= target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        int count = 0;
        while (l < n && nums[l++] == target) {
            count++;
        }
        return count;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> test_case_1{5, 7, 7, 8, 8, 10};
    EXPECT_EQ(s.search(test_case_1, 8), 2)
    EXPECT_EQ(s.search(test_case_1, 6), 0)
    return EXIT_SUCCESS;
}