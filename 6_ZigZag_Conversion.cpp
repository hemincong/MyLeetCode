//
// Created by mincong.he on 2021/1/7.
//
#include "AlgoUtils.h"
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (s.size() <= 1 || numRows == 1) return s;
        auto n = s.size();
        vector<char> ret;
        auto part = (n / numRows + 1);
        auto col = part * (numRows - 1);
        vector<vector<char>> tmp(numRows, vector<char>(col, ' '));
        auto s_i = 0;
        for (int i = 0; i < part; ++i) {
            auto c = i * (numRows - 1);
            for (int j = 0; j < numRows; ++j) {
                if (s_i >= n) break;
                tmp[j][c] = s[s_i++];
            }

            for (int j = 1; j < numRows - 1; ++j) {
                if (s_i >= n) break;
                tmp[numRows - j - 1][c + j] = s[s_i++];
            }
        }

        //printMatrix(tmp);
        for (const auto &r : tmp) {
            for (const auto &c : r) {
                if (c != ' ' && c != '\0') {
                    ret.emplace_back(c);
                }
            }
        }

        ret.emplace_back('\0');
        return string(&ret.at(0));
    }
};

int main(int argc, char **argv) {
    Solution s;
    EXPECT_EQ(s.convert("AB", 1), "AB");
    EXPECT_EQ(s.convert("PAYPALISHIRING", 3), "PAHNAPLSIIGYIR");
    EXPECT_EQ(s.convert("PAYPALISHIRING", 4), "PINALSIGYAHRPI");
    EXPECT_EQ(s.convert("A", 1), "A");
    return EXIT_SUCCESS;
}