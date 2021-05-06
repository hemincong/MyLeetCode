//
// Created by mincong.he on 2021/5/6.
//
#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int xorOperation(int n, int start) {
        if (n <= 1) return start;

        auto ret = start;
        for (int i = 1; i < n; i++) {
            ret ^= (start + 2 * i);
        }
        return ret;

    }
};

int main(int argc, char** argv) {
    Solution s;
    EXPECT_EQ(s.xorOperation(5, 0), 8);
    EXPECT_EQ(s.xorOperation(4, 3), 8);
    EXPECT_EQ(s.xorOperation(1, 7), 7);
    EXPECT_EQ(s.xorOperation(10, 5), 2);
    return EXIT_SUCCESS;
}