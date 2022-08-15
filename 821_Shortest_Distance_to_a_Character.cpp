#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int c_pos = -1;
        vector<int> ret(s.size(), 0);
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == c) c_pos = i;
            if (c_pos == -1) ret[i] = -1;
            if (c_pos != -1) ret[i] = i - c_pos;
        }

        c_pos = -1;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == c) c_pos = i;
            if (ret[i] == -1) {
                ret[i] = c_pos - i;
            } else if (c_pos != -1) {
                ret[i] = min(ret[i], c_pos - i);
            }
        }
        return ret;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> ret_1{3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0};
    assertArray(s.shortestToChar("loveleetcode", 'e'), ret_1);

    vector<int> ret_2{3, 2, 1, 0};
    assertArray(s.shortestToChar("aaab", 'b'), ret_2);

    return EXIT_SUCCESS;
}