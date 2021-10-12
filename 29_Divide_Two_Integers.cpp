#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0) return 0;
        if (divisor == 1) return dividend;
        if (divisor == -1) {
            if (dividend > INT_MIN) {
                return -dividend;
            }
            return INT_MAX;
        }
        int sign = 1;
        if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) {
            sign = -1;
        }
        long a = abs(dividend);
        long b = abs(divisor);
        auto ret = div(a, b);
        if (sign > 0) {
            if (ret > INT_MAX) {
                return INT_MAX;
            }
            return ret;
        }
        return -ret;
    }

private:
    long div(long a, long b) {
        if (a < b) return 0;
        long count = 1;
        long tb = b;
        while (tb + tb <= a) {
            count = count + count;
            tb = tb + tb;
        }
        return count + div(a - tb, b);
    }
}

int main(int argc, char **argv) {
    Solution s;
    return EXIT_SUCCESS;
}