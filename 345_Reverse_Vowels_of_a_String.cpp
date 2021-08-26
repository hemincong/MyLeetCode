#include <vector>
#include "AlgoUtils.h"

using namespace std;

#define IS_VOWEL(c)  \
    ((c) == 'a' || (c) == 'A' \
    || (c) == 'o' || (c) == 'O' \
    || (c) == 'e' || (c) == 'E' \
    || (c) == 'u' || (c) == 'U' \
    || (c) == 'i' || (c) == 'I')

#define IS_NOT_VOWEL(c) \
    !(IS_VOWEL(c))

class Solution {
public:

    string reverseVowels(string s) {
        if (s.empty()) return "";
        auto n = s.size();
        vector<char> ret_vec(n + 1, '\0');

        int l = 0;
        int r = n - 1;
        while (l <= r) {
            while (IS_NOT_VOWEL(s[l]) && l < r) {
                ret_vec[l] = s[l];
                l++;
            }
            while (IS_NOT_VOWEL(s[r]) && l < r) {
                ret_vec[r] = s[r];
                r--;
            }
            ret_vec[l] = s[r];
            ret_vec[r] = s[l];
            l++;
            r--;
        }

        return {&ret_vec.at(0)};
    }
};

int main(int argc, char **argv) {
    Solution s;
    EXPECT_EQ(s.reverseVowels("a."), "a.")
    EXPECT_EQ(s.reverseVowels(" "), " ")
    EXPECT_EQ(s.reverseVowels("hello"), "holle")
    EXPECT_EQ(s.reverseVowels("leetcode"), "leotcede")
    return EXIT_SUCCESS;
}