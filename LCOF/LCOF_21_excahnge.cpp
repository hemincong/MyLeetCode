#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        if (nums.empty()) return nums;
        auto r = nums.size() - 1;
        auto l = 0;
        while (l < r) {
            if (nums[l] % 2 != 0) l++;
            else if (nums[r] % 2 == 0) r--;
            else {
                swap(nums[l], nums[r]);
                l++;
                r--;
            }
        }
        return nums;
    }
};