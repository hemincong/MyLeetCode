#include <vector>
#include <set>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings) {
        auto cmp = [](const pair<int, int> &b1, pair<int, int> &b2) {
            return b1.second < b2.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);
        vector<vector<int>> ret;
        vector<int> boundaries;

        for (auto &b : buildings) {
            boundaries.emplace_back(b[0]);
            boundaries.emplace_back(b[1]);
        }
        sort(boundaries.begin(), boundaries.end());

        auto n = buildings.size();
        int index = 0;
        int curr_height = 0;
        for (auto &bound : boundaries) {
            // buildings 按 lefti 非递减排序
            while (index < n && buildings[index][0] <= bound) {
                // 从buildings的找到对应边的高度，压入堆
                q.emplace(buildings[index][1], buildings[index][2]);
                index++;
            }
            // 移除已经跑过的边, 无论是开始还是结
            while (!q.empty() && q.top().first <= bound) {
                q.pop();
            }

            if (q.empty()) {
                curr_height = 0;
            } else {
                curr_height = q.top().second;
            }
            // 与上一个不一样，ret起到了记录的作用
            if (ret.empty() || curr_height != ret.back()[1]) {
                ret.push_back({bound, curr_height});
            }
        }
        return ret;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<vector<int>> buildings_1{{2,  9,  10},
                                    {3,  7,  15},
                                    {5,  12, 12},
                                    {15, 20, 10},
                                    {19, 24, 8}};
    vector<vector<int>> ret_1{{2,  10},
                              {3,  15},
                              {7,  12},
                              {12, 0},
                              {15, 10},
                              {20, 8},
                              {24, 0}};
    auto ret1 = s.getSkyline(buildings_1); // ret_1;

    printMatrix(ret1);


    vector<vector<int>> buildings_2{{0, 2, 3},
                                    {2, 5, 3}};
    vector<vector<int>> ret_2{{0, 3},
                              {5, 0}};
    auto ret2 = s.getSkyline(buildings_2); // ret_1;
    printMatrix(ret2);

    return EXIT_SUCCESS;
}