//
// Created by mincong.he on 2020/12/27.
//

#include "AlgoUtils.h"

#include <vector>

using namespace std;

class Solution {
public:
    int findCircleNum(std::vector<std::vector<int> > &M) {
        auto n = M.size();
        std::vector<int> visited(n, 0);
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (visited[i] == 0) {
                dfs(i, M, visited);
                count++;
            }
        }
        return count;
    }

private:
    void dfs(int index, const vector<vector<int>> &M, vector<int> &visited) {
        visited[index] = 1;
        for (int i = 0; i < M.size(); ++i) {
            if (M[index][i] == 1 && visited[i] == 0) {
                dfs(i, M, visited);
            }
        }
    }
};

class DisjointSet {

public:
    explicit DisjointSet(int n) : _count(n),
                                  _size(vector<int>(n, 1)) {
        for (int i = 0; i < n; ++i) {
            _id.emplace_back(i);
        }
    }

    void union_(int p, int q) {
        int i = find(p);
        int j = find(q);

        if (i == j) return;

        if (_size[i] < _size[j]) {
            _id[i] = j;
            _size[j] += _size[i];
        } else {
            _id[j] = i;
            _size[i] += _size[j];
        }
        _count--;
    }


    int count() const {
        return _count;
    }

private:
    int find(int p) {
        int i = p;
        while (i != _id[i]) {
            _id[i] = _id[_id[i]];
            i = _id[i];
        }
        return i;
    }

    std::vector<int> _id;
    std::vector<int> _size;
    int _count;
};

class Solution_1 {
public:
    int findCircleNum(std::vector<std::vector<int> > &M) {
        DisjointSet disjoint_set(M.size());
        for (int i = 0; i < M.size(); ++i) {
            for (int j = 0; j < M[0].size(); ++j) {
                if (M[i][j]) {
                    disjoint_set.union_(i, j);
                }
            }
        }

        return disjoint_set.count();
    }
};

int main(int argc, char **argv) {
    Solution s;
    Solution_1 s_1;
    vector<vector<int>> test_case_1{{1, 1, 0},
                                    {1, 1, 0},
                                    {0, 0, 1}};
    vector<vector<int>> test_case_2{{1, 1, 0},
                                    {1, 1, 1},
                                    {0, 1, 1}};
    EXPECT_EQ(s.findCircleNum(test_case_1), 2);
    EXPECT_EQ(s.findCircleNum(test_case_2), 1);
    EXPECT_EQ(s_1.findCircleNum(test_case_1), 2);
    EXPECT_EQ(s_1.findCircleNum(test_case_2), 1);

    return EXIT_SUCCESS;
}
