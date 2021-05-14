//
// Created by mincong.he on 2021/5/15.
//

#include <sstream>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        auto i = 0;
        auto len = s.size();
        int ret = 0;
        while (i < len) {
            auto c = s[i];
            switch (c) {
                case 'M':
                    ret += 1000;
                    break;
                case 'D':
                    ret += 500;
                    break;
                case 'L':
                    ret += 50;
                    break;
                case 'V':
                    ret += 5;
                    break;
                case 'C':
                    if (s[i + 1] == 'M') {
                        ret += 900;
                        i++;
                    } else if (s[i + 1] == 'D') {
                        ret += 400;
                        i++;
                    } else {
                        ret += 100; // 'C'
                    }
                    break;
                case 'X':
                    if (s[i + 1] == 'C') {
                        ret += 90;
                        i++;
                    } else if (s[i + 1] == 'L') {
                        ret += 40;
                        i++;
                    } else {
                        ret += 10; // 'X'
                    }
                    break;
                case 'I':
                    if (s[i + 1] == 'V') {
                        ret += 4;
                        i++;
                    } else if (s[i + 1] == 'X') {
                        ret += 9;
                        i++;
                    } else {
                        ret += 1; // 'I'
                    }
                    break;
                default:
                    break;
            }
            i++;
        }
        return ret;
    }
};

int main(int argc, char **argv) {
    Solution s;
    EXPECT_EQ(s.romanToInt("III"), 3);
    EXPECT_EQ(s.romanToInt("IV"), 4);
    EXPECT_EQ(s.romanToInt("IX"), 9);
    EXPECT_EQ(s.romanToInt("LVIII"), 58);
    EXPECT_EQ(s.romanToInt("MCMXCIV"), 1994);
    return EXIT_SUCCESS;
}

