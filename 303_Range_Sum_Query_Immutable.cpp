//
// Created by mincong.he on 2021/3/1.
//

#include "AlgoUtils.h"
#include <vector>

using namespace std;

class NumArray {
public:
    NumArray(vector<int> &nums) {
        if (nums.size() == 0) return;
        _sum = vector<int>(nums.size(), 0);
        _sum[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            _sum[i] = _sum[i - 1] + nums[i];
        }
    }

    int sumRange(int i, int j) {
        if (i == 0) return _sum[j];
        return _sum[j] - _sum[i - 1];
    }

private:
    vector<int> _sum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */

int main(int argc, char **argv) {

    vector<int> test_case_1{-2, 0, 3, -5, 2, -1};
    NumArray *obj = new NumArray(test_case_1);
    EXPECT_EQ(obj->sumRange(0, 2), 1); // return 1 ((-2) + 0 + 3)
    EXPECT_EQ(obj->sumRange(2, 5), -1); // return -1 (3 + (-5) + 2 + (-1))
    EXPECT_EQ(obj->sumRange(0, 5), -3); // return -3 ((-2) + 0 + 3 + (-5) + 2 + (-1))
    delete (obj);

    return EXIT_SUCCESS;
}