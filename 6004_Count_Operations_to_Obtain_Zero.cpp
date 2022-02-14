//
// Created by mincong.he on 2022/2/13.
//

#include "AlgoUtils.h"

class Solution {
public:
    int countOperations(int num1, int num2) {
        if (num1 == 0 || num2 == 0) return 0;
        int count = 0;
        while (num1 > 0 && num2 > 0) {
            if (num1 > num2) {
                num1 -= num2;
            } else if (num2 > num1) {
                num2 -= num1;
            } else if (num2 == num1) {
                return count + 1;
            }
            count++;
        }
        return count + 1;
    }
};

int main(int argc, char** argv) {
    Solution s;
    EXPECT_EQ(s.countOperations(2, 3), 3);
    EXPECT_EQ(s.countOperations(10, 10), 1);
    EXPECT_EQ(s.countOperations(0, 0), 0);
    return EXIT_SUCCESS;
}