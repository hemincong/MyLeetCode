//
// Created by mincong.he on 2021/2/1.
//

#include "AlgoUtils.h"
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> fairCandySwap(vector<int> &A, vector<int> &B) {
        vector<int> ret(2, 0);
        set<int> s_a;
        long sum_a = 0;
        for (auto n : A) {
            sum_a += n;
            s_a.insert(n);
        }
        set<int> s_b;
        long sum_b = 0;
        for (auto n : B) {
            sum_b += n;
            s_b.insert(n);
        }

        auto delta = (sum_a - sum_b) >> 1;
        for (const auto &item: s_a) {
            auto may_be_b_item = item - delta;
            if (s_b.find(may_be_b_item) != s_b.end()) {
                ret[0] = item;
                ret[1] = may_be_b_item;
                return ret;
            }
        }

        return ret;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> a_0{2};
    vector<int> b_0{2};
    vector<int> ret_0{2, 2};
    assertArray(s.fairCandySwap(a_0, b_0), ret_0);
    vector<int> a_1{1, 1};
    vector<int> b_1{2, 2};
    vector<int> ret_1{1, 2};
    assertArray(s.fairCandySwap(a_1, b_1), ret_1);
    vector<int> a_2{1, 2};
    vector<int> b_2{2, 3};
    vector<int> ret_2{1, 2};
    assertArray(s.fairCandySwap(a_2, b_2), ret_2);
    vector<int> a_3{2};
    vector<int> b_3{1, 3};
    vector<int> ret_3{2, 3};
    assertArray(s.fairCandySwap(a_3, b_3), ret_3);
    vector<int> a_4{1, 2, 5};
    vector<int> b_4{2, 4};
    vector<int> ret_4{5, 4};
    assertArray(s.fairCandySwap(a_4, b_4), ret_4);
    return EXIT_SUCCESS;
}
