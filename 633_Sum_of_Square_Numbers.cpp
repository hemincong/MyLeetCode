//
// Created by mincong.he on 2021/4/28.
//

#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        int high = sqrt(c);
        int low = 0;
        while (low < high) {
            long long tmp = (long long)low * low + (long long)high * high;
            if (tmp > c) high--;
            else if (tmp < c) low++;
            else break;
        }
        return (long long)low * low + (long long)high * high == c;
    }
};

int main(int argc, char **argv) {
    Solution s;
    EXPECT_TRUE(s.judgeSquareSum(5))
    EXPECT_FALSE(s.judgeSquareSum(3))
    EXPECT_TRUE(s.judgeSquareSum(4))
    EXPECT_TRUE(s.judgeSquareSum(2))
    EXPECT_TRUE(s.judgeSquareSum(1))
    EXPECT_TRUE(s.judgeSquareSum(100000))
    EXPECT_TRUE(s.judgeSquareSum(1000000000))
    EXPECT_FALSE(s.judgeSquareSum(2147482647))
    return EXIT_SUCCESS;
}