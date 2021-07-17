#include "AlgoUtils.h"

class Solution {
public:
    int translateNum(int num) {
        if (num <= 9) return 1;

        auto n = num % 100;

        if (n <= 9 || n > 25) {
            return translateNum(num / 10);
        } else {
            return translateNum(num / 10) + translateNum(num / 100);
        }
    }
};

int main(int argc, char **argv) {
    Solution solution;
    EXPECT_EQ(solution.translateNum(0), 1);
    EXPECT_EQ(solution.translateNum(9), 1);
    EXPECT_EQ(solution.translateNum(10), 2);
    EXPECT_EQ(solution.translateNum(25), 2);
    EXPECT_EQ(solution.translateNum(12258), 5);
    return EXIT_SUCCESS;
}