#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool flag;
        while (n != 0) {
            flag = n & 0b1;
            n >>= 1;
            if ((n & 0b1) == flag ) {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char **argv) {
    Solution s;
    EXPECT_TRUE(s.hasAlternatingBits(5))
    EXPECT_FALSE(s.hasAlternatingBits(7))
    EXPECT_FALSE(s.hasAlternatingBits(11))
    return EXIT_SUCCESS;
}