//
// Created by mincong.he on 2020/7/27.
//

#include <string>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (t.empty() && !s.empty()) return false;

        long s_index = 0;
        long t_index = 0;
        while (s_index < s.length() && t_index < t.length()) {
            if (t[t_index] == s[s_index]) {
                s_index++;
            }

            t_index++;
        }

        return (s_index == s.length());
    }
};

int main(int argc, char** argv) {
    Solution s;
    assert(s.isSubsequence("abc", "ahbgdc"));
    assert(s.isSubsequence("", ""));
    assert(!s.isSubsequence("axc", "ahbgdc"));
    return EXIT_SUCCESS;
}