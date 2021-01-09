//
// Created by mincong.he on 2021/1/9.
//

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int part = k % n;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin() + part, nums.end());
        reverse(nums.begin(), nums.begin() + part);
    }
};
