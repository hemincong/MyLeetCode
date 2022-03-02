//
// Created by mincong.he on 2022/2/24.
//

#include "AlgoUtils.h"
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findBall(vector<vector<int>> &grid) {
        auto m = grid.size();
        auto n = grid[0].size();
        vector<int> ret;
        for (int j = 0; j < n; ++j) {
            auto pos = j;
            for (int i = 0; i < m; ++i) {
                if (grid[i][pos] == 1 && pos + 1 < n && grid[i][pos + 1] == 1) {
                    pos++;
                } else if (grid[i][pos] == -1 && pos - 1 >= 0 && grid[i][pos - 1] == -1) {
                    pos--;
                } else {
                    pos = -1;
                    break;
                }
            }
            ret.push_back(pos);
        }
        return ret;
    }
};

int main(int argc, char **argv) {
    vector<vector<int>> grid_1{{1,  1,  1,  -1, -1},
                               {1,  1,  1,  -1, -1},
                               {-1, -1, -1, 1,  1},
                               {1,  1,  1,  1,  -1},
                               {-1, -1, -1, -1, -1}};
    vector<int> ret_1{1, -1, -1, -1, -1};
    vector<vector<int>> grid_2{{-1}};
    vector<int> ret_2{-1};
    vector<vector<int>> grid_3{{1,  1,  1,  1,  1,  1},
                               {-1, -1, -1, -1, -1, -1},
                               {1,  1,  1,  1,  1,  1},
                               {-1, -1, -1, -1, -1, -1}};
    vector<int> ret_3{0, 1, 2, 3, 4, -1};
    Solution s;
    assertArray(s.findBall(grid_1), ret_1);
    assertArray(s.findBall(grid_2), ret_2);
    assertArray(s.findBall(grid_3), ret_3);
    return EXIT_SUCCESS;
};