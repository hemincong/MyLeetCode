//
// Created by mincong.he on 2020/12/30.
//

#include "AlgoUtils.h"
#include <vector>

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        unsigned int n_compare = 1;
        while (n >= n_compare) {
            if (n == n_compare) return true;

            n_compare <<= 1;
        }
        return false;
    }
};

class Solution_2 {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        return (n & (n - 1)) == 0;
    }
};

int main(int argc, char **argv) {
    Solution s;
    Solution_2 s_2;
    EXPECT_FALSE(s.isPowerOfTwo(-16))
    EXPECT_TRUE(s.isPowerOfTwo(1))
    EXPECT_TRUE(s.isPowerOfTwo(16))
    EXPECT_FALSE(s.isPowerOfTwo(3))
    EXPECT_TRUE(s.isPowerOfTwo(4))
    EXPECT_FALSE(s.isPowerOfTwo(5))
    EXPECT_FALSE(s.isPowerOfTwo(6))
    EXPECT_FALSE(s_2.isPowerOfTwo(-16))
    EXPECT_TRUE(s_2.isPowerOfTwo(1))
    EXPECT_TRUE(s_2.isPowerOfTwo(16))
    EXPECT_FALSE(s_2.isPowerOfTwo(3))
    EXPECT_TRUE(s_2.isPowerOfTwo(4))
    EXPECT_FALSE(s_2.isPowerOfTwo(5))
    EXPECT_FALSE(s_2.isPowerOfTwo(6))
    EXPECT_FALSE(s_2.isPowerOfTwo(12))
    return EXIT_SUCCESS;
}