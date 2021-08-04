//
// Created by mincong.he on 2021/5/5.
//

#include <vector>
#include "AlgoUtils.h"
#include <climits>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k) {
        auto inf = INT_MAX / 2;
        unordered_map<int, vector<vector<int>>> m;
        for (auto &item: times) {
            m[item[0]].emplace_back(item);
        }
        vector<int> dist(n + 1, inf);
        vector<int> visited(n + 1, 0);
        dist[k] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.emplace(0, k);

        while (!pq.empty()) {
            const auto &v = pq.top();
            //auto start = v[0];
            auto time = v.first;
            auto end = v.second;
            pq.pop();
            if (dist[end] < time) continue; // 到达这个点已经比之前的要慢了，这个点的后续就更慢了，不用压了
            for (auto &e : m[end])  {
                auto next_start = e[0];
                auto next_end = e[1];
                auto next_time = e[2];
                auto d = dist[end] + next_time;
                if (d < dist[next_end]) {
                    dist[next_end] = d;
                    pq.emplace(d, next_end);
                }
            }
        }

        int max_elem = INT_MIN;
        for (int i = 1; i <= n; ++i) {
            if (dist[i] == inf) return -1;
            if (dist[i] > max_elem) max_elem = dist[i];
        }
        return max_elem;
    }
};


int main(int argc, char **argv) {
    Solution s;
    vector<vector<int>> times_1{{2, 1, 1},
                                {2, 3, 1},
                                {3, 4, 1}};
    EXPECT_EQ(s.networkDelayTime(times_1, 4, 2), 2);
    vector<vector<int>> times_2{{1, 2, 1}};
    EXPECT_EQ(s.networkDelayTime(times_2, 2, 1), 1);
    EXPECT_EQ(s.networkDelayTime(times_2, 2, 2), -1);
    vector<vector<int>> times_3{{1, 2, 1},
                                {2, 1, 3}};
    EXPECT_EQ(s.networkDelayTime(times_3, 2, 2), 3);
    vector<vector<int>> times_4{{3, 5, 78},
                                {2, 1, 1},
                                {1, 3, 0},
                                {4, 3, 59},
                                {5, 3, 85},
                                {5, 2, 22},
                                {2, 4, 23},
                                {1, 4, 43},
                                {4, 5, 75},
                                {5, 1, 15},
                                {1, 5, 91},
                                {4, 1, 16},
                                {3, 2, 98},
                                {3, 4, 22},
                                {5, 4, 31},
                                {1, 2, 0},
                                {2, 5, 4},
                                {4, 2, 51},
                                {3, 1, 36},
                                {2, 3, 59}};
    EXPECT_EQ(s.networkDelayTime(times_4, 5, 5), 31);
    vector<vector<int>> times_5{{1, 5, 66},
                                {3, 5, 55},
                                {4, 3, 29},
                                {1, 2, 9},
                                {3, 4, 10},
                                {3, 1, 3},
                                {2, 3, 78},
                                {1, 4, 98},
                                {4, 5, 21},
                                {5, 2, 19},
                                {5, 1, 76},
                                {4, 1, 65},
                                {3, 2, 27},
                                {5, 3, 23},
                                {5, 4, 12},
                                {2, 1, 36},
                                {4, 2, 75},
                                {2, 4, 11},
                                {1, 3, 30},
                                {2, 5, 8}};
    EXPECT_EQ(s.networkDelayTime(times_5, 5, 1), 30);
    vector<vector<int>> times_6{{2, 4, 10},
                                {5, 2, 38},
                                {3, 4, 33},
                                {4, 2, 76},
                                {3, 2, 64},
                                {1, 5, 54},
                                {1, 4, 98},
                                {2, 3, 61},
                                {2, 1, 0},
                                {3, 5, 77},
                                {5, 1, 34},
                                {3, 1, 79},
                                {5, 3, 2},
                                {1, 2, 59},
                                {4, 3, 46},
                                {5, 4, 44},
                                {2, 5, 89},
                                {4, 5, 21},
                                {1, 3, 86},
                                {4, 1, 95}};
    EXPECT_EQ(s.networkDelayTime(times_6, 5, 1), 69);

    return EXIT_SUCCESS;
}