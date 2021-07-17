#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    const int mod = 1e9 + 7;

    int minAbsoluteSumDiff(vector<int> &nums1, vector<int> &nums2) {
        long abs_sum = 0;
        int n = nums1.size();
        vector<int> abs_array(n, 0);
        for (int i = 0; i < n; ++i) {
            abs_array[i] = std::abs(nums1[i] - nums2[i]);
            abs_sum += abs_array[i];
        }
        sort(nums1.begin(), nums1.end());
        int temp_max = INT_MIN;
        for (int i = 0; i < n; ++i) {
            int l = 0, r = n - 1;
            while (l < r) {
                int mid = (l + r + 1) >> 1;
                if (nums1[mid] <= nums2[i]) l = mid;
                else r = mid - 1;
            }
            int t = abs(nums1[l] - nums2[i]);
            if (l + 1 < n) t = min(t, abs(nums1[l + 1] - nums2[i]));
            temp_max = max(temp_max, abs_array[i] - t);
        }
        return (abs_sum - temp_max) % mod;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> nums1 = {1, 7, 5};
    vector<int> nums2 = {2, 3, 5};
    EXPECT_EQ(s.minAbsoluteSumDiff(nums1, nums2), 3);
    nums1 = {2, 4, 6, 8, 10};
    nums2 = {2, 4, 6, 8, 10};
    EXPECT_EQ(s.minAbsoluteSumDiff(nums1, nums2), 0);
    nums1 = {1, 10, 4, 4, 2, 7};
    nums2 = {9, 3, 5, 1, 7, 4};
    EXPECT_EQ(s.minAbsoluteSumDiff(nums1, nums2), 20);

    return EXIT_SUCCESS;
}