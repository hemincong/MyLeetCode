//
// Created by mincong.he on 2022/3/2.
//

#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    string nearestPalindromic(string n) {
        vector<char> temp;
        vector<char> ret;
        auto len = n.size();
        auto num = stol(n);
        // 10000
        if (num < 10 || num == pow(10, len - 1)) {
            // 9999
            return to_string(num - 1);
            // 10001
        } else if (num == pow(10, len - 1) + 1) {
            // 9999
            return to_string(num - 2);
            // 9999
        } else if (num == pow(10, len) - 1) {
            // 10001
            return to_string(num + 2);
        }

        int half = (len + 1) / 2;
        ret = vector<char>(n.data(), n.data() + len);
        ret.push_back('\0');
        for (int i = 0; i < half; ++i) {
            ret[len - i - 1] = ret[i];
        }

        long min_abs = INT_MAX;
        long ans_delta = 0;
        for (auto delta: {-1, 0, +1}) {
            temp = ret;
            temp[half - 1] += delta;
            if ((len & 1) == 0) {
                temp[half] += delta;
            }
            auto curr_num = atol(&temp.at(0));
            //计算差
            long curr_abs = abs(curr_num - num);
            //最最近（差最小）的回文数
            if (curr_num != num && curr_abs < min_abs) {
                min_abs = curr_abs;
                ans_delta = delta;
            }
        }
        ret[half - 1] += ans_delta;
        if ((len & 1) == 0) {
            ret[half] += ans_delta;
        }
        return {ret.data()};
    }
};

int main(int argc, char **argv) {
    Solution s;
    EXPECT_EQ(s.nearestPalindromic("9999"), "10001");
    EXPECT_EQ(s.nearestPalindromic("10001"), "9999");
    EXPECT_EQ(s.nearestPalindromic("10000"), "9999");
    EXPECT_EQ(s.nearestPalindromic("99"), "101");
    EXPECT_EQ(s.nearestPalindromic("88"), "77");
    EXPECT_EQ(s.nearestPalindromic("123"), "121");
    EXPECT_EQ(s.nearestPalindromic("1"), "0");
    return EXIT_SUCCESS;
}