//
// Created by mincong.he on 2021/1/3.
//

#include "AlgoUtils.h"
#include <vector>

using namespace std;


class Solution {
public:
    int maximumUnits(vector<vector<int>> &boxTypes, int truckSize) {
        if (boxTypes.empty()) return 0;
        std::sort(boxTypes.begin(), boxTypes.end(), [](const auto &T1, const auto &T2) {
            return T1[1] > T2[1];
        });

        int count = 0;
        for (const auto &b : boxTypes) {
            int min = b[0] < truckSize ? b[0] : truckSize;
            count += min * b[1];
            truckSize -= min;
            if (truckSize == 0) break;
        }
        return count;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<vector<int>> test_case_1{{1, 3},
                                    {2, 2},
                                    {3, 1}};
    vector<vector<int>> test_case_2{{5, 10},
                                    {2, 5},
                                    {4, 7},
                                    {3, 9}};
    EXPECT_EQ(s.maximumUnits(test_case_1, 4), 8);
    EXPECT_EQ(s.maximumUnits(test_case_2, 10), 91);
    return EXIT_SUCCESS;
}