#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        if (s.empty()) return false;
        s.erase(0, s.find_first_not_of(' '));       //prefixing spaces
        s.erase(s.find_last_not_of(' ') + 1);
        bool got_num = false;
        bool got_e_or_E = false;
        bool got_dot = false;
        auto n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == '+' || s[i] == '-') {
                if (i != 0 && s[i - 1] != 'e' && s[i - 1] != 'E') return false;
            } else if (s[i] >= '0' && s[i] <= '9') {
                got_num = true;
            } else if (s[i] == 'e' || s[i] == 'E') {
                if (!got_num || got_e_or_E) return false;
                got_num = false;
                got_e_or_E = true;
            } else if (s[i] == '.') {
                if (got_dot || got_e_or_E) return false;
                got_dot = true;
            } else {
                return false;
            }
        }
        return got_num;
    }
};

int main(int argc, char **argv) {
    Solution s;
    EXPECT_TRUE(s.isNumber("0"));
    EXPECT_FALSE(s.isNumber("e"));
    EXPECT_FALSE(s.isNumber("."));
    EXPECT_TRUE(s.isNumber("      .1 "));
    EXPECT_TRUE(s.isNumber("+100"));
    EXPECT_TRUE(s.isNumber("5e2"));
    EXPECT_TRUE(s.isNumber("-123"));
    EXPECT_TRUE(s.isNumber("3.1416"));
    EXPECT_TRUE(s.isNumber("-1E-16"));
    EXPECT_TRUE(s.isNumber("0123"));
    EXPECT_FALSE(s.isNumber("12e"));
    EXPECT_FALSE(s.isNumber("1a3.14"));
    EXPECT_FALSE(s.isNumber("1.2.3"));
    EXPECT_FALSE(s.isNumber("+-5"));
    EXPECT_FALSE(s.isNumber("12e+5.4"));
    return EXIT_SUCCESS;
}