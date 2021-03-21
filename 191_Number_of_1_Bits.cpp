//
// Created by mincong.he on 2021/3/22.
//

#include <cstdint>
#include <cstdlib>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ret = 0;
        while (n) {
            ret += (n & 1);
            n >>= 1;
        }
        return ret;
    }
};

int main(int argc, char **argv) {

    Solution s;
    EXPECT_EQ(s.hammingWeight(00000000000000000000000000001011), 3);
    EXPECT_EQ(s.hammingWeight(00000000000000000000000010000000), 1);
    //EXPECT_EQ(s.hammingWeight(11111111111111111111111111111101), 31);
    return EXIT_SUCCESS;
}