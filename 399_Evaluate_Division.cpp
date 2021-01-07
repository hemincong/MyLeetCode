//
// Created by mincong.he on 2021/1/6.
//
#include "AlgoUtils.h"
#include <vector>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>> &equations,
                                vector<double> &values,
                                vector<vector<string>> &queries) {
        vector<double> ret;
        if (equations.empty()) return ret;
        map<string, map<string, double>> graph;
        for (int n = 0; n < equations.size(); ++n) {
            auto w1 = equations[n][0];
            auto w2 = equations[n][1];
            auto v1 = values[n];
            auto v2 = 1 / values[n];

            graph[w1][w2] = v1;
            graph[w1][w1] = 1.00;
            graph[w2][w1] = v2;
            graph[w2][w2] = 1.00;
        }

        for (const auto &q : queries) {
            const auto d1 = q[0];
            const auto d2 = q[1];
            vector<double> d_path;
            set<string> visited;
            dfs(graph, vector<double>(), d_path, visited, d1, d2);
            if (d_path.empty()) {
                ret.emplace_back(-1.00);
            } else {
                double sum = 1.00;
                for (auto d : d_path) {
                    sum *= d;
                }
                ret.emplace_back(sum);
            }
        }
        return ret;
    }

private:
    bool dfs(const map<string, map<string, double>> &graph,
             vector<double> path,
             vector<double> &ret,
             set<string> visited,
             const string &d1, const string &d2) {
        if (graph.find(d1) == graph.end()) {
            return false;
        }
        if (graph.find(d2) == graph.end()) {
            return false;
        }

        auto values = graph.find(d1)->second;
        auto next = values.find(d2);
        // 找到d2
        if (next != values.end()) {
            path.emplace_back(next->second);
            ret = path;
            return true;
        }

        // 没有找到d2
        for (auto const &k : values) {
            if (visited.find(k.first) == visited.end()) {
                path.emplace_back(k.second);
                visited.insert(d1);
                auto dfs_ret = dfs(graph, path, ret, visited, k.first, d2);
                if (!dfs_ret) { path.pop_back(); }
                else return true;
            }
        }
        return false;
    };
};

int main(int argc, char **argv) {
    Solution s;
    vector<vector<string>> equations_1{{"a", "b"},
                                       {"b", "c"}};
    vector<double> value_1{2.0, 3.0};
    vector<vector<string>> queries_1{{"a", "c"},
                                     {"b", "a"},
                                     {"a", "e"},
                                     {"a", "a"},
                                     {"x", "x"}};
    printArray(s.calcEquation(equations_1, value_1, queries_1)); // {6.00000,0.50000,-1.00000,1.00000,-1.00000}
    std::cout << std::endl;

    vector<vector<string>> equations_2{{"a",  "b"},
                                       {"b",  "c"},
                                       {"bc", "cd"}};
    vector<double> value_2{1.5, 2.5, 5.0};
    vector<vector<string>> queries_2{{"a",  "c"},
                                     {"c",  "b"},
                                     {"bc", "cd"},
                                     {"cd", "bc"}};
    printArray(s.calcEquation(equations_2, value_2, queries_2)); // {3.75000,0.40000,5.00000,0.20000}
    std::cout << std::endl;

    vector<vector<string>> equations_3{{"a", "b"}};
    vector<double> value_3{0.5};
    vector<vector<string>> queries_3{{"a", "b"},
                                     {"b", "a"},
                                     {"a", "c"},
                                     {"x", "y"}};
    printArray(s.calcEquation(equations_3, value_3, queries_3)); // {0.50000,2.00000,-1.00000,-1.00000}
    std::cout << std::endl;

    vector<vector<string>> equations_4{{"a", "e"},
                                       {"b", "e"}};
    vector<double> value_4{4.0, 3.0};
    vector<vector<string>> queries_4{{"a", "b"},
                                     {"e", "e"},
                                     {"x", "x"}};
    printArray(s.calcEquation(equations_4, value_4, queries_4)); // {1.33333,1.0,-1.0}
    std::cout << std::endl;

    vector<vector<string>> equations_5{{"x1", "x2"},
                                       {"x2", "x3"},
                                       {"x3", "x4"},
                                       {"x4", "x5"}};
    vector<double> value_5{3.0, 4.0, 5.0, 6.0};
    vector<vector<string>> queries_5{{"x1", "x5"},
                                     {"x5", "x2"},
                                     {"x2", "x4"},
                                     {"x2", "x2"},
                                     {"x2", "x9"},
                                     {"x9", "x9"}};
    printArray(s.calcEquation(equations_5, value_5, queries_5)); // {360.0,0.00833,20.0,1.0,-1.0,-1.0}
    std::cout << std::endl;

    return EXIT_SUCCESS;
}