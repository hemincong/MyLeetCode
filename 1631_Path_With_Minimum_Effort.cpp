//
// Created by mincong.he on 2021/1/31.
//

#include "AlgoUtils.h"
#include <vector>

using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>> &heights) {
        if (heights.empty()) return 0;
        auto m = heights.size();
        auto n = heights[0].size();
        auto num = m * n;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int id = i * n + j;
                if (i > 0) {
                    _edges.emplace_back(id - n, id, abs(heights[i][j] - heights[i - 1][j]));
                }
                if (j > 0) {
                    _edges.emplace_back(id - 1, id, abs(heights[i][j] - heights[i][j - 1]));
                }
            }
        }
        sort(_edges.begin(), _edges.end(), [](const auto &e1, const auto &e2) {
            auto&&[x1, y1, v1] = e1;
            auto&&[x2, y2, v2] = e2;
            return v1 < v2;
        });

        _parent.resize(num);
        for (int i = 0; i < num; ++i) {
            _parent[i] = i;
        }

        int ret;
        for (const auto[x, y, v]:_edges) {
            _union(x, y);
            if (_is_conected(0, num - 1)) {
                ret = v;
                break;
            }
        }

        return ret;
    }

private:
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
    vector<tuple<int, int, int>> _edges;
};

int main(int argc, char **argv) {
    Solution s1;
    vector<vector<int>> test_case_1{{1, 2, 2},
                                    {3, 8, 2},
                                    {5, 3, 5}};
    EXPECT_EQ(s1.minimumEffortPath(test_case_1), 2);

    Solution s2;
    vector<vector<int>> test_case_2{{1, 2, 3},
                                    {3, 8, 4},
                                    {5, 3, 5}};
    EXPECT_EQ(s2.minimumEffortPath(test_case_2), 1);

    Solution s3;
    vector<vector<int>> test_case_3{{1, 2, 1, 1, 1},
                                    {1, 2, 1, 2, 1},
                                    {1, 2, 1, 2, 1},
                                    {1, 2, 1, 2, 1},
                                    {1, 1, 1, 2, 1}};
    EXPECT_EQ(s3.minimumEffortPath(test_case_3), 0);
    return EXIT_SUCCESS;
}