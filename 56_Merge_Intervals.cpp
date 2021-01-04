//
// Created by mincong.he on 2021/1/4.
//

#include "AlgoUtils.h"

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        if (intervals.empty()) return vector<vector<int>>();
        std::sort(intervals.begin(), intervals.end(), [](const auto &T1, const auto &T2) {
            return T1[0] < T2[0];
        });

        vector<vector<int>> ret;
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
    vector<vector<int>> test_case_1{{1,  3},
                                    {2,  6},
                                    {8,  10},
                                    {15, 18}};
    vector<vector<int>> test_case_2{{1, 4},
                                    {4, 5}};
    vector<vector<int>> test_case_3{{1, 4},
                                    {2, 3}};

    printMatrix(s.merge(test_case_1));
    printMatrix(s.merge(test_case_2));
    printMatrix(s.merge(test_case_3));
    return EXIT_SUCCESS;
}