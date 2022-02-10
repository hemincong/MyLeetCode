//
// Created by mincong.he on 2021/1/16.
//

#include "AlgoUtils.h"

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> hitBricks(vector<vector<int>> &grid, vector<vector<int>> &hits) {
        auto m = grid.size();
        auto n = grid[0].size();
        int grid_size = m * n;
        _parent = vector<int>(grid_size + 1, 0);
        _size = vector<int>(grid_size + 1, 1);
        for (int i = 0; i < _parent.size(); ++i) {
            _parent[i] = i;
        }
        auto copy = grid;
        for (const auto &hit: hits) {
            copy[hit[0]][hit[1]] = 0;
        }

        for (int j = 0; j < n; ++j) {
            if (copy[0][j] == 1) {
                // size是屋顶
                _union(j, grid_size);
            }
        }

        // 屋顶已经处理
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (copy[i][j] == 1) {
                    // 上面
                    if (copy[i - 1][j] == 1) {
                        _union(_get_index(n, i - 1, j), _get_index(n, i, j));
                    }
                    // 左边
                    if (j > 0 && copy[i][j - 1] == 1) {
                        _union(_get_index(n, i, j - 1), _get_index(n, i, j));
                    }
                }
            }
        }

        auto res = vector<int>(hits.size());
        for (int i = hits.size() - 1; i >= 0; i--) {
            auto hit_x = hits[i][0];
            auto hit_y = hits[i][1];

            // 空的
            if (grid[hit_x][hit_y] == 0) {
                continue;
            }

            // 与屋顶的连接数
            int origin = _get_union_size(grid_size);

            // 屋顶
            if (hit_x == 0) {
                _union(hit_y, grid_size);
            }

            for (const auto &d: _destination) {
                int new_x = hit_x + d.first;
                int new_y = hit_y + d.second;

                if (new_x >= 0 && new_x < m && new_y >= 0 && new_y < n && copy[new_x][new_y] == 1) {
                    // 补回去
                    _union(_get_index(n, hit_x, hit_y), _get_index(n, new_x, new_y));
                }
            }

            // 补完之后的现在的连通数
            int current = _get_union_size(grid_size);

            res[i] = max(0, current - origin - 1);
            copy[hit_x][hit_y] = 1;
        }
        return res;
    }

private:
    int _get_index(int n, int i, int j) {
        return n * i + j;
    }

    void _union(int p, int q) {
        int root_p = _find(p);
        int root_q = _find(q);

        if (root_p == root_q) return;

        _parent[root_p] = root_q;
        _size[root_q] += _size[root_p];
    }

    int _find(int x) {
        if (x != _parent[x]) {
            _parent[x] = _find(_parent[x]);
        }

        return _parent[x];
    }

    int _get_union_size(int x) {
        auto r = _find(x);
        return _size[r];
    }

    vector<int> _parent;
    vector<int> _size;
    const vector<pair<int, int>> _destination{
            {0,  1},
            {0,  -1},
            {1,  0},
            {-1, 0},
    };
};

int main(int argc, char **argv) {
    vector<vector<int>> grid_1{
            {1, 0, 0, 0},
            {1, 1, 1, 0}
    };
    vector<vector<int>> hits_1{{1, 0}};
    vector<int> ret_1{2};
    Solution s_1;
    assertArray(s_1.hitBricks(grid_1, hits_1), ret_1);

    vector<vector<int>> grid_2{
            {1, 0, 0, 0},
            {1, 1, 0, 0}
    };
    vector<vector<int>> hits_2{
            {1, 1},
            {1, 0}
    };
    vector<int> ret_2{0, 0};
    Solution s_2;
    assertArray(s_2.hitBricks(grid_2, hits_2), ret_2);

    vector<vector<int>> grid_3{
            {1},
            {1},
            {1},
            {1},
            {1},
    };
    vector<vector<int>> hits_3{
            {3, 0},
            {4, 0},
            {1, 0},
            {2, 0},
            {0, 0},
    };
    vector<int> ret_3{1, 0, 1, 0, 0};
    Solution s_3;
    assertArray(s_3.hitBricks(grid_3, hits_3), ret_3);

    vector<vector<int>> grid_4{
            {1, 0, 1},
            {0, 0, 1},
    };
    vector<vector<int>> hits_4{
            {1, 0},
            {0, 0}
    };
    vector<int> ret_4{0, 0};
    Solution s_4;
    assertArray(s_3.hitBricks(grid_4, hits_4), ret_4);

    return EXIT_SUCCESS;
}