#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
        vector<vector<int>> ret;
        vector<int> path{0};
        dfs(graph, ret, path, 0);
        return ret;
    }

    void dfs(vector<vector<int>> &graph, vector<vector<int>> &ret, vector<int> curr_path, int curr_point) {
        if (curr_point == graph.size() - 1) {
            ret.emplace_back(curr_path);
        }

        for (const auto &p: graph[curr_point]) {
            curr_path.push_back(p);
            dfs(graph, ret, curr_path, p);
            curr_path.pop_back();
        }
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<vector<int>> graph_1{{1, 2},
                                {3},
                                {3},
                                {}};
    vector<vector<int>> ret_1{{0, 1, 3},
                              {0, 2, 3}};
    printMatrix(s.allPathsSourceTarget(graph_1));

    vector<vector<int>> graph_2{{4, 3, 1},
                                {3, 2, 4},
                                {3},
                                {4},
                                {}};
    vector<vector<int>> ret_2{{0, 4},
                              {0, 3, 4},
                              {0, 1, 3, 4},
                              {0, 1, 2, 3, 4},
                              {0, 1, 4}};
    printMatrix(s.allPathsSourceTarget(graph_2));

    vector<vector<int>> graph_3{{1},
                                {}};
    vector<vector<int>> ret_3{{0, 1}};
    printMatrix(s.allPathsSourceTarget(graph_3));

    vector<vector<int>> graph_4{{1, 2, 3},
                                {2},
                                {3},
                                {}};
    vector<vector<int>> ret_4{{0, 1, 2, 3},
                              {0, 2, 3},
                              {0, 3}};
    printMatrix(s.allPathsSourceTarget(graph_4));

    vector<vector<int>> graph_5{{1, 2, 3},
                                {2},
                                {3},
                                {}};
    vector<vector<int>> ret_5{{0, 1, 2, 3},
                              {0, 2, 3},
                              {0, 3}};
    printMatrix(s.allPathsSourceTarget(graph_5));
    return EXIT_SUCCESS;
}