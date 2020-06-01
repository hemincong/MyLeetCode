//
// Created by mincong.he on 2020/6/1.
//

#include <string>
#include <map>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        if (s.empty()) return 0;

        std::map<char, int> dict;
        for (char c : s) {
            dict[c]++;
        }

        int count = 0;
        bool flag = false;
        for (const auto &p : dict) {
            if (p.second % 2 != 0) {
                flag = true;
            }
            count += (p.second / 2) * 2;
        }
        if (flag) {
            count++;
        }
        return count;
    }
};

int main(int argc, char **argv) {
    Solution solution;
    assert(solution.longestPalindrome("abccccdd") == 7);
    assert(solution.longestPalindrome("") == 0);
}
