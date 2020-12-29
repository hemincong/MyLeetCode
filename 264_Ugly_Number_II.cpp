//
// Created by mincong.he on 2020/12/29.
//

#include "AlgoUtils.h"
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<uint64_t, vector<uint64_t>, greater<>> minHeap;
        set<uint64_t> visited;
        vector<uint64_t> ret(n + 1, 0);
        static const int f[3] = {2, 3, 5};
        minHeap.push(1);

        for (int i = 1; i <= n; ++i) {
            auto top = minHeap.top();
            for (int j : f) {
                auto r = top * j;
                if (visited.count(r) == 0) {
                    visited.insert(r);
                    minHeap.push(r);
                }
            }
            ret[i] = minHeap.top();
            minHeap.pop();
        }

        return ret[n];
    }
};

// 三指针法
class Solution_2 {
public:
    int nthUglyNumber(int n) {
        int dp[3] = {0, 0, 0};
        vector<int> ret(n, 1);
        for (int i = 1; i < n; ++i) {
            auto ret_0 = ret[dp[0]] * 2;
            auto ret_1 = ret[dp[1]] * 3;
            auto ret_2 = ret[dp[2]] * 5;
            auto min = ret_0 < ret_1 ? ret_0 : ret_1;
            min = min < ret_2 ? min : ret_2;

            if (min == ret_0) {
                dp[0]++;
            }
            if (min == ret_1) {
                dp[1]++;
            }
            if (min == ret_2) {
                dp[2]++;
            }
            ret[i] = min;
        }

        return ret[n - 1];
    }
};

int main(int argc, char **argv) {
    Solution s;
    Solution_2 s_2;

    EXPECT_EQ(s.nthUglyNumber(10), 12);
    EXPECT_EQ(s.nthUglyNumber(11), 15);
    EXPECT_EQ(s.nthUglyNumber(1689), 2109375000);
    EXPECT_EQ(s_2.nthUglyNumber(10), 12);
    EXPECT_EQ(s_2.nthUglyNumber(11), 15);
    EXPECT_EQ(s_2.nthUglyNumber(1689), 2109375000);
    return EXIT_SUCCESS;
}