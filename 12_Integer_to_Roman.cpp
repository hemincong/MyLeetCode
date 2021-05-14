#include <unordered_map>
#include <sstream>
#include "AlgoUtils.h"

using namespace std;


class Solution {
public:
    string intToRoman(int num) {
        stringstream ss;
        for (const auto &m: num_map) {
            while (num >= m.first) {
                ss << m.second;
                num -= m.first;
            }
        }
        return ss.str();
    }

private:
    const vector<pair<int, const char *>> num_map{
            {1000, "M"},
            {900,  "CM"},
            {500,  "D"},
            {400,  "CD"},
            {100,  "C"},
            {90,   "XC"},
            {50,   "L"},
            {40,   "XL"},
            {10,   "X"},
            {9,    "IX"},
            {5,    "V"},
            {4,    "IV"},
            {1,    "I"}
    };
};

int main(int argc, char **argv) {
    Solution s;
    EXPECT_EQ(s.intToRoman(3), "III");
    EXPECT_EQ(s.intToRoman(4), "IV");
    EXPECT_EQ(s.intToRoman(9), "IX");
    EXPECT_EQ(s.intToRoman(58), "LVIII");
    EXPECT_EQ(s.intToRoman(1994), "MCMXCIV");
    return EXIT_SUCCESS;
}

