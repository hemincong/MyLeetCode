#include <string>
#include <iostream>

#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        auto len = s.length();
        if (len <= 1) return s;

        string ret;
        int longest = 0;

        for (int i = 0; i < len; ++i) {
            auto j = 0;
            while (i - j >= 0 && i + j < len && s[i - j] == s[i + j]) {
                if (longest < 2 * j + 1) {
                    longest = 2 * j + 1;
                    ret = s.substr(i - j, longest);
                }
                j++;
            }

            j = 0;
            while (i - j >= 0 && i + 1 + j < len && s[i - j] == s[i + 1 + j]) {
                if (longest < 2 * (j + 1)) {
                    longest = 2 * (j + 1);
                    ret = s.substr(i - j, longest);
                }
                j++;
            }
        }
        return ret;
    }
};

int main(int argc, char **argv) {
    Solution s;
    EXPECT_EQ(s.longestPalindrome("babad"), "bab");
    EXPECT_EQ(s.longestPalindrome("cbbd"), "bb");
    EXPECT_EQ(s.longestPalindrome("a"), "a");
    EXPECT_EQ(s.longestPalindrome("ac"), "a");
    EXPECT_EQ(s.longestPalindrome("bb"), "bb");
    return EXIT_SUCCESS;
}