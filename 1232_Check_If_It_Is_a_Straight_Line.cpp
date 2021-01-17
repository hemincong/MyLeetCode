//
// Created by mincong.he on 2021/1/17.
//

#include "AlgoUtils.h"

#include <vector>

using namespace std;

class Solution {
public:
    bool checkStraightLine(vector<vector<int>> &coordinates) {
        if (coordinates.size() < 3) return true;
        const auto delta_y = coordinates[1][1] - coordinates[0][1];
        const auto delta_x = coordinates[1][0] - coordinates[0][0];
        for (int i = 2; i < coordinates.size(); ++i) {
            auto k_1 = (coordinates[i][1] - coordinates[0][1]) * delta_x;
            auto k_2 = (coordinates[i][0] - coordinates[0][0]) * delta_y;
            if (k_1 != k_2) return false;
        }
        return true;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<vector<int>> test_case_1{{1, 2},
                                    {2, 3},
                                    {3, 4},
                                    {4, 5},
                                    {5, 6},
                                    {6, 7}};
    vector<vector<int>> test_case_2{{1, 1},
                                    {2, 2},
                                    {3, 4},
                                    {4, 5},
                                    {5, 6},
                                    {7, 7}};
    vector<vector<int>> test_case_3{{0, 0},{0, 1}, {0, -1}};
    EXPECT_TRUE(s.checkStraightLine(test_case_1));
    EXPECT_FALSE(s.checkStraightLine(test_case_2));
    EXPECT_TRUE(s.checkStraightLine(test_case_3));
    return EXIT_SUCCESS;
}