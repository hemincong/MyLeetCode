//
// Created by mincong.he on 2022/2/8.
//

#include <vector>
#include <set>
#include <map>
#include "AlgoUtils.h"

using namespace std;


class Solution {
    const vector<pair<int, int>> dirt{
            {0,  0}, // 中
            {1,  0}, // 右
            {-1, 0}, // 左
            {0,  1}, // 上
            {0,  -1}, // 下
            {1,  1}, // 右上
            {-1, 1}, // 左上
            {1,  -1}, // 右下
            {-1, -1}, // 左下
    };

public:
    vector<int> gridIllumination(int n, vector<vector<int>> &lamps, vector<vector<int>> &queries) {
        set<pair<int, int>> point;
        map<int, int> row, col, digonal, r_digonal;
        for (const auto &l: lamps) {
            auto x = l[0];
            auto y = l[1];
            if (point.find({x, y}) == point.end()) {
                point.insert({x, y});
                row[x]++;
                col[y]++;
                digonal[x - y]++;
                r_digonal[x + y]++;
            }
        }

        vector<int> ans;

        for (const auto &q: queries) {
            auto x = q[0];
            auto y = q[1];
            if (row[x] > 0 || col[y] > 0 || digonal[x - y] > 0 || r_digonal[x + y] > 0) {
                ans.push_back(1);
            } else {
                ans.push_back(0);
            }

            for (const auto &d: dirt) {
                auto new_x = x + d.first;
                auto new_y = y + d.second;

                if (point.find({new_x, new_y}) != point.end()) {
                    point.erase({new_x, new_y});
                    row[new_x]--;
                    col[new_y]--;
                    digonal[new_x - new_y]--;
                    r_digonal[new_x + new_y]--;
                }
            }
        }
        return ans;
    }
};

int main(int argc, char **argv) {
    Solution s;

    vector<int> ret_1{1, 0};
    vector<vector<int>> lamp_1{{0, 1},
                               {4, 4}};
    vector<vector<int>> queries_1{{1, 1},
                                  {1, 0}};
    assertArray(s.gridIllumination(5, lamp_1, queries_1), ret_1);

    vector<int> ret_2{1, 1};
    vector<vector<int>> lamp_2{{0, 0},
                               {4, 4}};
    vector<vector<int>> queries_2{{1, 1},
                                  {1, 1}};
    assertArray(s.gridIllumination(5, lamp_2, queries_2), ret_2);

    vector<int> ret_3{1, 1, 0};
    vector<vector<int>> lamp_3{{0, 0},
                               {0, 4}};
    vector<vector<int>> queries_3{{0, 4},
                                  {0, 1},
                                  {1, 4}};
    assertArray(s.gridIllumination(5, lamp_3, queries_3), ret_3);
    return EXIT_SUCCESS;
}