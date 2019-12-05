//
// Created by mincong.he on 2019/12/3.
//

#include <vector>
#include <queue>

using namespace std;

struct GraphNode {
    int label;
    std::vector<GraphNode *> neighbors;

    GraphNode(int x) : label(x) {};
};

class Solution2 {
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        std::vector<GraphNode *> graph;
        std::vector<int> degree(numCourses, 0);
        std::queue<GraphNode *> Q;

        graph.reserve(numCourses);
        for (int i = 0; i < numCourses; ++i) {
            graph.emplace_back(new GraphNode(i));
        }

        for (auto i : prerequisites) {
            graph[i.at(1)]->neighbors.emplace_back(graph[i.at(0)]);
            degree[i.at(0)]++;
        }

        for (int i = 0; i < numCourses; ++i) {
            if (degree[i] == 0) {
                Q.push(graph[i]);
            }
        }

        while (!Q.empty()) {
            GraphNode *node = Q.front();
            Q.pop();
            for (auto &neighbor : node->neighbors) {
                degree[neighbor->label]--;
                if (degree[neighbor->label] == 0) {
                    Q.push(neighbor);
                }
            }
        }

        for (auto &i : graph) {
            delete i;
        }

        return all_of(degree.begin(), degree.end(), [](int i) { return i == 0; });
    }
};

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        std::vector<GraphNode *> graph;
        std::vector<int> visit;
        bool ret = true;
        for (int i = 0; i < numCourses; ++i) {
            graph.emplace_back(new GraphNode(i));
            visit.emplace_back(-1);
        }

        for (auto i : prerequisites) {
            graph[i.at(1)]->neighbors.emplace_back(graph[i.at(0)]);
        }

        for (int i = 0; i < graph.size(); ++i) {
            if (visit[i] == -1 && !DFS_graph(graph[i], visit)) {
                ret = false;
                break;
            }
        }

        for (int i = 0; i < numCourses; ++i) {
            delete graph[i];
        }
        return ret;
    }

private:
    bool DFS_graph(GraphNode *node, std::vector<int> &visit) {
        visit[node->label] = 0;
        for (auto &neighbor : node->neighbors) {
            if (visit[neighbor->label] == 0) {
                return false;
            } else if (visit[neighbor->label] == -1) {
                if (!DFS_graph(neighbor, visit)) {
                    return false;
                }
            }
        }
        visit[node->label] = 1;
        return true;
    }
};


int main() {
    std::vector<std::vector<int> > prerequisites;
    prerequisites.emplace_back(std::vector<int>{1, 0});
    prerequisites.emplace_back(std::vector<int>{2, 0});
    prerequisites.emplace_back(std::vector<int>{3, 1});
    prerequisites.emplace_back(std::vector<int>{3, 2});
    Solution2 solve_2;
    auto ret_2 = solve_2.canFinish(4, prerequisites);
    printf("%d\n", ret_2);
    Solution solve;
    auto ret = solve.canFinish(4, prerequisites);
    printf("%d\n", ret);
    assert(ret == ret_2);
    return 0;
}