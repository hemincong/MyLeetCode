//
// Created by mincong.he on 2021/5/6.
//
#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    vector<int> decode(vector<int> &encoded) {
        auto n = encoded.size();
        vector<int> perm(n + 1);
        // 因为给你一个整数数组 perm ，它是前 n 个正整数的排列，且 n 是个 奇数 。
        // 然后然后就求整个数列的异或，无关顺序，就是要全部异或一遍
        int xor_perm = 0;
        for (int i = 1; i <= n + 1; i++) {
            xor_perm ^= i;
        }
        // 然后因为encode = A xor B, B xor C, 则，从1开始，xor全部，就差初始值A, 总数是奇数
        int xor_encode = 0;
        for (int i = 1; i < n; i += 2) {
            xor_encode ^= encoded[i];
        }
        // 让A放回去，
        perm[0] = xor_encode ^ xor_perm;
        for (int i = 1; i <= n; i++) {
            perm[i] = perm[i - 1] ^ encoded[i - 1];
        }
        return perm;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> encodeed_1{3, 1};
    vector<int> ret_1{1, 2, 3};
    vector<int> encodeed_2{6, 5, 4, 6};
    vector<int> ret_2{2, 4, 1, 5, 3};
    assertArray(s.decode(encodeed_1), ret_1);
    assertArray(s.decode(encodeed_2), ret_2);
    return EXIT_SUCCESS;
}