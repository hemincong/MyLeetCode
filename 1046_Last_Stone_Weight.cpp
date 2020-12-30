//
// Created by mincong.he on 2020/12/30.
//

#include "AlgoUtils.h"

#include <vector>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int> &stones) {
        std::priority_queue<int, vector<int>, less<int>> max_heap;

        for (auto s: stones) {
            max_heap.emplace(s);
        }

        while (max_heap.size() > 1) {
            auto top1 = max_heap.top();
            max_heap.pop();
            auto top2 = max_heap.top();
            max_heap.pop();

            if (top1 == top2) continue;
            auto tmp = top1 > top2 ? top1 - top2 : top2 - top1;
            max_heap.emplace(tmp);
        }
        if (max_heap.empty()) return 0;
        else return max_heap.top();
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> test_case_1{2, 7, 4, 1, 8, 1};
    EXPECT_EQ(s.lastStoneWeight(test_case_1), 1);
    return EXIT_SUCCESS;
}