//
// Created by mincong.he on 2021/1/13.
//

#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        vector<int> ret;
        if (edges.empty()) return ret;
        int edges_max = 0;
        for (const auto &e : edges) {
            if (e[0] > edges_max) edges_max = e[0];
            if (e[1] > edges_max) edges_max = e[1];
        }
        for (int i = 0; i <= edges_max; ++i) {
            parents.emplace_back(i);
        }

        for (const auto &e : edges) {
            auto root_1 = find(e[0]);
            auto root_2 = find(e[1]);
            if (root_1 != root_2) {
                unity(e[0], e[1]);
            } else {
                ret = e;
            }
        }

        return ret;
    }

private:
    void unity(int p, int q) {
        auto root = find(p);
        parents[root] = find(q);
    }

    int find(int p) {
        if (parents[p] == p) return parents[p];

        parents[p] = find(parents[p]);
        return parents[p];
    }

    vector<int> parents;
};

int main(int argc, char **argv) {
    Solution s;
    vector<vector<int>> test_case_1{{1, 2},
                                    {1, 3},
                                    {2, 3}};
    vector<vector<int>> test_case_2{{1, 2},
                                    {2, 3},
                                    {3, 4},
                                    {1, 4},
                                    {1, 5}};
    printArray(s.findRedundantConnection(test_case_1));
    Solution s_2;
    std::cout << std::endl;
    printArray(s_2.findRedundantConnection(test_case_2));
    return EXIT_SUCCESS;
}