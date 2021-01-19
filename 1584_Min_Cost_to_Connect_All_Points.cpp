//
// Created by mincong.he on 2021/1/19.
//
#include "AlgoUtils.h"

#include <vector>

using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>> &points) {
        int ret = 0;
        auto n = points.size();
        if (n < 2) return ret;
        std::vector<tuple<int, int, int>> edges;

        for (int i = 0; i < n; ++i) {
            _parents.push_back(i);
            for (int j = i + 1; j < n; ++j) {
                edges.emplace_back(_distance(points[i], points[j]), i, j);
            }
        }

        sort(edges.begin(), edges.end(), [](const auto &t1, const auto &t2) {
            return std::get<0>(t1) < std::get<0>(t2);
        });

        int num = 0;
        for (auto&[d, x, y] : edges) {
            if (_union(x, y)) {
                ret += d;
                num++;
                if (num == n) break;
            }
        }
        return ret;
    }

private:
    int _distance(const vector<int> &p1, const vector<int> &p2) {
        return std::abs(p1[0] - p2[0]) + std::abs(p1[1] - p2[1]);
    }

    bool _union(int p, int q) {
        auto p_root = _find(p);
        auto q_root = _find(q);

        if (p_root == q_root) return false;

        _parents[p_root] = q_root;
        return true;
    }

    int _find(int p) {
        if (_parents[p] == p) return p;

        if (_parents[p] != p) {
            _parents[p] = _find(_parents[p]);
        }
        return _parents[p];
    }

    vector<int> _parents;
};

int main(int argc, char **argv) {
    Solution s_1;
    vector<vector<int>> test_case_1{{0, 0},
                                    {2, 2},
                                    {3, 10},
                                    {5, 2},
                                    {7, 0}}; // 20
    Solution s_2;
    vector<vector<int>> test_case_2{{3,  12},
                                    {-2, 5},
                                    {-4, 1}}; // 18
    Solution s_3;
    vector<vector<int>> test_case_3{{0,  0},
                                    {1,  1},
                                    {1,  0},
                                    {-1, 1}}; // 4
    Solution s_4;
    vector<vector<int>> test_case_4{{-1000000, -1000000},
                                    {1000000,  1000000}}; // 4000000
    Solution s_5;
    vector<vector<int>> test_case_5{{0, 0}}; // 0
    EXPECT_EQ(s_1.minCostConnectPoints(test_case_1), 20);
    EXPECT_EQ(s_2.minCostConnectPoints(test_case_2), 18);
    EXPECT_EQ(s_3.minCostConnectPoints(test_case_3), 4);
    EXPECT_EQ(s_4.minCostConnectPoints(test_case_4), 4000000);
    EXPECT_EQ(s_5.minCostConnectPoints(test_case_5), 0);
    return EXIT_SUCCESS;
}