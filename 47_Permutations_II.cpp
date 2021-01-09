//
// Created by mincong.he on 2021/1/9.
//
#include "AlgoUtils.h"

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        vector<vector<int>> ret;
        if (nums.empty()) return ret;

        sort(nums.begin(), nums.end());
        perm(ret, nums, 0, nums.size() - 1);

        return ret;
    }

private:
    void perm(vector<vector<int>> &ret, vector<int> nums, int left, int right) {
        if (left == right) {
            ret.push_back(nums);
            return;
        }

        for (int i = left; i <= right; i++) {
            if (i != left && nums[left] == nums[i]) continue;
            swap(nums[left], nums[i]);
            perm(ret, nums, left + 1, right);
        }
    }
};


int main(int argc, char **argv) {
    Solution s;
    vector<int> test_case_1{1, 1, 2};
    printMatrix(s.permuteUnique(test_case_1));
    vector<int> test_case_2{1, 2, 3};
    printMatrix(s.permuteUnique(test_case_2));
    vector<int> test_case_3{3, 3, 0, 3};
    printMatrix(s.permuteUnique(test_case_3));
    return EXIT_SUCCESS;
}