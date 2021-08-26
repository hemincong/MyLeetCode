#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int len = 0;
        for (int i = 0, cnt = 1; i < chars.size(); i++, cnt++) {
            if (i + 1 == chars.size() || chars[i] != chars[i + 1]) {
                chars[len++] = chars[i];
                if (cnt > 1) {
                    for (char ch : to_string(cnt)) {
                        chars[len++] = ch;
                    }
                }
                cnt = 0;
            }
        }
        return len;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<char> chars_1{'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    vector<char> ret_1{'a', '2', 'b', '2', 'c', '3'};
    EXPECT_EQ(s.compress(chars_1), 6)
    chars_1.resize(6);
    assertArray(chars_1, ret_1);

    vector<char> chars_2{'a'};
    vector<char> ret_2{'a'};
    EXPECT_EQ(s.compress(chars_2), 1)
    chars_2.resize(1);
    assertArray(chars_2, ret_2);

    vector<char> chars_3{'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};
    vector<char> ret_3{'a', 'b', '1', '2'};
    EXPECT_EQ(s.compress(chars_3), 4)
    chars_3.resize(4);
    assertArray(chars_3, ret_3);

    vector<char> chars_4{'a', 'a', 'a', 'b', 'b', 'a', 'a'};
    vector<char> ret_4{'a', '3', 'b', '2', 'a', '2'};
    EXPECT_EQ(s.compress(chars_4), 6)
    chars_4.resize(6);
    assertArray(chars_4, ret_4);
    return EXIT_SUCCESS;
}