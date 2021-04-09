//
// Created by mincong.he on 2021/4/10.
//
#include "AlgoUtils.h"

class Solution {
public:
    bool isUgly(int n) {
        if (n < 1) return false;
        while (n > 1) {
            if (n % 5 == 0) {
                n /= 5;
            } else if (n % 3 == 0) {
                n /= 3;
            } else if (n % 2 == 0) {
                n = n >> 1;
            } else {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char **argv) {
    Solution s;
    EXPECT_TRUE(s.isUgly(6));
    EXPECT_TRUE(s.isUgly(8));
    EXPECT_FALSE(s.isUgly(14));
    EXPECT_TRUE(s.isUgly(1));
    EXPECT_FALSE(s.isUgly(-2147483648));
    return EXIT_SUCCESS;
}