//
// Created by mincong.he on 2021/4/20.
//

#include <string>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int strStr(string s, string p) {
        int n = s.size(), m = p.size();
        s = std::string(" ") + s;
        p = std::string(" ") + p;
        if (m == 0) return 0;
        auto next = vector<int>(m + 1, 0);
        for (int i = 2, j = 0; i <= m; i++) {
            while (j > 0 && p[i] != p[j + 1]) {
                j = next[j];
            }
            if (p[i] == p[j + 1]) {
                j++;
            }
            next[i] = j;
        }
        for (int i = 1, j = 0; i <= n; i++) {
            while (j > 0 && s[i] != p[j + 1]) {
                j = next[j];
            }
            if (s[i] == p[j + 1]) { j++; }
            if (j == m) {
                return i - m;
            }
        }
        return -1;

    }
};

int main(int argc, char **argv) {
    Solution s;
    EXPECT_EQ(s.strStr("ababcabcacbab", "aaaab"), -1)
    EXPECT_EQ(s.strStr("ababcabcacbab", "abcacb"), 5)
    EXPECT_EQ(s.strStr("ababcabcacbab", "abaabcac"), -1)
    EXPECT_EQ(s.strStr("hello", "ll"), 2)
    EXPECT_EQ(s.strStr("a", "a"), 0)
    EXPECT_EQ(s.strStr("aaaaa", "bba"), -1)
    EXPECT_EQ(s.strStr("", ""), 0)
    return EXIT_SUCCESS;
}