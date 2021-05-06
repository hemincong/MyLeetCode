//
// Created by mincong.he on 2021/5/6.
//
#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        auto n = encoded.size();
        vector<int> ret(n + 1, 0);
        ret[0] = first;
        for (int i = 0; i < n; ++i) {
            ret[i + 1] = ret[i] xor encoded[i];
        }
        return ret;
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<int> encodeed_1{1, 2, 3};
    vector<int> ret_1{1, 0, 2, 1};
    vector<int> encodeed_2{6, 2, 7, 3};
    vector<int> ret_2{4, 2, 0, 7, 4};
    assertArray(s.decode(encodeed_1, 1), ret_1);
    assertArray(s.decode(encodeed_2, 4), ret_2);
    return EXIT_SUCCESS;
}