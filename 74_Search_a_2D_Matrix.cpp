//
// Created by mincong.he on 2021/3/30.
//
#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        auto m = matrix.size();
        auto n = matrix[0].size();

        int i = 0, j = m - 1;
        while (i <= j) {
            int mid = i + ((j - i) >> 1);
            int cmp = matrix[mid][0];
            if (target > cmp) {
                i = mid + 1;
            } else if (target < cmp) {
                j = mid - 1;
            } else {
                return true;
            }
        }
        if (j < 0) j = 0;

        int k = 0, l = n - 1;
        while (k <= l) {
            int mid = k + ((l - k) >> 1);
            int cmp = matrix[j][mid];
            if (target > cmp) {
                k = mid + 1;
            } else if (target < cmp) {
                l = mid - 1;
            } else {
                return true;
            }
        }
        return false;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<vector<int>> test_case_1{{1,  3,  5,  7},
                                    {10, 11, 16, 20},
                                    {23, 30, 34, 60}};
    EXPECT_TRUE(s.searchMatrix(test_case_1, 3));
    EXPECT_FALSE(s.searchMatrix(test_case_1, 13));

    vector<vector<int>> test_case_2{{1}};
    EXPECT_FALSE(s.searchMatrix(test_case_2, 0));
    EXPECT_FALSE(s.searchMatrix(test_case_2, 2));

    vector<vector<int>> test_case_3{{1, 3}};
    EXPECT_TRUE(s.searchMatrix(test_case_3, 3));
    EXPECT_FALSE(s.searchMatrix(test_case_3, 2));

    vector<vector<int>> test_case_4{{1},
                                    {3}};
    EXPECT_TRUE(s.searchMatrix(test_case_4, 3));
    EXPECT_FALSE(s.searchMatrix(test_case_4, 2));
    return EXIT_SUCCESS;
}