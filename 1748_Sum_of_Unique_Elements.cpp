//
// Created by mincong.he on 2022/2/8.
//

class Solution {
public:
    int sumOfUnique(vector<int> &nums) {
        std::vector<int> count(101, 0);
        for (auto n: nums) {
            count[n]++;
        }
        int sum = 0;
        for (int i = 0; i < count.size(); ++i) {
            if (count[i] == 1) {
                sum += i;
            }
        }
        return sum;
    }
};