#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int networkBecomesIdle(vector<vector<int>> &edges, vector<int> &patience) {
        int n = patience.size();
        vector<vector<int>> graph(n, vector<int>());
        vector<int> dist(n, -1);

        for (auto &e: edges) {
            graph[e[0]].emplace_back(e[1]);
            graph[e[1]].emplace_back(e[0]);
        }

        queue<int> q;
        q.push(0);
        dist[0] = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v: graph[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }

        int ans = 0;
        for (int i = 1; i < n; i++) {
            // 变为空闲的时间 = 收到回复信息的时间 + 最近发出的包的到达时间 + 1
            int len = 2 * dist[i];
            int tmp = len + 1;
            if (len >= patience[i]) {
                if (len % patience[i] == 0)
                    tmp += len - patience[i];
                else
                    tmp += len - (len % patience[i]);
            }
            ans = max(ans, tmp);
        }

        return ans;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<vector<int>> edges_1{{0, 1},
                                {1, 2}};
    vector<int> patience_1{0, 2, 1};
    EXPECT_EQ(s.networkBecomesIdle(edges_1, patience_1), 8)
    vector<vector<int>> edges_2{{0, 1},
                                {0, 2},
                                {1, 2}};
    vector<int> patience_2{0, 10, 10};
    EXPECT_EQ(s.networkBecomesIdle(edges_2, patience_2), 3)

    return EXIT_SUCCESS;
}