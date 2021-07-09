//
// Created by mincong.he on 2021/7/1.
//

#include <vector>
#include "../AlgoUtils.h"

using namespace std;

class Solution {
public:
    int numWays(int n, vector<vector<int>> &relation, int k) {
        vector<vector<int>> road_map(n, vector<int>(n, 0));
        for (auto r : relation) {
            auto i = r[0];
            auto j = r[1];
            road_map[i][j] = 1;
        }
        int count = 0;
        dfs(n, road_map, 0, k, count);
        return count;
    }

private:
    void dfs(int n, const vector<vector<int>> &road_map, int curr_pos, int k, int &count) {
        if (k == 0 && curr_pos == n - 1) {
            count++;
            return;
        } else if (k == 0) {
            return;
        }

        auto r = road_map[curr_pos];
        for (int i = 0; i < r.size(); ++i) {
            if (r[i] == 1) {
                dfs(n, road_map, i, k - 1, count);
            }
        }
    }
};

int main(int argc, char **argv) {
    Solution s;
    auto test_case_1 = vector<vector<int>>{
            {0, 2},
            {2, 1},
            {3, 4},
            {2, 3},
            {1, 4},
            {2, 0},
            {0, 4},
    };
    EXPECT_EQ(s.numWays(5, test_case_1, 3), 3);

    auto test_case_2 = vector<vector<int>>{
            {0, 2},
            {2, 1},
    };
    EXPECT_EQ(s.numWays(3, test_case_2, 2), 0);

    return EXIT_SUCCESS;
}