//
// Created by mincong.he on 2021/2/5.
//

#include "AlgoUtils.h"
#include <string>

using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        auto n = s.size();
        if (n == 0) return 0;
        int total_cost = 0;
        int j = 0;
        int max_len = 0;
        for (int i = 0; i < n; ++i) {
            total_cost += abs(t[i] - s[i]);
            while (j <= i && total_cost > maxCost) {
                total_cost -= abs(t[j] - s[j]);
                j++;
            }
            if (i - j + 1 > max_len) max_len = i - j + 1;
        }
        return max_len;
    }
};

int main(int argc, char **argv) {
    Solution s;
    EXPECT_EQ(s.equalSubstring("abcd", "bcdf", 3), 3)
    EXPECT_EQ(s.equalSubstring("abcd", "cdef", 3), 1)
    EXPECT_EQ(s.equalSubstring("abcd", "cdef", 1), 0)
    EXPECT_EQ(s.equalSubstring("abcd", "acde", 0), 1)
    EXPECT_EQ(s.equalSubstring("a", "a", 3), 1)
    return EXIT_SUCCESS;
}