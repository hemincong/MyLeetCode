//
// Created by mincong.he on 2021/2/2.
//

#include "AlgoUtils.h"
#include <string>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        auto n = s.size();
        if (n <= 1) return n;
        static const int cc_size = 26;
        vector<int> char_count(cc_size, 0);

        int j = 0;
        int max = 0;

        for (int i = 0; i < n; ++i) {
            char_count[s[i] - 'A']++;
            auto max_char_num = INT_MIN;
            for (int w = 0; w < cc_size; ++w) {
                if (char_count[w] > max_char_num) max_char_num = char_count[w];
            }
            while (i - j + 1 - max_char_num > k) {
                char_count[s[j] - 'A']--;
                j++;
            }
            if (i - j + 1 > max) max = i - j + 1;
        }
        return max;
    }
};

int main(int argc, char **argv) {
    Solution s;
    EXPECT_EQ(s.characterReplacement("", 0), 0)
    EXPECT_EQ(s.characterReplacement("ABAB", 2), 4)
    EXPECT_EQ(s.characterReplacement("AABABBA", 1), 4)

    return EXIT_SUCCESS;
}