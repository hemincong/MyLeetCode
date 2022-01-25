//
// Created by mincong.he on 2022/1/25.
//

#include "AlgoUtils.h"

class Solution {
public:
    int numberOfMatches(int n) {
        int sum = 0;
        while (n > 1) {
            auto temp = n >> 1;
            if ((n & 1) == 0) {
                sum += temp;
            } else {
                sum += temp + 1;
            }
            n >>= 1;
        }
        return sum;
    }
};

class Solution_2 {
public:
    int numberOfMatches(int n) {
        return n - 1;
    }
};

int main(int argc, char **argv) {
    Solution s;

    EXPECT_EQ(s.numberOfMatches(1), 0);
    EXPECT_EQ(s.numberOfMatches(7), 6);
    EXPECT_EQ(s.numberOfMatches(14), 13);
    EXPECT_EQ(s.numberOfMatches(200), 199);
    return EXIT_SUCCESS;
}
