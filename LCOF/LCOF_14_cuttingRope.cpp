#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int cuttingRope(int n) {
        if (n <= 3) return n - 1;
        long ret = 1L;
        int mod = 1e9 + 7;
        while (n > 4) {
            ret = ret * 3 % mod;
            n -= 3;
        }
        return ret * n % mod;
    }
};

int main(int argc, char **argv) {
    Solution s;
    EXPECT_EQ(s.cuttingRope(2), 1);
    EXPECT_EQ(s.cuttingRope(10), 36);
    EXPECT_EQ(s.cuttingRope(120), 953271190);
    EXPECT_EQ(s.cuttingRope(127), 439254203);
    return EXIT_SUCCESS;
}