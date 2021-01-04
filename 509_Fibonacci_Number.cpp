//
// Created by mincong.he on 2021/1/4.
//

#include "AlgoUtils.h"

class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        long long n_0 = 0;
        long long n_1 = 1;
        long long ret = n_0 + n_1;

        for (int i = 2; i <= n; i++) {
            ret = n_0 + n_1;
            n_0 = n_1;
            n_1 = ret;
        }
        return (int) ret;
    }
};

int main(int argc, char **argv) {
    Solution s;
    EXPECT_EQ(s.fib(2), 1);
    EXPECT_EQ(s.fib(3), 2);
    EXPECT_EQ(s.fib(4), 3);
    EXPECT_EQ(s.fib(30), 832040);
    return EXIT_SUCCESS;
}