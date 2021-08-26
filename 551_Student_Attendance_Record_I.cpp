#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    bool checkRecord(string s) {
        auto n = s.size();
        auto L_count = 0;
        auto A_count = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'A') {
                A_count++;
                if (A_count >= 2) return false;
            }
            if (s[i] == 'L') {
                L_count++;
                if (L_count >= 3) return false;
            } else {
                L_count = 0;
            }
        }
        return true;
    }
};

int main(int argc, char **argv) {
    Solution s;
    EXPECT_TRUE(s.checkRecord("PPALLP"));
    EXPECT_FALSE(s.checkRecord("PPALLL"));
    EXPECT_TRUE(s.checkRecord("PPALL"));
    EXPECT_FALSE(s.checkRecord("PPALLLL"));
    EXPECT_TRUE(s.checkRecord("LALL"));
    return EXIT_SUCCESS;
}