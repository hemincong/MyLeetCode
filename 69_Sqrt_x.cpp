//
// Created by mincong.he on 2020/12/8.
//

#include "AlgoUtils.h"

class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) return x;

        double Xn = x;
        double Xn_1 = (Xn + x / Xn) / 2;
        while (abs(Xn - Xn_1) > 0) {
            Xn = Xn_1;
            Xn_1 = (Xn + x / Xn) / 2;
        }

        return Xn_1 > Xn ? int(Xn) : int(Xn_1);
    }
};

int main(int argc, char **argv) {
    Solution s;
    EXPECT_EQ(s.mySqrt(3), 1)
    EXPECT_EQ(s.mySqrt(4), 2)
    EXPECT_EQ(s.mySqrt(0), 0)
    EXPECT_EQ(s.mySqrt(8), 2)
    EXPECT_EQ(s.mySqrt(2147395599), 46339)
    return EXIT_SUCCESS;
}