//
// Created by mincong.he on 2022/2/8.
//

#include <string>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        vector<char> ans_vec;
        vector<pair<int, char>> arr{
                {a, 'a'},
                {b, 'b'},
                {c, 'c'}
        };
        while (true) {
            std::sort(arr.begin(), arr.end(), [](const auto &p1, const auto &p2) {
                return p1.first > p2.first;
            });

            bool has_next = false;
            for (auto &[freq, ch]: arr) {
                int m = ans_vec.size();
                if (freq <= 0) break;
                if (m >= 2 && ans_vec[m - 2] == ch && ans_vec[m - 1] == ch) {
                    continue;
                }
                has_next = true;
                ans_vec.push_back(ch);
                freq--;
                break;
            }
            if (!has_next) {
                break;
            }
        }
        if (ans_vec.empty()) return "";
        ans_vec.push_back('\0');
        return {ans_vec.data()};
    }
};

int main(int argc, char **argv) {
    Solution s;
    EXPECT_EQ(s.longestDiverseString(1, 1, 7), "ccaccbcc");
    EXPECT_EQ(s.longestDiverseString(7, 1, 0), "aabaa");
    return EXIT_SUCCESS;
}