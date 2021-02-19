//
// Created by mincong.he on 2021/2/17.
//

#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &nums, int r, int c) {
        auto n_r = nums.size();
        auto n_c = nums[0].size();
        if (r * c != n_c * n_r) return nums;

        int c_i = 0;
        vector<vector<int>> ret;
        vector<int> tmp_row;
        tmp_row.reserve(c);
        for (int i = 0; i < n_r; ++i) {
            for (int j = 0; j < n_c; ++j) {
                if (c_i >= c) {
                    ret.emplace_back(tmp_row);
                    c_i = 0;
                    tmp_row.clear();
                    tmp_row.reserve(c);
                }

                tmp_row.push_back(nums[i][j]);
                c_i++;
            }
        }
        ret.push_back(tmp_row);
        return ret;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<vector<int>> test_case_1{{1, 2},
                                    {3, 4}};
    printMatrix(s.matrixReshape(test_case_1, 1, 4));
    printMatrix(s.matrixReshape(test_case_1, 2, 4));
    printMatrix(s.matrixReshape(test_case_1, 4, 1));

    return EXIT_SUCCESS;
}