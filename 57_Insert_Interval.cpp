//
// Created by mincong.he on 2021/1/5.
//
#include "AlgoUtils.h"

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval) {
        vector<vector<int>> ret;
        if (intervals.empty()) {
            ret.emplace_back(newInterval);
            return ret;
        }

        intervals.emplace_back(newInterval);
        std::sort(intervals.begin(), intervals.end(), [](const auto &T1, const auto &T2) {
            return T1[0] < T2[0];
        });
        vector<int> contain_record(intervals.size(), 0);

        for (int i = 0; i < intervals.size(); ++i) {
            if (contain_record[i] == 1) continue;
            auto left_bound = intervals[i][0];
            auto right_bound = intervals[i][1];
            for (int j = i; j < intervals.size(); ++j) {
                auto next_left_bound = intervals[j][0];
                if (next_left_bound <= right_bound) {
                    contain_record[j] = 1;
                    right_bound = right_bound > intervals[j][1] ? right_bound : intervals[j][1];
                } else {
                    break;
                }
            }
            ret.emplace_back(vector<int>{left_bound, right_bound});
        }
        return ret;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<vector<int>> test_case_1{{1, 3},
                                    {6, 9}};
    vector<int> test_case_1_insert{2, 5};
    vector<vector<int>> test_case_1_ret{{1, 5},
                                        {6, 9}};
    assert(s.insert(test_case_1, test_case_1_insert) == test_case_1_ret);

    vector<vector<int>> test_case_2{{1,  2},
                                    {3,  5},
                                    {6,  7},
                                    {8,  10},
                                    {12, 16}};
    vector<int> test_case_2_insert{4, 8};
    vector<vector<int>> test_case_2_ret{{1,  2},
                                        {3,  10},
                                        {12, 16}};
    assert(s.insert(test_case_2, test_case_2_insert) == test_case_2_ret);

    vector<vector<int>> test_case_3;
    vector<int> test_case_3_insert{5, 7};
    vector<vector<int>> test_case_3_ret{{5, 7}};
    assert(s.insert(test_case_3, test_case_3_insert) == test_case_3_ret);

    vector<vector<int>> test_case_4{{1, 5}};
    vector<int> test_case_4_insert{2, 3};
    vector<vector<int>> test_case_4_ret{{1, 5}};
    assert(s.insert(test_case_4, test_case_4_insert) == test_case_4_ret);

    vector<vector<int>> test_case_5{{1, 5}};
    vector<int> test_case_5_insert{2, 7};
    vector<vector<int>> test_case_5_ret{{1, 7}};
    assert(s.insert(test_case_5, test_case_5_insert) == test_case_5_ret);

    return EXIT_SUCCESS;
}