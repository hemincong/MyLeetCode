//
// Created by mincong.he on 2021/3/1.
//

#include "AlgoUtils.h"
#include <vector>

using namespace std;

class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {
        if (matrix.empty()) return;
        auto m = matrix.size();
        auto n = matrix[0].size();
        _tmp = vector<vector<int>>(m, vector<int>(n + 1, 0));

        for (int i = 0; i < m; ++i) {
            for (int j = 1; j <= n; ++j) {
                _tmp[i][j] = _tmp[i][j - 1] + matrix[i][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for (int i = row1; i <= row2; ++i) {
            sum += _tmp[i][col2 + 1] - _tmp[i][col1];
        }
        return sum;
    }

private:
    vector<vector<int>> _tmp;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */

int main(int argc, char **argv) {
    vector<vector<int>> test_case_1{
            {3, 0, 1, 4, 2},
            {5, 6, 3, 2, 1},
            {1, 2, 0, 1, 5},
            {4, 1, 0, 1, 7},
            {1, 0, 3, 0, 5}
    };

    auto *obj = new NumMatrix(test_case_1);
    EXPECT_EQ(obj->sumRegion(2, 1, 4, 3), 8);
    EXPECT_EQ(obj->sumRegion(1, 1, 2, 2), 11);
    EXPECT_EQ(obj->sumRegion(1, 2, 2, 4), 12);
    delete (obj);

    return EXIT_SUCCESS;
}