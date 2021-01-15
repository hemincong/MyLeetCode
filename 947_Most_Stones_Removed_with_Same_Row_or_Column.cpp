//
// Created by mincong.he on 2021/1/15.
//

#include "AlgoUtils.h"

#include <vector>

#include <map>

#include <unordered_map>

using namespace std;

class Solution {
public:
    Solution() : count(0) {
    }
    ~Solution() = default;

    int removeStones(vector<vector<int>> &stones) {
        int ret = 0;
        auto n = stones.size();
        if (n <= 1) return ret;

        for (const auto &s: stones) {
            union_(s[0] + 10001, s[1]);
        }

        return n - count;
    }

private:
    int find(int x) {
        if (parent.find(x) == parent.end()) {
            count++;
            parent[x] = x;
        }

        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }

        return parent[x];
    }

    void union_(int p, int q) {
        auto root_p = find(p);
        auto root_q = find(q);
        if (root_q == root_p) return;

        parent[root_p] = root_q;
        count--;
    }

    int count;
    std::unordered_map<int, int> parent;
};

int main(int argc, char **argv) {
    Solution s;
    vector<vector<int>> test_case_1{{0, 0},
                                    {0, 1},
                                    {1, 0},
                                    {1, 2},
                                    {2, 1},
                                    {2, 2}};
    EXPECT_EQ(s.removeStones(test_case_1), 5)
    Solution s_1;
    vector<vector<int>> test_case_2{{0, 0},
                                    {0, 2},
                                    {1, 1},
                                    {2, 0},
                                    {2, 2}};
    EXPECT_EQ(s_1.removeStones(test_case_2), 3)
    Solution s_2;
    vector<vector<int>> test_case_3{{0, 0}};
    EXPECT_EQ(s_2.removeStones(test_case_3), 0)

    return EXIT_SUCCESS;
}