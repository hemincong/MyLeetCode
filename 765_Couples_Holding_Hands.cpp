//
// Created by mincong.he on 2021/2/14.
//

#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    Solution() : _parent(70) {
        for (int i = 0; i < 70; ++i) {
            _parent[i] = i;
        }
    }

    int minSwapsCouples(vector<int> &row) {
        int n = row.size();
        for (int i = 0; i < n / 2; i++) {
            _union(row[2 * i] / 2, row[2 * i + 1] / 2);
        }
        int count = 0;
        for (int i = 0; i < n / 2; ++i) {
            if (_parent[i] == i) count++;
        }
        return n / 2 - count;
    }

private:
    void _union(int p, int q) {
        auto p_root = _find_root(p);
        auto q_root = _find_root(q);
        if (p_root == q_root) return;

        _parent[p_root] = q_root;
    }

    int _find_root(int x) {
        if (_parent[x] == x) return _parent[x];

        _parent[x] = _find_root(_parent[x]);

        return _parent[x];
    }

    vector<int> _parent;
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> test_case_1{0, 2, 1, 3};
    EXPECT_EQ(s.minSwapsCouples(test_case_1), 1)

    Solution s_2;
    vector<int> test_case_2{3, 2, 0, 1};
    EXPECT_EQ(s_2.minSwapsCouples(test_case_2), 0)
    return EXIT_SUCCESS;
}