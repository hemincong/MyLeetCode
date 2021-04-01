//
// Created by mincong.he on 2021/4/1.
//

#include "AlgoUtils.h"

//   20 * 19 / 18 + 17 = 21 + 17
// - 16 * 15 / 14 + 13 = 17 + 13
// - 12 * 11 / 10 +  9 = 13 +  9
// -  8  * 7 /  6 +  5 =  9 +  5
// -  5  * 4 /  3 +  2 =  5 +  2
// -  1

class Solution {
public:
    int clumsy(int N) {
        if (N > 4) {
            auto n_mod = N % 4;
            switch (n_mod) {
                case 0:
                    return N + 1;
                case 1:
                    return N + 2;
                case 2:
                    return N + 2;
                case 3:
                    return N - 1;
            }
        } else {
            switch (N) {
                case 0:
                    return 0;
                case 1:
                    return 1;
                case 2:
                    return 2;
                case 3:
                    return 6;
                case 4:
                    return 7;
            }
        }
        return 0;
    }
};

int main(int argc, char **argv) {
    Solution s;
    EXPECT_EQ(s.clumsy(10), 12)
    EXPECT_EQ(s.clumsy(5), 7)
    EXPECT_EQ(s.clumsy(4), 7)
    EXPECT_EQ(s.clumsy(0), 0)
    return EXIT_SUCCESS;
}