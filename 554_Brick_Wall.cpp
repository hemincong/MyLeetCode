//
// Created by mincong.he on 2021/5/2.
//
#include <vector>
#include <unordered_map>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int leastBricks(vector<vector<int>> &wall) {
        if (wall.empty()) return 0;

        unordered_map<int, int> count_map;
        for (auto &i: wall) {
            int pos = 0;
            for (int j = 0; j < i.size() - 1; ++j) {
                pos += i[j];
                count_map[pos]++;
            }
        }

        int max_count = 0;
        for (auto &p : count_map) {
            if (p.second > max_count) max_count = p.second;
        }
        return wall.size() - max_count;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<vector<int>> test_case_1{{1, 2, 2, 1},
                                    {3, 1, 2},
                                    {1, 3, 2},
                                    {2, 4},
                                    {3, 1, 2},
                                    {1, 3, 1, 1}};
    vector<vector<int>> test_case_2{{1},
                                    {1},
                                    {1}};
    EXPECT_EQ(s.leastBricks(test_case_1), 2);
    EXPECT_EQ(s.leastBricks(test_case_2), 3);
    return EXIT_SUCCESS;
}