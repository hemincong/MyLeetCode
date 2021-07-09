//
// Created by mincong.he on 2021/7/4.
//

#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int> &nums) {
        vector<int> ret{0, 0};
        vector<int> m(nums.size() + 1, 0);

        for (auto n : nums) {
            m[n]++;
        }

        for (int i = 1; i <= nums.size(); ++i) {
            if (m[i] > 1) {
                ret[0] = i;
            }
            if (m[i] == 0) {
                ret[1] = i;
            }
        }
        return ret;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> test_case_1{1, 2, 2, 4};
    vector<int> ret_1{2, 3};
    vector<int> test_case_2{1, 1};
    vector<int> ret_2{1, 2};
    assertArray(s.findErrorNums(test_case_1), ret_1);
    assertArray(s.findErrorNums(test_case_2), ret_2);
    return EXIT_SUCCESS;
}