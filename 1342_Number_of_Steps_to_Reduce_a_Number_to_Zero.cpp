//
// Created by mincong.he on 2022/1/31.
//
#include "AlgoUtils.h"

class Solution {
public:
    int numberOfSteps(int num) {
        if (num == 0) return 0;
        int step = 0;
        while (num != 0) {
            if ((num & 1) == 0) {
                // 除一次
                ++step;
            } else {
                // 减去一次，除一次
                step += 2;
            }
            num >>= 1;
        }
        // for 1，只需要减
        return step - 1;
    }
};

int main(int argc, char **argv) {
    Solution s;
    EXPECT_EQ(s.numberOfSteps(14), 6)
    EXPECT_EQ(s.numberOfSteps(8), 4)
    return EXIT_SUCCESS;
}