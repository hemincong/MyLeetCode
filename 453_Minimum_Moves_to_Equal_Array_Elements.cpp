//
// Created by mincong.he on 2021/10/21.
//

class Solution {
public:
    int minMoves(vector<int> &nums) {
        int sum = 0;
        int min_num = *min_element(nums.begin(), nums.end());
        for (auto n: nums) {
            sum += n - min_num;
        }
        return sum;

    }
};