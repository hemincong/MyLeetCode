//
// Created by mincong.he on 2021/1/11.
//

#include <string>
#include <map>

#include "AlgoUtils.h"

using namespace std;

class DisjointSet {
public:
    explicit DisjointSet(int n) {
        for (int i = 0; i < n; ++i) {
            parent.emplace_back(i);
        }
    }

    void union_(int p, int q) {
        parent[find(p)] = find(q);
    }

    int find(int p) {
        if (parent[p] == p) {
            return p;
        }

        parent[p] = find(parent[p]);
        return parent[p];
    }

private:
    std::vector<int> parent;
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>> &pairs) {
        if (pairs.empty()) return s;

        auto n = s.size();
        auto disjointSet = DisjointSet(n);
        for (const auto &p : pairs) {
            disjointSet.union_(p[0], p[1]);
        }

        map<int, priority_queue<char, vector<char>, greater<char>>> charMap;
        for (int i = 0; i < n; ++i) {
            int root = disjointSet.find(i);
            charMap[root].push(s[i]);
        }

        char *buff = (char *) malloc(n + 1);
        memset(buff, '\0', n + 1);
        memcpy(buff, s.c_str(), n);
        for (int i = 0; i < n; ++i) {
            int root = disjointSet.find(i);
            buff[i] = charMap[root].top();
            charMap[root].pop();
        }

        auto ret = string(buff);
        free(buff);
        return ret;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<vector<int>> pairs_1{
            {0, 3},
            {1, 2},
    };
    EXPECT_EQ(s.smallestStringWithSwaps("dcab", pairs_1), "bacd");

    vector<vector<int>> pairs_2{
            {0, 3},
            {1, 2},
            {0, 2},
    };
    EXPECT_EQ(s.smallestStringWithSwaps("dcab", pairs_2), "abcd");

    vector<vector<int>> pairs_3{
            {0, 1},
            {1, 2},
    };
    EXPECT_EQ(s.smallestStringWithSwaps("bca", pairs_3), "abc");

    vector<vector<int>> pairs_4{
            {3, 3},
            {3, 0},
            {5, 1},
            {3, 1},
            {3, 4},
            {3, 5}
    };
    EXPECT_EQ(s.smallestStringWithSwaps("udyyek", pairs_4), "deykuy");
    return EXIT_SUCCESS;
}