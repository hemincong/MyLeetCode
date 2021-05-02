#include <vector>
#include "AlgoUtils.h"
#include <bits/stdc++.h>

class Solution {
public:
    int reverse(int x) {
        long i = 0;
        while (x != 0) {
            auto t = x % 10;
            i = i*10 + t;
            x /= 10;
        }
        return i > INT_MAX || i < INT_MIN ? (int) 0 : i;
    }
};

int main(int argc, char** argv) {
    Solution s;
    EXPECT_EQ(s.reverse(123), 321)
    EXPECT_EQ(s.reverse(-123), -321)
    EXPECT_EQ(s.reverse(120), 21)
    EXPECT_EQ(s.reverse(0), 0)
    return EXIT_SUCCESS;
}