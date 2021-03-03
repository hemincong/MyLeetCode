//
// Created by mincong.he on 2021/3/3.
//

#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret(num + 1, 0);
        for (int i = 1; i <= num; ++i) {
            if (i % 2 == 1) {
                ret[i] = ret[i - 1] + 1;
            } else {
                ret[i] = ret[i / 2];
            }
        }
        return ret;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> ret_1{0, 1, 1};
    assertArray(s.countBits(2), ret_1);
    vector<int> ret_2{0, 1, 1, 2, 1, 2};
    assertArray(s.countBits(5), ret_2);
    return EXIT_SUCCESS;
}