//
// Created by mincong.he on 2021/3/21.
//

#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>> &matrix) {
        const auto m = matrix.size();
        const auto n = matrix[0].size();
        bool col_flag = false;
        bool row_flag = false;
        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] == 0) {
                col_flag = true;
                break;
            }
        }

        for (int i = 0; i < n; ++i) {
            if (matrix[0][i] == 0) {
                row_flag = true;
                break;
            }
        }


        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        if (col_flag) {
            for (int j = 0; j < m; ++j) {
                matrix[j][0] = 0;
            }
        }

        if (row_flag) {
            for (int i = 0; i < n; ++i) {
                matrix[0][i] = 0;
            }
        }
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<vector<int>> test_case_1{{1, 1, 1},
                                    {1, 0, 1},
                                    {1, 1, 1}};
    s.setZeroes(test_case_1);
    printMatrix(test_case_1);

    vector<vector<int>> test_case_2{{0, 1, 2, 0},
                                    {3, 4, 5, 2},
                                    {1, 3, 1, 5}};
    s.setZeroes(test_case_2);
    printMatrix(test_case_2);

    vector<vector<int>> test_case_3{{1, 0}};
    s.setZeroes(test_case_3);
    printMatrix(test_case_3);

    vector<vector<int>> test_case_4{{1, 0, 3}};
    s.setZeroes(test_case_4);
    printMatrix(test_case_4);

    return EXIT_SUCCESS;
}