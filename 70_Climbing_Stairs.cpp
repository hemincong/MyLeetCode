//
// Created by mincong.he on 2020/12/8.
//

#include "AlgoUtils.h"
#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;

        return climbStairs(n - 1) + climbStairs(n - 2);
    }
};

class Solution_2 {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;

        int step_1 = 1;
        int step_2 = 2;
        int step = 0;
        for (int i = 2; i < n; i++) {
            step = step_1 + step_2;
            step_1 = step_2;
            step_2 = step;
        }

        return step;
    }
};

class Solution_3 {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;

        vector<int> ret;
        ret.resize(n);

        ret.at(0) = 1;
        ret.at(1) = 2;
        for (int i = 2; i < n; i++) {
            ret.at(i) = ret.at(i - 1) + ret.at(i - 2);
        }

        return ret.at(n - 1);
    }
};

int main(int argc, char **argv) {
    Solution s;
    Solution_2 s_2;
    Solution_3 s_3;
    EXPECT_EQ(s_3.climbStairs(1), 1);
    EXPECT_EQ(s_3.climbStairs(2), 2);
    EXPECT_EQ(s_3.climbStairs(3), 3);
    EXPECT_EQ(s_3.climbStairs(20), 10946);
    EXPECT_EQ(s_3.climbStairs(45), 1836311903);
    EXPECT_EQ(s_2.climbStairs(1), 1);
    EXPECT_EQ(s_2.climbStairs(2), 2);
    EXPECT_EQ(s_2.climbStairs(3), 3);
    EXPECT_EQ(s_2.climbStairs(20), 10946);
    EXPECT_EQ(s_2.climbStairs(45), 1836311903);
    EXPECT_EQ(s.climbStairs(1), 1);
    EXPECT_EQ(s.climbStairs(2), 2);
    EXPECT_EQ(s.climbStairs(3), 3);
    EXPECT_EQ(s.climbStairs(20), 10946);
    EXPECT_EQ(s.climbStairs(45), 1836311903);
    return EXIT_SUCCESS;
}