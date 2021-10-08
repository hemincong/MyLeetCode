#include <vector>
#include <unordered_map>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        vector<char> buff;

        // 符号
        if (((long) numerator * (long) denominator) < 0) {
            buff.push_back('-');
        }
        numerator = abs(numerator);
        denominator = abs(denominator);
        // 小数点前
        long integer = numerator / denominator;
        auto integer_str = std::to_string(integer);
        for (char &i: integer_str) {
            buff.push_back(i);
        }

        // 小数点
        long rem = numerator % denominator;
        if (rem == 0) {
            buff.push_back('\0');
            return {&buff.at(0)};
        }

        // 余数
        int index = 0;
        buff.push_back('.');
        unordered_map<long, int> rem_dict;
        vector<int> quos;
        while (rem != 0 && rem_dict.find(rem) == rem_dict.end()) {
            rem_dict[rem] = index++;
            quos.emplace_back(rem * 10 / denominator);
            rem = rem * 10 % denominator;
        }
        // rem == 0 没有循环
        int first_index = rem_dict[rem];
        for (int i = 0; i < quos.size(); ++i) {
            if (rem != 0 && i == first_index) buff.push_back('(');
            buff.push_back((char)('0' + (int)quos[i]));
        }
        if (rem != 0) buff.push_back(')');
        buff.push_back('\0');
        return {&buff.at(0)};
    }
};

int main(int argc, char **argv) {
    Solution s;
    EXPECT_EQ(s.fractionToDecimal(1, 2), "0.5")
    EXPECT_EQ(s.fractionToDecimal(2, 1), "2")
    EXPECT_EQ(s.fractionToDecimal(2, 3), "0.(6)")
    EXPECT_EQ(s.fractionToDecimal(4, 333), "0.(012)")
    EXPECT_EQ(s.fractionToDecimal(1, 5), "0.2")
    EXPECT_EQ(s.fractionToDecimal(-50, 8), "-6.25")
    EXPECT_EQ(s.fractionToDecimal(-1, -2147483648), "0.0000000004656612873077392578125")
    return EXIT_SUCCESS;
}