//
// Created by mincong.he on 2022/2/11.
//

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());
        int min_delta = INT_MAX;
        for (int i = 0; i <= nums.size() - k; ++i) {
            min_delta = min(min_delta, nums[i + k - 1] - nums[i]);
        }
        return min_delta;
    }
};