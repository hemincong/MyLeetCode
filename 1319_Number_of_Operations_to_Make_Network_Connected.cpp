#include <vector>
#include <set>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int makeConnected(int n, vector<vector<int>> &connections) {
        _parent.resize(n);
        for (int i = 0; i < n; ++i) {
            _parent[i] = i;
        }

        int connected = 0;
        for (const auto &c : connections) {
            if (_find(c[0]) == _find(c[1])) {
                connected++;
            } else {
                _union(c[0], c[1]);
            }
        }

        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (_parent[i] == i) count++;
        }

        return connected >= count - 1 ? count - 1 : -1;
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
    }

    vector<int> _parent;
};

int main(int argc, char **argv) {
    Solution s;
    vector<vector<int>> connections_1{{0, 1},
                                      {0, 2},
                                      {1, 2}};
    int n_1 = 4;
    int ret_1 = 1;
    EXPECT_EQ(s.makeConnected(n_1, connections_1), ret_1);

    vector<vector<int>> connections_2{{0, 1},
                                      {0, 2},
                                      {0, 3},
                                      {1, 2},
                                      {1, 3}};
    int n_2 = 6;
    int ret_2 = 2;
    EXPECT_EQ(s.makeConnected(n_2, connections_2), ret_2);

    vector<vector<int>> connections_3{{0, 1},
                                      {0, 2},
                                      {0, 3},
                                      {1, 2}};
    int n_3 = 6;
    int ret_3 = -1;
    EXPECT_EQ(s.makeConnected(n_3, connections_3), ret_3);

    vector<vector<int>> connections_4{{0, 1},
                                      {0, 2},
                                      {3, 4},
                                      {2, 3}};
    int n_4 = 5;
    int ret_4 = 0;
    EXPECT_EQ(s.makeConnected(n_4, connections_4), ret_4);

    return EXIT_SUCCESS;
}