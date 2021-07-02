//
// Created by mincong.he on 2021/7/3.
//

#include "AlgoUtils.h"


class Solution {
public:
    int tribonacci(int n) {
        long long t0 = 0;
        long long t1 = 1;
        long long t2 = 1;
        if (n == 0) return t0;
        if (n == 1) return t1;
        if (n == 2) return t2;

        long long t = 0;
        for (int i = 3; i <= n; ++i) {
            t = t0 + t1 + t2;

            t0 = t1;
            t1 = t2;
            t2 = t;
        }
        return t;
    }
};

int main(int argc, char **argv) {
    Solution s;
    EXPECT_EQ(s.tribonacci(4), 4);
    EXPECT_EQ(s.tribonacci(25), 1389537);
    return EXIT_SUCCESS;
}