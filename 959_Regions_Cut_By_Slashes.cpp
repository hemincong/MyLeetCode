//
// Created by mincong.he on 2021/1/25.
//

#include "AlgoUtils.h"
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int regionsBySlashes(vector<string> &grid) {
        if (grid.empty()) return 0;

        auto n = grid.size();
        _parent.resize(n * n * 4);
        for (int i = 0; i < n * n * 4; ++i) {
            _parent[i] = i;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                auto index = i * n + j;
                // 上下
                if (i < n - 1) {
                    _union(index * 4 + 2, (index + n) * 4);
                }

                // 左右
                if (j < n - 1) {
                    _union(index * 4 + 1, (index + 1) * 4 + 3);
                }

                // 内部
                if (grid[i][j] == ' ') {
                    _union(index * 4, index * 4 + 1);
                    _union(index * 4 + 1, index * 4 + 2);
                    _union(index * 4 + 2, index * 4 + 3);
                } else if (grid[i][j] == '\\') {
                    _union(index * 4, index * 4 + 1);
                    _union(index * 4 + 2, index * 4 + 3);
                } else if (grid[i][j] == '/') {
                    _union(index * 4 + 1, index * 4 + 2);
                    _union(index * 4, index * 4 + 3);
                }
            }
        }

        int count = 0;
        for (int i = 0; i < _parent.size(); ++i) {
            if (_parent[i] == i) count++;
        }

        return count;
    }

private:
    void _union(int p, int q) {
        auto p_root = _find(p);
        auto q_root = _find(q);
        if (p_root == q_root) return;
        _parent[p_root] = q_root;
    }

    int _find(int x) {
        if (_parent[x] == x) return x;
        _parent[x] = _find(_parent[x]);
        return _parent[x];
    };
    vector<int> _parent;
};

int main(int argc, char **argv) {
    Solution s;
    vector<string> test_case_1{" /", "/ "};
    EXPECT_EQ(s.regionsBySlashes(test_case_1), 2);
    vector<string> test_case_2{" /", "  "};
    EXPECT_EQ(s.regionsBySlashes(test_case_2), 1);
    vector<string> test_case_3{"\\/", "/\\"};
    EXPECT_EQ(s.regionsBySlashes(test_case_3), 4);
    vector<string> test_case_4{"/\\", "\\/"};
    EXPECT_EQ(s.regionsBySlashes(test_case_4), 5);
    vector<string> test_case_5{"//", "/ "};
    EXPECT_EQ(s.regionsBySlashes(test_case_5), 3);

    return EXIT_SUCCESS;
}