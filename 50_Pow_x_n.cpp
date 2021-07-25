#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        double ret = 1.0;

        for (int i = n; i != 0; i /= 2) {
            if (abs(i) % 2 != 0) {
                ret *= x;
            }
            x *= x;
        }
        return n < 0 ? 1 / ret : ret;

    }
};
int main(int argc, char **argv) {
    Solution s;
    return EXIT_SUCCESS;
}