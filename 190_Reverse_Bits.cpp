//
// Created by mincong.he on 2021/3/29.
//


#include <cstdint>
#include <cstdlib>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret = 0;
        for (int i = 0; i < 32; ++i) {
            ret <<= 1;
            ret |= (n & 1);
            n >>= 1;
        }

        return ret;
    }
};

int main(int argc, char **argv) {

    Solution s;
    EXPECT_EQ(s.reverseBits(4294967293), 3221225471);
    EXPECT_EQ(s.reverseBits(43261596), 964176192);
    EXPECT_EQ(s.reverseBits(4294967293), 3221225471);
    return EXIT_SUCCESS;
}