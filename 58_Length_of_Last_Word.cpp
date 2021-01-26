//
// Created by mincong.he on 2021/1/26.
//

#include "AlgoUtils.h"
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        auto n = s.size();
        if (n == 0) return 0;

        auto i = n - 1;
        while (i > 0 && s[i] == ' ') {
            i--;
        }

        auto l = 0;
        while (i > 0 && s[i] != ' ') {
            i--;
            l++;
        }
        if (i == 0 && s[0] != ' ') l++;

        return l;
    }
};

int main(int argc, char **argv) {
    Solution s;
    EXPECT_EQ(s.lengthOfLastWord("abc"), 3)
    EXPECT_EQ(s.lengthOfLastWord("a"), 1)
    EXPECT_EQ(s.lengthOfLastWord("Hello World"), 5)
    EXPECT_EQ(s.lengthOfLastWord(" "), 0)
    EXPECT_EQ(s.lengthOfLastWord("Hello World    "), 5)
    return EXIT_SUCCESS;
}