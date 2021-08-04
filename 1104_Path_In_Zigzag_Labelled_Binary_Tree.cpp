#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> ret;
        while (label) {
            ret.push_back(label);
            label >>= 1;
        }

        reverse(ret.begin(), ret.end());
        auto n = ret.size();
        for (int i = 0; i < n; ++i) {
            if ((n % 2 == 1 && i % 2 == 0) || (n % 2 == 0 && i % 2 == 1)) {
                continue;
            }
            int l = 1 << i;
            auto r = l + l - 1;
            ret[i] = r - ret[i] + l;
        }

        return ret;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> ret_1{1, 3, 4, 14};
    vector<int> ret_2{1, 2, 6, 10, 26};
    assertArray(s.pathInZigZagTree(14), ret_1);
    assertArray(s.pathInZigZagTree(26), ret_2);
    return EXIT_SUCCESS;
}