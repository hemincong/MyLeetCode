#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    bool validUtf8(vector<int> &data) {
        int byte_to_check = 0;
        for (auto &x: data) {
            // 字头
            if (byte_to_check == 0) {
                if ((x & 0b10000000) == 0b00000000) {
                    byte_to_check = 0;
                } else if ((x & 0b11100000) == 0b11000000) {
                    byte_to_check = 1;
                } else if ((x & 0b11110000) == 0b11100000) {
                    byte_to_check = 2;
                } else if ((x & 0b11111000) == 0b11110000) {
                    byte_to_check = 3;
                } else return false;
                // 字节尾几个数
            } else {
                if ((x & 0b11000000) != 0b10000000) return false;
                byte_to_check--;
            }
        }
        return byte_to_check == 0;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> test_case_4{230, 136, 145};
    EXPECT_TRUE(s.validUtf8(test_case_4));

    vector<int> test_case_3{237};
    EXPECT_FALSE(s.validUtf8(test_case_3));

    vector<int> test_case_5{255};
    EXPECT_FALSE(s.validUtf8(test_case_5));

    vector<int> test_case_1{197, 139, 1};
    EXPECT_TRUE(s.validUtf8(test_case_1));

    vector<int> test_case_2{235, 140, 4};
    EXPECT_FALSE(s.validUtf8(test_case_2));

    return EXIT_SUCCESS;
}