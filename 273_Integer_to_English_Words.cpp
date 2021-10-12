#include <string>
#include <sstream>

#include "AlgoUtils.h"

using namespace std;

static const char *singles[10]{"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
static const char *teens[10]{"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen",
                             "Eighteen", "Nineteen"};
static const char *tens[10]{"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
static const char *thousands[4]{"Billion", "Million", "Thousand", ""};

class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }

        stringstream ss;
        long unit = 1000000000;
        for (int i = 0; i <= 3; ++i) {
            int unit_num = num / unit;
            if (unit_num != 0) {
                num -= unit_num * unit;
                unit_to_word(ss, unit_num);
                ss << thousands[i];
                if (i != 3) {
                    ss << " ";
                }
            }
            unit /= 1000;
        }
        auto s = ss.str();
        s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
            return !std::isspace(ch);
        }).base(), s.end());
        return s;
    }

private:
    void unit_to_word(stringstream &ss, int num) {
        int hundred = num / 100;
        num %= 100;
        if (hundred != 0) {
            ss << singles[hundred] << " Hundred ";
        }
        int ten = num / 10;
        if (ten >= 2) {
            ss << tens[ten] << " ";
            num %= 10;
        }

        if (num > 0 && num < 10) {
            ss << singles[num] << " ";
        } else if (num >= 10) {
            ss << teens[num - 10] << " ";
        }
    }
};

int main(int argc, char **argv) {
    Solution s;
    auto ret_1 = string("One Hundred Twenty Three");
    auto ret_2 = string("Twelve Thousand Three Hundred Forty Five");
    auto ret_3 = string("One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven");
    auto ret_4 = string(
            "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One");
    EXPECT_EQ(s.numberToWords(123), ret_1);
    EXPECT_EQ(s.numberToWords(12345), ret_2);
    EXPECT_EQ(s.numberToWords(1234567), ret_3);
    EXPECT_EQ(s.numberToWords(1234567891), ret_4);

    return EXIT_SUCCESS;
}