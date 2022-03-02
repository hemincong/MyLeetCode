//
// Created by mincong.he on 2022/2/18.
//

#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int findCenter(vector<vector<int>> &edges) {
        int n = edges.size();
        vector<int> count(n + 2, 0);
        for (const auto &e: edges) {
            auto from = e[0];
            auto to = e[1];
            count[from]++;
            count[to]++;
            if (count[from] == n) return from;
            if (count[to] == n) return to;
        }
        return 0;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<vector<int>> test_case_1{{1, 2},
                                    {2, 3},
                                    {4, 2}};
    EXPECT_EQ(s.findCenter(test_case_1), 2);
    vector<vector<int>> test_case_2{{1, 2},
                                    {5, 1},
                                    {1, 3},
                                    {1, 4}};
    EXPECT_EQ(s.findCenter(test_case_1), 2);
    return EXIT_SUCCESS;
}