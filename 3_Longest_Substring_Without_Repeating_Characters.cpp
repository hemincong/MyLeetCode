//
// Created by mincong.he on 2020/6/3.
//
#include <map>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        if (s.size() == 1) return 1;

        int left_index = 0;
        int right_index = 0;
        int longest = 0;
        map<char, size_t> curr_char_count;

        while (right_index < s.size()) {
            char r_char;
            do {
                r_char = s[right_index];
                curr_char_count[r_char]++;
                if (right_index - left_index > longest && curr_char_count[r_char] == 1) {
                    longest = right_index - left_index;
                }
                right_index++;
            } while (right_index < s.size() && curr_char_count[r_char] < 1);
            while (curr_char_count[r_char] > 1 && left_index < right_index) {
                auto l_char = s[left_index];
                curr_char_count[l_char]--;
                left_index++;
            }
        }
        return longest + 1;
    }
};

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(Test, test_1) {
    Solution solution;
    EXPECT_EQ(solution.lengthOfLongestSubstring("bbbbb"), 1);
    EXPECT_EQ(solution.lengthOfLongestSubstring("abcabcbb"), 3);
    EXPECT_EQ(solution.lengthOfLongestSubstring("dvdf"), 3);
    EXPECT_EQ(solution.lengthOfLongestSubstring(" "), 1);
    EXPECT_EQ(solution.lengthOfLongestSubstring(""), 0);
    EXPECT_EQ(solution.lengthOfLongestSubstring("au"), 2);
    EXPECT_EQ(solution.lengthOfLongestSubstring("pwwkew"), 3);
}