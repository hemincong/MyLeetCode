#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        auto n = columnTitle.size();
        auto ret = 0;
        for (int i = 0; i < n; ++i) {
            ret *= 26;
            ret += (columnTitle[i] - 'A' + 1);
        }
        return ret;
    }
};

int main(int argc, char **argv) {
    Solution s;
    EXPECT_EQ(s.titleToNumber("A"), 1)
    EXPECT_EQ(s.titleToNumber("AB"), 28)
    EXPECT_EQ(s.titleToNumber("ZY"), 701)
    return EXIT_SUCCESS;
}