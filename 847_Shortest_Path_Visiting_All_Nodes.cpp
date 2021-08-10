#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int shortestPathLength(vector<vector<int>> &graph) {
        auto n = graph.size();
        vector<vector<int>> visited(n, vector<int>( 1 << n));
        queue<tuple<int, int, int>> q;

        for (int i = 0; i < n; i++) {
            q.emplace(i, 1 << i, 0);
            visited[i][1 << i] = true;
        }

        while (!q.empty()) {
            auto [cur, mask, dist] = q.front();
            q.pop();

            if (mask == (1 << n) - 1) return dist;

            for (int x : graph[cur]) {
                int nextmask = mask | (1 << x);
                if (!visited[x][nextmask]) {
                    q.emplace(x, nextmask, dist + 1);
                    visited[x][nextmask] = true;
                }
            }
        }
        return 0;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<vector<int>> test_case_1{{1, 2, 3},
                                    {0},
                                    {0},
                                    {0}};
    vector<vector<int>> test_case_2{{1},
                                    {0, 2, 4},
                                    {1, 3, 4},
                                    {2},
                                    {1, 2}};
    EXPECT_EQ(s.shortestPathLength(test_case_1), 4);
    EXPECT_EQ(s.shortestPathLength(test_case_2), 4);
    return EXIT_SUCCESS;
}