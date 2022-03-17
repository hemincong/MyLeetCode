#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        vector<char> ret;
        string longest_word = *max_element(strs.begin(), strs.end());
        for (int i = 0; i < longest_word.size(); ++i) {
            for (const auto &s: strs) {
                if (s[i] != longest_word[i]) {
                    ret.push_back('\0');
                    return {&ret.at(0)};
                }
            }
            ret.push_back(longest_word[i]);
        }

        ret.push_back('\0');
        return {&ret.at(0)};
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<string> test_case_1{"flower", "flow", "flight"};
    EXPECT_EQ(s.longestCommonPrefix(test_case_1), "fl")
    vector<string> test_case_2{"dog", "racecar", "car"};
    EXPECT_EQ(s.longestCommonPrefix(test_case_2), "")

    return EXIT_SUCCESS;
}