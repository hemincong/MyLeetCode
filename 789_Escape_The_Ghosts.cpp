#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    bool escapeGhosts(vector<vector<int>> &ghosts, vector<int> &target) {
        auto dest = abs(target[0]) + abs(target[1]);
        for (const auto &g : ghosts) {
            auto dest_g_0 = abs(g[0] - target[0]);
            auto dest_g_1 = abs(g[1] - target[1]);
            if (dest_g_0 + dest_g_1 < dest + 1) {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char **argv) {
    vector<vector<vector<int>>> ghosts{
            {{1,  0}, {0,   3}},
            {{1,  0}},
            {{2,  0}},
            {{5,  0}, {-10, -2}, {0,  -5}, {-2, -2}, {-7, 1}},
            {{-1, 0}, {0,   1},  {-1, 0},  {0,  1},  {-1, 0}},
            {{1,  8}, {-9,  0},  {-7, -6}, {4,  3},  {1,  3}}
    };

    vector<vector<int>> targets{
            {0, 1},
            {2, 0},
            {1, 0},
            {7, 7},
            {0, 0},
            {6, -9}
    };
    vector<bool> ret{
            true,
            false,
            false,
            false,
            true,
            false
    };

    Solution s;

    for ( int i = 0; i < ret. size(); ++i) {
        if (ret[i]) {
            EXPECT_TRUE(s.escapeGhosts(ghosts[i], targets[i]));
        } else {
            EXPECT_FALSE(s.escapeGhosts(ghosts[i], targets[i]));
        }
    }

    return EXIT_SUCCESS;
}