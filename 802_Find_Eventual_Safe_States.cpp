#include <vector>
#include "AlgoUtils.h"
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
        auto n = graph.size();
        vector<int> in_deg(n, 0);
        queue<int> safe_point;
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < n; ++i) {
            for (int to : graph[i]) {
                m[to].push_back(i);
            }
            in_deg[i] = graph[i].size();
            if (in_deg[i] == 0) {
                safe_point.push(i);
            }
        }

        while (!safe_point.empty()) {
            auto p = safe_point.front();
            safe_point.pop();
            for (int l : m[p]) {
                in_deg[l]--;
                if (in_deg[l] == 0) {
                    safe_point.push(l);
                }
            }
        }

        vector<int> ret;
        for (int i = 0; i < n; ++i) {
            if (in_deg[i] == 0) ret.push_back(i);
        }
        return ret;
    }
};

int main(int argc, char **argv) {
    vector<vector<int>> graph_1 = {{1, 2},
                                   {2, 3},
                                   {5},
                                   {0},
                                   {5},
                                   {},
                                   {}};
    vector<int> ret_1 = {2, 4, 5, 6};
    vector<vector<int>> graph_2 = {{1, 2, 3, 4},
                                   {1, 2},
                                   {3, 4},
                                   {0, 4},
                                   {}};
    vector<int> ret_2 = {4};
    Solution s;
    assertArray(s.eventualSafeNodes(graph_1), ret_1);
    assertArray(s.eventualSafeNodes(graph_2), ret_2);
    return EXIT_SUCCESS;
}