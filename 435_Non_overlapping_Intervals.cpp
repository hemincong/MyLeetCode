//
// Created by mincong.he on 2021/1/1.
//
#include "AlgoUtils.h"

#include <vector>

using namespace std;

bool compare(const std::vector<int> &a, const std::vector<int> &b) {
    return a.at(1) < b.at(1);
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals) {
        if (intervals.empty()) return 0;

        int count = 0;
        sort(intervals.begin(), intervals.end(), compare);
        int high_bound = INT_MIN;

        for (const auto &i : intervals) {
            if (i[0] >= high_bound) {
                high_bound = i[1];
            } else {
                count++;
            }
        }

        return count;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<vector<int>> test_case_1{{1, 2},
                                    {2, 3},
                                    {3, 4},
                                    {1, 3}};
    vector<vector<int>> test_case_2{{1, 2},
                                    {1, 2},
                                    {1, 2}};
    vector<vector<int>> test_case_3{{1, 2},
                                    {2, 3}};
    vector<vector<int>> test_case_4{{1,    2},
                                    {2,    3},
                                    {3,    4},
                                    {-100, -2},
                                    {5,    7}};

    EXPECT_EQ(s.eraseOverlapIntervals(test_case_1), 1);
    EXPECT_EQ(s.eraseOverlapIntervals(test_case_2), 2);
    EXPECT_EQ(s.eraseOverlapIntervals(test_case_3), 0);
    EXPECT_EQ(s.eraseOverlapIntervals(test_case_4), 0);
    return EXIT_SUCCESS;
}