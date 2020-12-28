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

int main(int argc, char **argv) {
    Solution s;
    vector<vector<int>> test_case_1{{1, 1, 0},
                                    {1, 1, 0},
                                    {0, 0, 1}};
    vector<vector<int>> test_case_2{{1, 1, 0},
                                    {1, 1, 1},
                                    {0, 1, 1}};
    EXPECT_EQ(s.findCircleNum(test_case_1), 2);
    EXPECT_EQ(s.findCircleNum(test_case_2), 1);

    return EXIT_SUCCESS;
}
