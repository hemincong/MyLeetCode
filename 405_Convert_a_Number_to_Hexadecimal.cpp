#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        const char hex[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
        vector<char> buff;
        while (num && buff.size() < 8) {
            buff.push_back(hex[num & 0x0f]);
            num >>= 4;
        }
        std::reverse(buff.begin(), buff.end());
        buff.push_back('\0');
        return string(&buff.at(0));
    }
};

int main(int argc, char **argv) {
    Solution s;
    EXPECT_EQ(s.toHex(26), "1a")
    EXPECT_EQ(s.toHex(-1), "ffffffff")
    return EXIT_SUCCESS;
}