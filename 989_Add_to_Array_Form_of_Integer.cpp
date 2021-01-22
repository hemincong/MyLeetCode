//
// Created by mincong.he on 2021/1/22.
//
#include "AlgoUtils.h"
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> addToArrayForm(vector<int> &A, int K) {
        vector<int> ret = A;
        std::reverse(ret.begin(), ret.end());
        int i = 0;
        while (K > 0) {
            auto n = K % 10;
            if (i > ret.size() - 1) ret.push_back(0);
            ret[i] += n;

            i++;
            K = K / 10;
        }

        auto s = ret.size();
        for (int j = 0; j < s; ++j) {
            if (ret[j] > 9) {
                ret[j] = ret[j] - 10;
                if (j + 1 > ret.size() - 1) {
                    ret.push_back(0);
                }
                ret[j + 1]++;
            }
        }

        std::reverse(ret.begin(), ret.end());
        return ret;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> A_1{1, 2, 0, 0};
    int K_1 = 34;
    vector<int> ret_1{1, 2, 3, 4};
    EXPECT_TRUE(assertArray(s.addToArrayForm(A_1, K_1), ret_1));

    vector<int> A_2{2, 7, 4};
    int K_2 = 181;
    vector<int> ret_2{4, 5, 5};
    EXPECT_TRUE(assertArray(s.addToArrayForm(A_2, K_2), ret_2));

    vector<int> A_3{2, 1, 5};
    int K_3 = 806;
    vector<int> ret_3{1, 0, 2, 1};
    EXPECT_TRUE(assertArray(s.addToArrayForm(A_3, K_3), ret_3));

    vector<int> A_4{9, 9, 9, 9, 9, 9, 9, 9, 9, 9};
    int K_4 = 1;
    vector<int> ret_4{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    EXPECT_TRUE(assertArray(s.addToArrayForm(A_4, K_4), ret_4));

    vector<int> A_5{0};
    int K_5 = 23;
    vector<int> ret_5{2, 3};
    EXPECT_TRUE(assertArray(s.addToArrayForm(A_5, K_5), ret_5));

    return EXIT_SUCCESS;
}