//
// Created by mincong.he on 2021/7/2.
//

#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        if (n == 0) return false;

        int i = 0;
        int j = n - 1;
        while (i < m && j >= 0) {
            if (matrix[i][j] == target) return true;
            else if (matrix[i][j] > target) {
                j--;
            } else {
                i++;
            }
        }

        return false;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<vector<int>> test_case_1{{1,  4,  7,  11, 15},
                                    {2,  5,  8,  12, 19},
                                    {3,  6,  9,  16, 22},
                                    {10, 13, 14, 17, 24},
                                    {18, 21, 23, 26, 30}};
    EXPECT_TRUE(s.searchMatrix(test_case_1, 5));
    EXPECT_FALSE(s.searchMatrix(test_case_1, 20));
    vector<vector<int>> test_case_2{{-5}};
    EXPECT_TRUE(s.searchMatrix(test_case_2, -5));
    vector<vector<int>> test_case_3{{1, 1}};
    EXPECT_FALSE(s.searchMatrix(test_case_3, 2));
    vector<vector<int>> test_case_4{{1,  2,  3,  4,  5},
                                    {6,  7,  8,  9,  10},
                                    {11, 12, 13, 14, 15},
                                    {16, 17, 18, 19, 20},
                                    {21, 22, 23, 24, 25}};
    EXPECT_TRUE(s.searchMatrix(test_case_4, 19));
    vector<vector<int>> test_case_5{{-1, 3}};
    EXPECT_TRUE(s.searchMatrix(test_case_5, -1));
    return EXIT_SUCCESS;
}