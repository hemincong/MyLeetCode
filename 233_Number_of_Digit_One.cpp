//
// Created by mincong.he on 2020/12/29.
//
#include "AlgoUtils.h"

#include <string>

class Solution {
public:
    int countDigitOne(int n) {
        auto num_str = std::to_string(n);
        auto num_size = num_str.size();

        size_t count = 0;
        for (int i = 1; i <= num_size; i++) {
            // 前部
            int a = n / pow(10, i);
            // 尾巴
            int b = n % size_t(pow(10, i - 1));
            // 当前位固定，则有前面位数那么多的个1
            count += pow(10, i - 1) * a;

            // 当前数字
            auto digit = num_str[num_size - i] - '0';
            if (digit > 1) {
                // 后面全加
                count += pow(10, i - 1);
            } else if (digit == 1) {
                // 加后面,但只有1
                count += b;
                count += 1;
            } // 0就没了
        }
        return count;
    }
};

int main(int argc, char **argv) {
    Solution s;
    EXPECT_EQ(s.countDigitOne(0), 0);
    EXPECT_EQ(s.countDigitOne(13), 6);
    EXPECT_EQ(s.countDigitOne(824883294), 767944060);
    EXPECT_EQ(s.countDigitOne(999999999), 900000000);
    EXPECT_EQ(s.countDigitOne(1410065408), 1737167499);
    EXPECT_EQ(s.countDigitOne(1633388154), 2147483646);
    return EXIT_SUCCESS;
}