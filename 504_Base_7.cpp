#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";
        vector<char> ret_vec;

        int num_mod = 0;
        auto num_x = abs(num);
        while (num_x != 0) {
            num_mod = num_x % 7;
            ret_vec.push_back('0' + num_mod);
            num_x /= 7;
        }

        if (num < 0) { ret_vec.push_back('-'); };
        reverse(ret_vec.begin(), ret_vec.end());
        ret_vec.push_back('\0');
        return {ret_vec.data()};
    }
};

int main(int argc, char **argv) {
    Solution s;
    EXPECT_EQ(s.convertToBase7(101), "203");
    EXPECT_EQ(s.convertToBase7(100), "202");
    EXPECT_EQ(s.convertToBase7(-7), "-10");
    EXPECT_EQ(s.convertToBase7(0), "0");
    EXPECT_EQ(s.convertToBase7(7), "10");
    EXPECT_EQ(s.convertToBase7(6), "6");
    EXPECT_EQ(s.convertToBase7(-1), "-1");
    return EXIT_SUCCESS;
}