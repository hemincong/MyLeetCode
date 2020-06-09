//
// Created by mincong.he on 2020/6/10.
//

#include "AlgoUtils.h"

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        // XXX: signed int overflow
        unsigned int comp = 0;
        int tmp_x = x;
        while (tmp_x != 0) {
            int temp = tmp_x % 10;
            comp = comp * 10 + temp;
            tmp_x = tmp_x / 10;
        }

        return x == comp;
    }
};

int main(int argc, char **argv) {
    Solution solution;
    EXPECT_EQ(solution.isPalindrome(2147483647), false);
    EXPECT_EQ(solution.isPalindrome(0), true);
    EXPECT_EQ(solution.isPalindrome(-10), false);
    EXPECT_EQ(solution.isPalindrome(1), true);
    EXPECT_EQ(solution.isPalindrome(121), true);
    EXPECT_EQ(solution.isPalindrome(-121), false);
    EXPECT_EQ(solution.isPalindrome(12), false);
    EXPECT_EQ(solution.isPalindrome(10), false);
}