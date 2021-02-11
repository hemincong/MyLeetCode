//
// Created by mincong.he on 2021/2/11.
//
#include "AlgoUtils.h"
#include <string>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        auto s1_len = s1.size();
        if (s1_len <= 0) return true;
        auto s2_len = s2.size();
        if (s2_len <= 0) return false;
        if (s1_len > s2_len) return false;

        vector<int> char_count_1(26, 0);
        vector<int> char_count_2(26, 0);
        for (int i = 0; i < s1_len; ++i) {
            char_count_1[s1[i] - 'a']++;
            char_count_2[s2[i] - 'a']++;
        }

        for (int i = 0; i < s2_len - s1_len; ++i) {
            if (char_count_1 == char_count_2) return true;

            char_count_2[s2[i] - 'a']--;
            char_count_2[s2[i + s1_len] - 'a']++;
        }

        return char_count_1 == char_count_2;
    }
};

int main(int argc, char **argv) {
    Solution s;
    EXPECT_TRUE(s.checkInclusion("ab", "eidbaooo"))
    EXPECT_TRUE(s.checkInclusion("ab", "ab"))
    EXPECT_FALSE(s.checkInclusion("ab", "eidboaoo"))
    return EXIT_SUCCESS;
}