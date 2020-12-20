//
// Created by mincong.he on 2020/12/19.
//

#include "AlgoUtils.h"

#include <vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>> &triangle) {
        if (triangle.empty()) return 0;

        int level = triangle.size();
        vector<vector<int>> ret(level, std::vector<int>(level, 0));

        ret[0][0] = triangle[0][0];

        for (int i = 1; i < level; ++i) {
            ret[i][0] = ret[i - 1][0] + triangle[i][0];
            for (int j = 1; j < i; ++j) {
                int curr_shortest;

                if (ret[i - 1][j - 1] < ret[i - 1][j]) {
                    curr_shortest = ret[i - 1][j - 1];
                } else {
                    curr_shortest = ret[i - 1][j];
                }
                ret[i][j] = triangle[i][j] + curr_shortest;
            }
            ret[i][i] = ret[i - 1][i - 1] + triangle[i][i];
        }

        auto min = std::min_element(ret[level - 1].begin(), ret[level - 1].end());
        return *min;
    }
};

int main(int argc, char **argv) {
    Solution s;
    auto test_case_1 = vector<vector<int>>{
            {2},
            {3, 4},
            {6, 5, 7},
            {4, 1, 8, 3}
    };
    EXPECT_EQ(s.minimumTotal(test_case_1), 11);

    auto test_case_2 = vector<vector<int>>{
            {7},
            {-5, 9},
            {6,  5,  2},
            {-8, -2, -7, 3},
            {-2, 6,  -6, -1, 4}
    };
    EXPECT_EQ(s.minimumTotal(test_case_2), -6);
    return EXIT_SUCCESS;
}