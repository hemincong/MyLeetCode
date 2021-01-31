//
// Created by mincong.he on 2021/1/31.
//

#include "AlgoUtils.h"
#include <vector>

using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>> &grid) {
        if (grid.empty()) return 0;
        auto n = grid.size();
        auto N = n * n;

        _parent.resize(N);
        for (int i = 0; i < N; ++i) {
            _parent[i] = i;
        }

        // 必定一个水位只有一个位置？？？
        _index.resize(N);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                _index[grid[i][j]] = std::move(make_pair(i, j));
            }
        }

        for (int i = 0; i < N; ++i) {
            auto pos_pair = _index[i];
            for (const auto &d_pair : dest) {
                auto new_pos_x = pos_pair.first + d_pair.first;
                auto new_pos_y = pos_pair.second + d_pair.second;
                if (new_pos_x >= 0 && new_pos_x < n && new_pos_y >= 0 && new_pos_y < n &&
                    grid[new_pos_x][new_pos_y] <= i) {
                    _union(pos_pair.first * n + pos_pair.second, new_pos_x * n + new_pos_y);
                }
                if (_is_conected(0, N - 1)) return i;
            }
        }

        return -1;
    }

private:

    const vector<pair<int, int>> dest{
            {0,  1},
            {0,  -1},
            {1,  0},
            {-1, 0},
    };

    void _union(int p, int q) {
        if (_is_conected(p, q)) return;
        _parent[_find(p)] = _find(q);
    }

    bool _is_conected(int p, int q) {
        auto p_root = _find(p);
        auto q_root = _find(q);

        return p_root == q_root;
    }

    int _find(int x) {
        if (_parent[x] == x) return _parent[x];
        _parent[x] = _find(_parent[x]);
        return _parent[x];
    }

    vector<int> _parent;
    vector<pair<int, int>> _index;
};

int main(int argc, char **argv) {
    Solution s1;
    vector<vector<int>> test_case_1{{0, 2},
                                    {1, 3}};
    EXPECT_EQ(s1.swimInWater(test_case_1), 3);

    Solution s2;
    vector<vector<int>> test_case_2{{0,  1,  2,  3,  4},
                                    {24, 23, 22, 21, 5},
                                    {12, 13, 14, 15, 16},
                                    {11, 17, 18, 19, 20},
                                    {10, 9,  8,  7,  6}};
    EXPECT_EQ(s2.swimInWater(test_case_2), 16);
    return EXIT_SUCCESS;
}